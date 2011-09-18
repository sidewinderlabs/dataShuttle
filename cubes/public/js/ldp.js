LDP = function() {};
LDP.Service = function() {};

(function($) {

	/**
	 * Service constructor
	 */
	LDP.Service = function(config) {
		this.url = config.url;
		this.rows = config.rows || 10;
		this.dimensionHandlers = {};
		this.cut = {};
	};

	/**
	 * Set handler for dimensions
	 */
	LDP.Service.prototype.addDimension = function(dimension, handler) {
		this.dimensionHandlers[dimension] = handler;
		this.dimensionHandlers[dimension].service = this;
	};

	/**
	 * Page setup - fetch all models
	 */
	LDP.Service.prototype.run = function() {
		this.sendRequest('model', 'model');
	};

	/**
	 * Re-fetch all dimensions using the current cut
	 */
	LDP.Service.prototype.update = function() {

		var values = [];
		for(var dimension in this.cut) {
			values.push(dimension + ':' + this.cut[dimension]);
		}

		var cut = values.join('|');

		// Get values for each dimension
		for (var cube in this.model.cubes) {
			for (var i = 0; i < this.model.cubes[cube].dimensions.length; i++) {

				var dimensionName = this.model.cubes[cube].dimensions[i];
				var dimensionData = this.model.dimensions[dimensionName].levels[dimensionName];

				var requestVars = {};
				requestVars.cut = cut;

				if (!(dimensionName in this.cut)) {
					requestVars.drilldown = dimensionName;
				}

				this.sendRequest(
					'dimension',
					'cube/' + this.model.cubes[cube].name + '/aggregate',
					requestVars,
					{
						label: this.model.dimensions[dimensionName].label,
						name: dimensionData.name,
						key: dimensionData.name + '.' + dimensionData.key,
						cube_name: this.model.cubes[cube].name,
						cube_label: this.model.cubes[cube].label
					}
				);

			}
		}

	};
	/**
	 * Add value to filter on
	 */
	LDP.Service.prototype.addCut = function(dimension, value) {
		this.cut[dimension] = value;
	};

	/**
	 * Remove value to filter on
	 */
	LDP.Service.prototype.removeCut = function(dimension) {
		delete this.cut[dimension];
	};

	/**
	 * Send a request to the cubes API
	 */
	LDP.Service.prototype.sendRequest = function(type, action, data, extraData) {
		$.ajax({
			url: this.url + '/' + action,
			type: 'GET',
			data: $.extend(
				{ pagesize: this.rows },
				data
			),
			dataType: 'json',
			context: this,
			success: function(data, textStatus, jqXHR) {
				this.processResponse(type, action, $.extend(extraData, data));
			}
		});
	}

	/**
	 * Process response from cubes API
	 */
	LDP.Service.prototype.processResponse = function(type, action, data) {

		switch(type) {

			case 'model':
				this.model = data;
				this.update();
				break;

			case 'dimension':
				if (!(data.name in this.dimensionHandlers)) {
					console.log('Unknown dimension: ' + data.name);
					return;
				}
				this.dimensionHandlers[data.name].processResponse(data);
				break;

			default:
				console.log('Unknown action: ' + action);
				break;

		}

	};

	/**
	 * Dimension namespace
	 */
	LDP.Dimension = function() {};

	/**
	 * Utiltiy function to format a number for human consumption
	 */
	LDP.Dimension.numFormat = function(num) {
		num += '';
		x = num.split('.');
		x1 = x[0];
		x2 = x.length > 1 ? '.' + x[1] : '';
		var rgx = /(\d+)(\d{3})/;
		while (rgx.test(x1)) {
			x1 = x1.replace(rgx, '$1' + ',' + '$2');
		}
		return x1 + x2;
	};

	/**
	 * List Dimension constructor
	 */
	LDP.Dimension.List = function(config) {
		config = config || {};

		this.service = null;

		this.container = config.container || '#dimensions';
		this.container = $(this.container);

	};

	LDP.Dimension.List.prototype.processResponse = function(dimension) {
		if (dimension.total_cell_count == null) {
			this.single(dimension);
		} else {
			this.multi(dimension);
		}
	};

	LDP.Dimension.List.prototype.single = function(dimension) {

		var service = this.service;

		var removeLink = $('<a href="#">x</a>')
			.click(function() {
				service.removeCut(dimension.name);
				service.update();
				return false;
			});

		var list = $('<ul></ul>').append(
			$('<li></li>')
				.append(dimension.summary[dimension.key] + ' (' + LDP.Dimension.numFormat(dimension.summary.value_sum) + ') ')
				.append(removeLink)
		);

		this.addDimension(dimension.name, dimension.label, list);

	};

	LDP.Dimension.List.prototype.multi = function(dimension) {

		var list = $('<ul></ul>');

		for (var i = 0; i < dimension.drilldown.length; i++) {
			list.append(this.multiItem(dimension, dimension.drilldown[i]));
		}

		this.addDimension(dimension.name, dimension.label, list);

	}

	LDP.Dimension.List.prototype.multiItem = function(dimension, curDimension) {

		var service = this.service;

		var link = $('<a href="#">' + curDimension[dimension.key] + ' (' + LDP.Dimension.numFormat(curDimension.value_sum) + ')</a>')
			.click(function() {
				service.addCut(dimension.name, curDimension[dimension.key]);
				service.update();
				return false;
			});

		return $('<li></li>').append(link);

	};

	LDP.Dimension.List.prototype.addDimension = function(name, label, content) {

		var dimension = $('#dimension_' + name);
		if (dimension.size()) {

			// Replace existing dimension
			dimension
				.next()
					.remove()
				.end()
				.after(content);

		} else {

			// Add new dimension
			this.container
				.append('<h2 id="dimension_' + name + '">' + label + '</h2>')
				.append(content);

		}

	};

	/**
	 * Geo Dimension constructor
	 */
	LDP.Dimension.Geo = function(config) {
		config = config || {};

		this.service = null;

		this.container = config.container || '#geo';

		// Default to grayscale colour range
		this.colourMin = config.colourMin || "#fff";
		this.colourMax = config.colourMax || "#000";

		// Prefix to target GeoJSON features (defaults to dimension's name and an undescore)
		this.featureIdPrefix = config.featureIdPrefix || null;

		// Default to view of UK (assuming longitude and latitude using WGS84 datum)
		this.projection = d3.geo.albers()
			.scale(config.scale || 6000)
			.origin(config.origin || [1, 54]);

		this.path = d3.geo.path()
			.projection(this.projection);

		this.chart = d3.select(this.container)
			.append('svg:svg');

		this.geo = this.chart.append('svg:g')
			.attr('id', config.id || 'geo_chart');

		this.isLoaded = false;

		var handler = this;
		d3.json(config.url || 'geo.json', function(json) {

			handler.geo.selectAll("path")
				.data(json.features)
			.enter().append("svg:path")
				.attr("id", handler.getId)
				.attr("d", handler.path);

			handler.isLoaded = true;

		});

	};

	LDP.Dimension.Geo.prototype.processResponse = function(dimension) {

		// Defer processing if the geo data hasn't loaded yet
		if (!this.isLoaded) {
			var handler = this;
			window.setTimeout(function() { handler.processResponse(dimension); }, 200);
			return;
		}

		// Get colour range for the current set of values
		var colourScale = this.getColourScale(dimension);

		// Get prefix for GeoJSON features IDs' (the suffix is always the dimension value)
		var prefix = (this.featureIdPrefix == null) ? dimension.name + '_' : this.featureIdPrefix;

		// Set each dimension value's area to the appropriate colour
		for (var i = 0; i < dimension.drilldown.length; i++) {

			this.setFeatureValue(
				'#' + prefix + dimension.drilldown[i][dimension.key],
				dimension.drilldown[i].value_sum,
				colourScale
			);

		}

	};

	LDP.Dimension.Geo.prototype.setFeatureValue = function(featureId, value, colourScale) {

		$(featureId)
			.css('fill', colourScale(value))
			.unbind('hover')
			.hover(
				function (e) {

					if (this.tooltip) {
						this.tooltip.html(LDP.Dimension.numFormat(value));
						this.tooltip.show();
						return;
					}

					var offset = $(this).offset();
					this.tooltip = $('<div class="tooltip">' + LDP.Dimension.numFormat(value) + '</div>')
						.css({
							position: 'absolute',
							top: offset.top + "px",
							left: offset.left + "px"
						});

					$('body')
						.append(this.tooltip);

				},
				function (e) {
					if (this.tooltip) {
						this.tooltip.hide();
					}
				}
			);

	};

	LDP.Dimension.Geo.prototype.getColourScale = function(dimension) {

		// Loop through all dimension's values to get minimum and maximum
		var min = dimension.drilldown[0].value_sum;
		var max = dimension.drilldown[0].value_sum;

		for (var i = 0; i < dimension.drilldown.length; i++) {
			var value = dimension.drilldown[i].value_sum;
			if (value > max) {
				max = value;
			}
			if (value < min) {
				min = value;
			}
		}

		// Return a linear scaling function
		return d3.scale.linear()
			.domain([min, max])
			.range([this.colourMin, this.colourMax]);

	};

	LDP.Dimension.Geo.prototype.getId = function(d) {
		return d.id;
	};

})(jQuery);

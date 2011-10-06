var LDP = function() {};

(function($) {

	/**
	 * Utility function to format a number for human consumption
	 */
	LDP.numFormat = function(num) {
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
	 * Service constructor
	 */
	LDP.Service = function(config) {
		this.url = config.url;
		this.rows = config.rows || 10;
		this.stateContainer = $(config.stateContainer || '#state');
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
		this.updateStateInfo();
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
		for (var i = 0; i < this.model.cubes[this.cubeName].dimensions.length; i++) {

			var dimensionName = this.model.cubes[this.cubeName].dimensions[i];
			var dimensionData = this.model.dimensions[dimensionName].levels[dimensionName];

			var requestVars = {};
			requestVars.cut = cut;

			if (!(dimensionName in this.cut)) {
				requestVars.drilldown = dimensionName;
			}

			this.sendRequest(
				'dimension',
				'cube/' + this.cubeName + '/aggregate',
				requestVars,
				{
					label: this.model.dimensions[dimensionName].label,
					name: dimensionData.name,
					key: dimensionData.name + '.' + dimensionData.key
				}
			);

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

				// Save model data
				this.model = data;

				// Always use the first cube model
				for (var cube in this.model.cubes) {
					this.cubeName = cube;
					break;
				}

				// Fetch dimensions
				this.update();

				break;

			case 'dimension':

				this.updateStateInfo(data.summary.value_sum);

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
	 * Update state information base on the current cut
	 */
	LDP.Service.prototype.updateStateInfo = function(total) {

		this.stateContainer.empty();

		if (total != undefined) {
			this.stateContainer
				.append('<h2>Total ' + this.model.cubes[this.cubeName].label + ': ' + LDP.numFormat(total) + '</h2>');
		}

		if (Object.keys(this.cut).length != 0) {

			var table = $('<table></table>');

			for (var dimension in this.cut) {
				$('<tr></tr>')
					.append('<th>' + this.model.dimensions[dimension].label + '</th>')
					.append('<td>' + this.cut[dimension] + '</td>')
					.appendTo(table);

			}

			this.stateContainer
				.append(table);

		}

	};

	/**
	 * Dimension namespace
	 */
	LDP.Dimension = function() {};


	/**
	 * Add/replace a dimension
	 */
	LDP.Dimension.addDimension = function(container, name, label, content) {

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
			container
				.append('<h2 id="dimension_' + name + '">' + label + '</h2>')
				.append(content);

		}

	};

	/**
	 * Dimension tooltips
	 */
	LDP.Dimension.tooltipMouseMove = function(dimension, data) {

		if (!d3.select(this).classed('click')) {
			return;
		}

		if (!this.tooltip) {
			this.tooltip = $('<div class="tooltip"></div>')
				.css('position', 'absolute')
				.appendTo('body');
		}

		// Show dimension measure in tooltip
		values = [
			LDP.numFormat(data.value_sum)
		];

		// Add any additional dimension attributes to tooltip
		for (var i in data) {
			if (i != dimension.key && i.split('.')[0] == dimension.name) {
				values.push(data[i]);
			}
		}

		this.tooltip
			.html(values.join(' <br/>'))
			.css({
				left: (d3.event.pageX - 20) + 'px',
				top: (d3.event.pageY - (values.length * 20) - 5) + 'px'
			})
			.show();

	};

	LDP.Dimension.tooltipMouseOut = function(d, i) {
		if (this.tooltip) {
			this.tooltip.hide();
		}
	};

	LDP.Dimension.tooltipsRemove = function() {
		$('.tooltip').remove();
	}

	/**
	 * List Dimension constructor
	 */
	LDP.Dimension.List = function(config) {
		config = config || {};

		this.service = null;

		this.container = config.container || '#dimensions';
		this.container = $(this.container);
	};

	/**
	 * Process list dimension response
	 */
	LDP.Dimension.List.prototype.processResponse = function(dimension) {
		if (dimension.total_cell_count == null) {
			this.single(dimension);
		} else {
			this.multi(dimension);
		}
	};

	LDP.Dimension.List.prototype.single = function(dimension) {

		var service = this.service;

		var showAll = $('<a href="#" class="showAll">x</a>')
			.click(function() {
				service.removeCut(dimension.name);
				service.update();
				return false;
			});

		var list = $('<ul></ul>').append(
			$('<li></li>')
				.append(this.formatValue(dimension.summary[dimension.key], dimension.summary.value_sum) + ' ')
				.append(showAll)
		);

		LDP.Dimension.addDimension(this.container, dimension.name, dimension.label, list);

	};

	/**
	 * Render list
	 */
	LDP.Dimension.List.prototype.multi = function(dimension) {

		var list = $('<ul></ul>');

		for (var i = 0; i < dimension.drilldown.length; i++) {
			list.append(this.multiItem(dimension, dimension.drilldown[i]));
		}

		LDP.Dimension.addDimension(this.container, dimension.name, dimension.label, list);

	}

	/**
	 * Render item in list
	 */
	LDP.Dimension.List.prototype.multiItem = function(dimension, curDimension) {

		var service = this.service;

		var link = $('<a href="#">' + this.formatValue(curDimension[dimension.key], curDimension.value_sum) + '</a>')
			.click(function() {
				service.addCut(dimension.name, curDimension[dimension.key]);
				service.update();
				return false;
			});

		return $('<li></li>').append(link);

	};

	/**
	 * Utility function to format a dimension value
	 */
	LDP.Dimension.List.prototype.formatValue = function(name, value) {
		return name + ' (' + LDP.numFormat(value) + ')';
	};

	/**
	 * BarChart Dimension constructor
	 */
	LDP.Dimension.BarChart = function(config) {
		config = config || {};

		this.service = null;

		this.container = $(config.container || '#dimensions');

		this.barWidth = config.barWidth || 250;
		this.barHeight = config.barHeight || 20;

		this.textX = config.textX || -3;
		this.textY = config.textY || '.35em';
		this.textAnchor = config.textAnchor || 'end';

		this.scale = config.scale || this.scale;
	};

	/**
	 * Process bar chart dimension response
	 */
	LDP.Dimension.BarChart.prototype.processResponse = function(dimension) {
		if (dimension.total_cell_count == null) {
			this.single(dimension);
		} else {
			this.multi(dimension);
		}
	};

	/**
	 * Display a single bar
	 */
	LDP.Dimension.BarChart.prototype.single = function(dimension) {

		var service = this.service;

		// Create link to remove cut for current dimension and show all values
		var removeLink = $('<a href="#" class="showAll">Show All</a>')
			.click(function() {
				service.removeCut(dimension.name);
				service.update();
				LDP.Dimension.tooltipsRemove();
				return false;
			});

		// Create single line bar chart
		var bar = '<svg class="barChart static" width="' + this.barWidth + '" height="' + this.barHeight + '">';
		bar += '<rect y="0" width="' + this.barWidth + '" height="' + this.barHeight + '"></rect>';
		bar += '<text x="' + this.barWidth + '" y="' + (this.barHeight / 2) + '" dx="' + this.textX + '" dy="' + this.textY + '" text-anchor="' + this.textAnchor + '">';
		bar += dimension.summary[dimension.key] + '</text></svg>';

		// Add content to page
		var content = $('<div></div>')
			.addClass('barContainer')
			.append(bar)
			.append(removeLink);

		LDP.Dimension.addDimension(this.container, dimension.name, dimension.label, content);

	};

	/**
	 * Display a bar chart
	 */
	LDP.Dimension.BarChart.prototype.multi = function(dimension) {

		var handler = this;
		var data = dimension.drilldown.map(function (d) {
			return d.value_sum
		});
		var scale = this.scale(data);

		// Create bar chart
		var chartContainer = $('<div></div>');
		var chart = d3.select(chartContainer.get(0))
			.append('svg:svg')
				.attr('class', 'barChart')
				.attr('width', this.barWidth)
				.attr('height', this.barHeight * data.length);

		// Create bars
		var bars = chart.selectAll('rect')
				.data(data)
			.enter().append('svg:rect')
				.attr('y', function(d, i) { return i * handler.barHeight; })
				.attr('width', scale)
				.attr('height', this.barHeight)
				.classed('click', true)
				.on('click', function(d, i) {
					handler.service.addCut(dimension.name, dimension.drilldown[i][dimension.key]);
					handler.service.update();
					LDP.Dimension.tooltipsRemove();
				})
				.on('mousemove', function(d, i) {
					LDP.Dimension.tooltipMouseMove.apply(this, [dimension, dimension.drilldown[i]]);
				})
				.on('mouseout', LDP.Dimension.tooltipMouseOut);

		// Create bar labels
		chart.selectAll('text')
				.data(data)
			.enter().append('svg:text')
				.attr('x', scale)
				.attr('y', function(d, i) { return (i * handler.barHeight) + (handler.barHeight/2); })
				.attr('dx', this.textX)
				.attr('dy', this.textY)
				.attr('text-anchor', this.textAnchor)
				.text(function (d, i) {
					return dimension.drilldown[i][dimension.key];
				})
				.classed('click', true)
				.on('click', this.delegateEvent)
				.on('mousemove', this.delegateEvent)
				.on('mouseout', this.delegateEvent);

		// Add chart to page
		LDP.Dimension.addDimension(this.container, dimension.name, dimension.label, chartContainer);

	};

	/**
	 * Delegate an event on a bar chart's label to the corresponding bar
	 */
	LDP.Dimension.BarChart.prototype.delegateEvent = function(d, i) {

		var bar = $(this)
			.parent()
			.children('rect')
			.get(i);

		d3.select(bar)
			.on(d3.event.type)
			.apply(bar, [d, i]);

	};

	/**
	 * Default scaling function (linear) for bar lengths
	 */
	LDP.Dimension.BarChart.prototype.scale = function(data) {
		return d3.scale.linear()
			.domain([0, d3.max(data)])
			.range([0, this.barWidth]);
	};

	/**
	 * Geo Dimension constructor
	 */
	LDP.Dimension.Geo = function(config) {
		config = config || {};

		this.service = null;

		// Where to render the map
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

	/**
	 * Process geo dimension response
	 */
	LDP.Dimension.Geo.prototype.processResponse = function(dimension) {

		// Defer processing if the geo data hasn't loaded yet
		if (!this.isLoaded) {
			var handler = this;
			window.setTimeout(function() { handler.processResponse(dimension); }, 200);
			return;
		}

		if (dimension.total_cell_count == null) {
			this.single(dimension);
		} else {
			this.multi(dimension);
		}

	};

	/**
	 * Highlight single geogpahical region
	 */
	LDP.Dimension.Geo.prototype.single = function(dimension) {

		var handler = this;
		var service = this.service;

		// Reset styles
		this.chart.selectAll('path')
			.style('fill', null)
			.classed('click', false);

		// Style the region we're selecting on
		this.setFeatureValue(
			dimension,
			dimension.summary,
			function() { return handler.colourMax; }
		);

		$('<a href="#" class="showAll">Show All</a>')
			.click(function() {
				service.removeCut(dimension.name);
				service.update();
				LDP.Dimension.tooltipsRemove();
				return false;
			})
			.appendTo(this.container);

	};

	/**
	 * Display choropleth
	 */
	LDP.Dimension.Geo.prototype.multi = function(dimension) {

		// Remove show all link
		$(this.container)
			.find('.showAll')
			.remove();

		// Get colour range for the current set of values
		var colourScale = d3.scale.linear()
			.domain([
				d3.min(dimension.drilldown, this.getValue),
				d3.max(dimension.drilldown, this.getValue)
			])
			.range([this.colourMin, this.colourMax])

		// Set each region to the appropriate colour
		for (var i = 0; i < dimension.drilldown.length; i++) {

			this.setFeatureValue(
				dimension,
				dimension.drilldown[i],
				colourScale
			);

		}

	};

	/**
	 * Highlight single geogpahical region in choropleth
	 */
	LDP.Dimension.Geo.prototype.setFeatureValue = function(dimension, data, colourScale) {

		var handler = this;
		var featureId = '#' + ((this.featureIdPrefix == null) ? dimension.name + '_' : this.featureIdPrefix) + data[dimension.key];

		d3.select(featureId)
			.style('fill', colourScale(data.value_sum))
			.classed('click', true)
			.on('click', function(d, i) {

				if (!d3.select(this).classed('click')) {
					return;
				}

				handler.service.addCut(dimension.name, data[dimension.key]);
				handler.service.update();

				LDP.Dimension.tooltipsRemove();

			})
			.on('mousemove', function(d, i) {
				LDP.Dimension.tooltipMouseMove.apply(this, [dimension, data]);
			})
			.on('mouseout', LDP.Dimension.tooltipMouseOut);

	};

	LDP.Dimension.Geo.prototype.getId = function(d) {
		return d.id;
	};

	LDP.Dimension.Geo.prototype.getValue = function(d) {
		return d.value_sum;
	};

})(jQuery);

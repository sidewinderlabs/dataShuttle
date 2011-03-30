// ASSUMPTIONS
// ###########
// ~ incoming data looks like this: [ { value: 42, label: 'answer to the ultimate question' }, ... ]

var barchart = (function() {
	var self = this;

	var data = [];
	var labels = [];
	var highlights = [];
	var highlightedLabels = [];
	var defaultColour = 0;
	var defaultHighlightColour = 1;
	var chart;
	var overview;
	var name;

	self.setOptions = function(options) {
		defaultColour = options.defaultColour || 0;
		defaultHighlightColour = options.defaultHighlightColour || 1;
		name = options.name;
	};

	self.load = function(rawData) {
		for(var i = 0; i < rawData.length; ++i) {
			data.push([i, rawData[i].value]);
			labels.push([i, rawData[i].label]);
			highlightedLabels.push([i, '']);
		}
	};

	self.highlightItem = function(index, colour) {
		highlights[indexify(index)] = colour || defaultHighlightColour;
		highlightedLabels[index] = labels[index];
	};

	var indexify = function(index) {
		return 'i' + index;
	};

		self.unhighlightItem = function(index) {
		delete highlights[indexify(index)];
		highlightedLabels[index] = [index, ''];
	};

	self.draw = function(chartContainer, overviewContainer, detailContainer, topvalue) {
		var upperBound = data.length - 1;
		
		if(chartContainer) {
			drawChart(chartContainer, 0, upperBound, detailContainer, topvalue);
		}
		if(overviewContainer) {
			drawOverview(overviewContainer, 0, upperBound);
		}
		// Uncomment the following if the selection plugin is being used.
		//if(chartContainer && overviewContainer) {
		//	bindChartAndOverview(chartContainer, overviewContainer);
		//}
		addPanControls(chartContainer);
		addZoomControls(chartContainer);
	};

	var drawChart = function(chartContainer, lowerBound, upperBound, detailContainer) {
		var options = getOptions(lowerBound, upperBound);
		var mydata = getData(lowerBound, upperBound);

		chart = $.plot(chartContainer, mydata, options);
		if(detailContainer && options.grid.hoverable === true) {
			bindHoverInfo(chartContainer, detailContainer);
		}
	};

	var getData = function(lowerBound, upperBound) {
		var inRangeHighlights = getInRangeHighlights(lowerBound, upperBound);
		return getAllSeries(lowerBound, upperBound, inRangeHighlights, getNumberOfSeries(lowerBound, upperBound, inRangeHighlights));
	};

	var getInRangeHighlights = function(lowerBound, upperBound) {
		var inRangeHighlights = [], highlight;

		for(highlight in highlights) {
			if(highlights.hasOwnProperty(highlight)) {
				if(unindexify(highlight) >= lowerBound && unindexify(highlight) <= upperBound) {
					inRangeHighlights.push(unindexify(highlight));
				}
			}
		}

		inRangeHighlights.sort(function(a, b) { return a - b; });

		return inRangeHighlights;
	};

	var unindexify = function(index) {
		return parseInt(index.substring(1), 10);
	};

	var getNumberOfSeries = function(lowerBound, upperBound, inRangeHighlights) {
		var numberOfSeries = 2 * inRangeHighlights.length + 1;

		if(inRangeHighlights[0] === lowerBound) {
			--numberOfSeries;
		}

		if(inRangeHighlights[inRangeHighlights.length - 1] === upperBound) {
			--numberOfSeries;
		}
		return numberOfSeries;
	};

	var getAllSeries = function(lowerBound, upperBound, inRangeHighlights, numberOfSeries) {
		var series = [], seriesIndex = lowerBound, label = name;
		for(var i = 0; i < numberOfSeries; ++i) {
			if(seriesIndex === inRangeHighlights[0]) {
				series.push(getHighlightSeries(inRangeHighlights.shift()));
				++seriesIndex;
			} else {
				if(inRangeHighlights.length === 0) {
					series.push(getNormalSeries(seriesIndex, upperBound, label));
					if(label) {
						label = undefined;
					}
				} else {
					series.push(getNormalSeries(seriesIndex, inRangeHighlights[0] - 1, label));
					seriesIndex = inRangeHighlights[0];
					if(label) {
						label = undefined;
					}
				}
			}
		}
		return series;
	};

	var getHighlightSeries = function(index) {
		return getSeries(index, index, highlights[indexify(index)]);
	};

	var getNormalSeries = function(lowerBound, upperBound, label) {
		return getSeries(lowerBound, upperBound, defaultColour, label);
	};

	var getSeries = function(lowerBound, upperBound, colour, label) {
		return {
			data: data.slice(lowerBound, upperBound + 1),
			bars: { show: true },
			color: colour,
			shadowSize: 0,
			label: label
		};
	};

	var getOptions = function() {
		var upperBound = data.length;
		topvalue = topvalue + 10
		return {
			// TODO: Make more (all?) of this stuff configurable
			xaxis: {
				ticks: highlightedLabels,
				zoomRange: [ 0, upperBound * 1.4 ],
				panRange: [ 0, upperBound ]
			},
			yaxis: {
				min: 0,
				max: topvalue,
				zoomRange: [0, topvalue + 1],
				panRange: [0, topvalue + 1]
			},
			selection: { mode: 'x' },
			grid: {
				hoverable: true,
				color: 'rgb(0, 0, 0)',
				backgroundColor: 'rgb(255, 255, 255)',
				tickColor: 'rgb(255, 255, 255)'
			},
			zoom: { interactive: true },
			pan: { interactive: true },
			legend: {
				show: true,
				position: 'ne',
				margin: 20
			}
		};
	};


	var drawOverview = function(overviewContainer, lowerBound, upperBound) {
		// TODO: Get overview options dynamically
		overview = $.plot(overviewContainer, getData(lowerBound, upperBound), {
			xaxis: { ticks: [] },
			yaxis: { ticks: [] },
			selection: { mode: 'x' },
			grid: { show: false },
			legend: { show: false }
		});
	};

	var bindChartAndOverview = function(chartContainer, overviewContainer) {
		chartContainer.bind('plotselected', function(evt, range) {
			range.xaxis.from = Math.floor(range.xaxis.from);
			range.xaxis.to = Math.floor(range.xaxis.to);
			drawChart(chartContainer, range.xaxis.from, range.xaxis.to);
			overview.setSelection(range, true);
		});
		overviewContainer.bind('plotselected', function(evt, range) {
			chart.setSelection(range);
		});
	};

	var bindHoverInfo = function(chartContainer, detailContainer) {
		//alert('bindHoverInfo arguments: ' + chartContainer + ' | ' + detailContainer);
		chartContainer.bind('plothover', function(evt, position, item) {
			var itemIndex;
			if(item) {
				itemIndex = item.series.data[item.dataIndex][0];
				setDetail(detailContainer[0], labels[itemIndex][1], data[itemIndex][1]);
			}
		});
	};

	var setDetail = function(detailContainer, label, value) {
		// TODO: Add unit symbol for the data value?
		detailContainer.innerHTML = makeParagraph(label) + makeParagraph(value);
	};

	var makeParagraph = function(string) {
		return '<p>' + string + '</p>';
	};

	var addPanControls = function(chartContainer) {
		addPanControl(chartContainer, 'left', 45, 40, { left: -100 });
		addPanControl(chartContainer, 'right', 75, 40, { left: 100 });
		addPanControl(chartContainer, 'up', 60, 25, { top: -100 });
		addPanControl(chartContainer, 'down', 60, 55, { top: 100 });
	};

	var addPanControl = function(chartContainer, direction, left, top, offset) {
		createControlImage('arrow-' + direction + '.gif', 19, left, top).appendTo(chartContainer).click(function(evt) {
			evt.preventDefault();
			chart.pan(offset);
		});
	};

	var addZoomControls = function(chartContainer) {
		addZoomControl(chartContainer, 'in', 50, 80, function() { chart.zoom(); });
		addZoomControl(chartContainer, 'out', 70, 80, function() { chart.zoomOut(); });
	};

	var addZoomControl = function(chartContainer, direction, left, top, clickFunction) {
		createControlImage('zoom-' + direction + '.png', 20, left, top).appendTo(chartContainer).click(function(evt) {
			evt.preventDefault();
			clickFunction();
		});
	};

	var createControlImage = function(src, width, left, top) {
		return $('<img src="/sites/all/themes/ldp/images/' + src + '" style="cursor: pointer; width: ' + width + 'px; position: absolute; left: ' + left + 'px; top: ' + top + 'px;" />');
	};

	return self;
}());


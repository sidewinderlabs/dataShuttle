jQuery.fn.searchLabelReplace = function () {

	// Top search form (in navigation region)
	var topSearch = $('.block-search');
	var topSearchLabel = $('.block-search label');

	// Page search form
	var pageSearch = $('#search-form');
	var pageSearchValue = $('#search-form input#edit-keys[value]').val();
	
	// Replace "Search this site"
	topSearchLabel.text('Search');
		
};

$(document).ready(function() {

  // Remove page search form
  $('#page-tools .block-search').searchLabelReplace();

});
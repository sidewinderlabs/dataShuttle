$(document).ready(function() {

  // temporal grid bg
  
  bodyHeight = $('body').outerHeight();
  $('#page').before('<div class="bg-grid"></div>');
  $('.bg-grid').hide();
  $('.bg-grid').after('<a class="grid-toggle">Grid Toggle</a>');
  $('.bg-grid').css({height: bodyHeight +'px', opacity: 0.8});
  
  $('.grid-toggle').toggle(function() { 
    $('.bg-grid').show();
  }, function() { 
    $('.bg-grid').hide();
  });


});
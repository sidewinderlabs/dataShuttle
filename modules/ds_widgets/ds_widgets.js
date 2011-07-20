/*
 *  Currently Unused.
 *  This was an attempt to update the embed code based on the panel tab we're viewing
 *  Options: table, chart, map
 */

if (Drupal.jsEnabled) {
  $(document).ready(function(){
    
    // attach handler to each tab button 
    $('ul.ui-tabs-nav > li > a').click(function() {
      
      // update embed code to point to current display (map, chart, table)
      var embed_code = $('input.#web_widgets_0').val();
      var display_name = '';
      
      console.log($(this).attr('href'));
      switch($(this).attr('href')) {
        case '#viewsresults-tab-2':
          display_name = 'chart';
          break;
        case '#viewsresults-tab-3':
          display_name = 'table';
          break;
        case '#viewsresults-tab-4':
          display_name = 'map';
          break;
      }
      // TODO - regex to select correct text to replace
      $('input.#web_widgets_0').val(embed_code.replace(/chart/i, displayname));
      
      console.log($('input.#web_widgets_0').val());
    });
  
    
  });
}
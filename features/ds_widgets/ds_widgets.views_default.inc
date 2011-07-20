<?php

/**
 * Implementation of hook_views_default_views().
 */
function ds_widgets_views_default_views() {
  $views = array();

  // Exported view: indicator_results_widgets
  $view = new view;
  $view->name = 'indicator_results_widgets';
  $view->description = 'Shows results from a SPARQL query for an Indicator';
  $view->tag = 'ldp';
  $view->view_php = '';
  $view->base_table = 'sparql_ep';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = '&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options'] = array(
    'endpoint_url' => 'http://ec2-79-125-59-17.eu-west-1.compute.amazonaws.com:8890/sparql',
    'dataset_url' => '',
    'endpoint_read_key' => '',
    'handwritten_query' => 1,
    'prefixes' => 'prefix ohio: <http://data.dh.gov.uk/ontology/ohio/>
prefix scv: <http://purl.org/NET/scovo#>
prefix dct: <http://purl.org/dc/terms/>
prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#>
prefix xsd: <http://www.w3.org/2001/XMLSchema#>
prefix skos: <http://www.w3.org/2004/02/skos/core#>',
    'select_clause' => 'SELECT ?lad ?areacode ?year ?icdcode sum(xsd:int(?gendervalue)) as ?value ?lad_lat ?lad_long
WHERE { 
  [
     <http://purl.org/NET/scovo#dimension> ?lad ;

     <http://purl.org/NET/scovo#dimension> [
       a <http://reference.data.gov.uk/def/intervals/CalendarYear> ;
       rdfs:label ?year
     ] ;

     <http://purl.org/NET/scovo#dimension> [
       a <http://purl.org/linked-data/sdmx/2009/code#Sex> ;
       rdfs:label ?gender
     ] ;

     <http://purl.org/NET/scovo#dimension> [
       a <http://purl.bioontology.org/ontology/ICD10> ;
       rdfs:label ?icdcode
     ] ;

     <http://www.w3.org/1999/02/22-rdf-syntax-ns#value> ?gendervalue
   ] .

   graph ?lad {
     ?lad <http://www.w3.org/2004/02/skos/core#altLabel> ?areacode ;
       a <http://statistics.data.gov.uk/def/administrative-geography/LocalAuthorityDistrict> ;
       owl:sameAs ?os_lad .
   }
   ?os_lad <http://www.w3.org/2003/01/geo/wgs84_pos#lat> ?lad_lat ;
               <http://www.w3.org/2003/01/geo/wgs84_pos#long> ?lad_long .
   FILTER(xsd:int(?year) = [year])
   FILTER(?icdcode = "[icdcode]")
}
',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'areacode' => 'areacode',
    'value' => 'value',
    'lad_lat' => 'lad_lat',
    'lad_long' => 'lad_long',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'areacode' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'lad_lat' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'lad_long' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Field: SPARQL: areacode */
  $handler->display->display_options['fields']['areacode']['id'] = 'areacode';
  $handler->display->display_options['fields']['areacode']['table'] = 'sparql_ep';
  $handler->display->display_options['fields']['areacode']['field'] = 'areacode';
  $handler->display->display_options['fields']['areacode']['label'] = 'Local Authority District';
  $handler->display->display_options['fields']['areacode']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['areacode']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['areacode']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['areacode']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['areacode']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['areacode']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['areacode']['alter']['html'] = 0;
  $handler->display->display_options['fields']['areacode']['alter']['combine_values'] = 0;
  $handler->display->display_options['fields']['areacode']['alter']['separator'] = '';
  $handler->display->display_options['fields']['areacode']['hide_empty'] = 0;
  $handler->display->display_options['fields']['areacode']['empty_zero'] = 0;
  /* Field: SPARQL: value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'sparql_ep';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = 'Value';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['value']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value']['alter']['combine_values'] = 0;
  $handler->display->display_options['fields']['value']['alter']['separator'] = '';
  $handler->display->display_options['fields']['value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value']['empty_zero'] = 0;
  /* Field: SPARQL: lad_lat */
  $handler->display->display_options['fields']['lad_lat']['id'] = 'lad_lat';
  $handler->display->display_options['fields']['lad_lat']['table'] = 'sparql_ep';
  $handler->display->display_options['fields']['lad_lat']['field'] = 'lad_lat';
  $handler->display->display_options['fields']['lad_lat']['exclude'] = TRUE;
  $handler->display->display_options['fields']['lad_lat']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['lad_lat']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['lad_lat']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['lad_lat']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['lad_lat']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['lad_lat']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['lad_lat']['alter']['html'] = 0;
  $handler->display->display_options['fields']['lad_lat']['alter']['combine_values'] = 0;
  $handler->display->display_options['fields']['lad_lat']['alter']['separator'] = '';
  $handler->display->display_options['fields']['lad_lat']['hide_empty'] = 0;
  $handler->display->display_options['fields']['lad_lat']['empty_zero'] = 0;
  /* Field: SPARQL: lad_long */
  $handler->display->display_options['fields']['lad_long']['id'] = 'lad_long';
  $handler->display->display_options['fields']['lad_long']['table'] = 'sparql_ep';
  $handler->display->display_options['fields']['lad_long']['field'] = 'lad_long';
  $handler->display->display_options['fields']['lad_long']['exclude'] = TRUE;
  $handler->display->display_options['fields']['lad_long']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['lad_long']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['lad_long']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['lad_long']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['lad_long']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['lad_long']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['lad_long']['alter']['html'] = 0;
  $handler->display->display_options['fields']['lad_long']['alter']['combine_values'] = 0;
  $handler->display->display_options['fields']['lad_long']['alter']['separator'] = '';
  $handler->display->display_options['fields']['lad_long']['hide_empty'] = 0;
  $handler->display->display_options['fields']['lad_long']['empty_zero'] = 0;
  /* Argument: SPARQL: icdcode */
  $handler->display->display_options['arguments']['icdcode']['id'] = 'icdcode';
  $handler->display->display_options['arguments']['icdcode']['table'] = 'sparql_ep';
  $handler->display->display_options['arguments']['icdcode']['field'] = 'icdcode';
  $handler->display->display_options['arguments']['icdcode']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['icdcode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['icdcode']['replacement_type'] = 'arg';
  /* Argument: SPARQL: year */
  $handler->display->display_options['arguments']['year']['id'] = 'year';
  $handler->display->display_options['arguments']['year']['table'] = 'sparql_ep';
  $handler->display->display_options['arguments']['year']['field'] = 'year';
  $handler->display->display_options['arguments']['year']['default_action'] = 'default';
  $handler->display->display_options['arguments']['year']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['year']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['year']['default_argument_options']['code'] = 'if (isset($_GET[\'startdate\']) && is_numeric($_GET[\'startdate\'])) {
return $_GET[\'startdate\'];
}
else return \'2008\';';
  $handler->display->display_options['arguments']['year']['replacement_type'] = 'arg';
  
/* Display: Openlayers Data */
  $handler = $view->new_display('openlayers', 'Openlayers Data', 'openlayers_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'lad_lat',
    'other_lon' => 'lad_long',
    'openlayers_wkt' => 'areacode',
    'other_top' => 'areacode',
    'other_right' => 'areacode',
    'other_bottom' => 'areacode',
    'other_left' => 'areacode',
    'name_field' => 'areacode',
    'keep_orig_name_field' => 1,
    'description_field' => '',
    'keep_orig_desc_field' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: SPARQL: icdcode */
  $handler->display->display_options['arguments']['icdcode']['id'] = 'icdcode';
  $handler->display->display_options['arguments']['icdcode']['table'] = 'sparql_ep';
  $handler->display->display_options['arguments']['icdcode']['field'] = 'icdcode';
  $handler->display->display_options['arguments']['icdcode']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['icdcode']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['icdcode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['icdcode']['default_argument_options']['argument'] = 'G20';
  $handler->display->display_options['arguments']['icdcode']['replacement_type'] = 'arg';
  /* Argument: SPARQL: year */
  $handler->display->display_options['arguments']['year']['id'] = 'year';
  $handler->display->display_options['arguments']['year']['table'] = 'sparql_ep';
  $handler->display->display_options['arguments']['year']['field'] = 'year';
  $handler->display->display_options['arguments']['year']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['year']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['year']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['year']['default_argument_options']['code'] = 'if (isset($_GET[\'startdate\']) && is_numeric($_GET[\'startdate\'])) {
return $_GET[\'startdate\'];
}
else return \'2008\';';
  $handler->display->display_options['arguments']['year']['replacement_type'] = 'arg';
  
/* Display: Table Page */
  $handler = $view->new_display('page', 'Table Page', 'page_1');
  $handler->display->display_options['path'] = 'indicator_page/%/%/table';
  
/* Display: Web widget */
  $handler = $view->new_display('web_widgets', 'Web widget', 'web_widgets_1');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'indicator_widget/%/%/table';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'panel_pane_1' => 0,
    'panel_pane_3' => 0,
    'panel_pane_2' => 0,
  );
  
/* Display: Chart Page */
  $handler = $view->new_display('page', 'Chart Page', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'areacode' => 'areacode',
    'value' => 'value',
    'lad_lat' => 'lad_lat',
    'lad_long' => 'lad_long',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'areacode' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'value' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'lad_lat' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
    'lad_long' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'indicator_page/%/%/chart';
  
/* Display: Web widget */
  $handler = $view->new_display('web_widgets', 'Web widget', 'web_widgets_2');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'indicator_widget/%/%/chart';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'panel_pane_1' => 0,
    'panel_pane_3' => 0,
    'panel_pane_2' => 0,
    'page_1' => 0,
  );
  
/* Display: Map Page */
  $handler = $view->new_display('page', 'Map Page', 'page_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'ds_indicators_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'indicator_page/%/%/map';
  
/* Display: Web widget */
  $handler = $view->new_display('web_widgets', 'Web widget', 'web_widgets_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'ds_indicators_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'indicator_widget/%/%/map';
  $handler->display->display_options['displays'] = array(
    'page_3' => 'page_3',
    'default' => 0,
    'panel_pane_1' => 0,
    'panel_pane_3' => 0,
    'panel_pane_2' => 0,
    'page_1' => 0,
    'page_2' => 0,
  );

  $views[$view->name] = $view;

  return $views;
}

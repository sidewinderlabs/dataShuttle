<?php

/**
 * Implementation of hook_views_default_views().
 */
function ds_topics_views_default_views() {
  $views = array();

  // Exported view: topics_listing
  $view = new view;
  $view->name = 'topics_listing';
  $view->description = 'A listing of all ICD-10 chapters';
  $view->tag = 'topics';
  $view->view_php = '';
  $view->base_table = 'sparql_ep';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Topics';
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
    'select_clause' => '
SELECT DISTINCT ?title ?icdrangelabel WHERE {
  ?s a <http://datashuttle.org/ICDChapter>.
?s <http://purl.org/dc/elements/1.1/title> ?title ;
   <http://datashuttle.org/icdRange> ?icdrange .

?icdrange a <http://purl.bioontology.org/ontology/ICD10>; 
          rdfs:label ?icdrangelabel .
}
',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['row_plugin'] = 'semanticviews_fields';
  /* Field: SPARQL: icdrangelabel */
  $handler->display->display_options['fields']['icdrangelabel']['id'] = 'icdrangelabel';
  $handler->display->display_options['fields']['icdrangelabel']['table'] = 'sparql_ep';
  $handler->display->display_options['fields']['icdrangelabel']['field'] = 'icdrangelabel';
  $handler->display->display_options['fields']['icdrangelabel']['label'] = '';
  $handler->display->display_options['fields']['icdrangelabel']['exclude'] = TRUE;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['html'] = 0;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['combine_values'] = 0;
  $handler->display->display_options['fields']['icdrangelabel']['alter']['separator'] = '';
  $handler->display->display_options['fields']['icdrangelabel']['hide_empty'] = 0;
  $handler->display->display_options['fields']['icdrangelabel']['empty_zero'] = 0;
  /* Field: SPARQL: title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'sparql_ep';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'topic/[icdrangelabel]';
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['alter']['combine_values'] = 0;
  $handler->display->display_options['fields']['title']['alter']['separator'] = '';
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  
/* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'topics';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Topics';
  $handler->display->display_options['menu']['description'] = 'List all topics';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'primary-links';
  
/* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  $views[$view->name] = $view;

  return $views;
}

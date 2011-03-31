<?php

/**
 * Implementation of hook_views_default_views().
 */
function ds_mortality_indicators_views_default_views() {
  $views = array();

  // Exported view: indicator_details
  $view = new view;
  $view->name = 'indicator_details';
  $view->description = 'Indicator details such as source and quality statement';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Field: Content: Quality Statement (field_indicator_quality) */
  $handler->display->display_options['fields']['field_indicator_quality_value']['id'] = 'field_indicator_quality_value';
  $handler->display->display_options['fields']['field_indicator_quality_value']['table'] = 'node_data_field_indicator_quality';
  $handler->display->display_options['fields']['field_indicator_quality_value']['field'] = 'field_indicator_quality_value';
  $handler->display->display_options['fields']['field_indicator_quality_value']['label'] = 'Quality Statement';
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['link_to_node'] = 0;
  /* Argument: Content: ICD 10 range (field_icd10) */
  $handler->display->display_options['arguments']['field_icd10_value']['id'] = 'field_icd10_value';
  $handler->display->display_options['arguments']['field_icd10_value']['table'] = 'node_data_field_icd10';
  $handler->display->display_options['arguments']['field_icd10_value']['field'] = 'field_icd10_value';
  $handler->display->display_options['arguments']['field_icd10_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_icd10_value']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_icd10_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_icd10_value']['glossary'] = 0;
  $handler->display->display_options['arguments']['field_icd10_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_icd10_value']['transform_dash'] = 0;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'indicator' => 'indicator',
  );
  
/* Display: IndicatorBodyContent */
  $handler = $view->new_display('panel_pane', 'IndicatorBodyContent', 'indicator_body_content');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_icd10_value' => array(
      'type' => 'panel',
      'context' => 'node.field_subclassof-url',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: ICD 10 range (field_icd10)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';
  
/* Display: Indicator Source */
  $handler = $view->new_display('panel_pane', 'Indicator Source', 'indicator_source');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Source';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Source (field_indicator_source) */
  $handler->display->display_options['fields']['field_indicator_source_value']['id'] = 'field_indicator_source_value';
  $handler->display->display_options['fields']['field_indicator_source_value']['table'] = 'node_data_field_indicator_source';
  $handler->display->display_options['fields']['field_indicator_source_value']['field'] = 'field_indicator_source_value';
  $handler->display->display_options['fields']['field_indicator_source_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_indicator_source_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_indicator_source_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_indicator_source_value']['label_type'] = 'none';
  $handler->display->display_options['argument_input'] = array(
    'field_icd10_value' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: ICD 10 range (field_icd10)',
    ),
  );
  
/* Display: Indicator Quality Statement */
  $handler = $view->new_display('panel_pane', 'Indicator Quality Statement', 'indicator_quality');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Quality Statement';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Quality Statement (field_indicator_quality) */
  $handler->display->display_options['fields']['field_indicator_quality_value']['id'] = 'field_indicator_quality_value';
  $handler->display->display_options['fields']['field_indicator_quality_value']['table'] = 'node_data_field_indicator_quality';
  $handler->display->display_options['fields']['field_indicator_quality_value']['field'] = 'field_indicator_quality_value';
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_indicator_quality_value']['label_type'] = 'none';
  $handler->display->display_options['argument_input'] = array(
    'field_icd10_value' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: ICD 10 range (field_icd10)',
    ),
  );

  $views[$view->name] = $view;

  // Exported view: indicator_listing
  $view = new view;
  $view->name = 'indicator_listing';
  $view->description = 'Lists all indicator nodes';
  $view->tag = 'ldp';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Geographical Unit (field_indicator_geo_unit) */
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['id'] = 'field_indicator_geo_unit_value';
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['table'] = 'node_data_field_indicator_geo_unit';
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['field'] = 'field_indicator_geo_unit_value';
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['label'] = 'Geographical Unit';
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_indicator_geo_unit_value']['link_to_node'] = 0;
  /* Field: Content: ICD 10 range (field_icd10) */
  $handler->display->display_options['fields']['field_icd10_value']['id'] = 'field_icd10_value';
  $handler->display->display_options['fields']['field_icd10_value']['table'] = 'node_data_field_icd10';
  $handler->display->display_options['fields']['field_icd10_value']['field'] = 'field_icd10_value';
  $handler->display->display_options['fields']['field_icd10_value']['label'] = 'ICD 10 range';
  $handler->display->display_options['fields']['field_icd10_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_icd10_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_icd10_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_icd10_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_icd10_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_icd10_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_icd10_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_icd10_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_icd10_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_icd10_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_icd10_value']['link_to_node'] = 0;
  /* Field: Content: Subject (field_indicator_subject) */
  $handler->display->display_options['fields']['field_indicator_subject_value']['id'] = 'field_indicator_subject_value';
  $handler->display->display_options['fields']['field_indicator_subject_value']['table'] = 'node_data_field_indicator_subject';
  $handler->display->display_options['fields']['field_indicator_subject_value']['field'] = 'field_indicator_subject_value';
  $handler->display->display_options['fields']['field_indicator_subject_value']['label'] = 'Subject';
  $handler->display->display_options['fields']['field_indicator_subject_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_indicator_subject_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_indicator_subject_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_indicator_subject_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_indicator_subject_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_indicator_subject_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_indicator_subject_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_indicator_subject_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_indicator_subject_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_indicator_subject_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_indicator_subject_value']['link_to_node'] = 0;
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'indicator/[field_icd10_value]/[field_indicator_subject_value]/[field_indicator_geo_unit_value]/year/2008';
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Node: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'node_revisions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  /* Sort criterion: Node: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'indicator' => 'indicator',
  );
  
/* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'indicators';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Indicators';
  $handler->display->display_options['menu']['description'] = 'List all Indicators';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'primary-links';

  $views[$view->name] = $view;

  // Exported view: indicator_results
  $view = new view;
  $view->name = 'indicator_results';
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
    'select_clause' => 'SELECT  ?value ?areacode 
WHERE { 
        ?s <http://www.w3.org/1999/02/22-rdf-syntax-ns#value> ?value .
        
        ?s <http://purl.org/NET/scovo#dimension> ?lad .
        
        ?s <http://purl.org/NET/scovo#dimension> ?year .
        ?year a <http://reference.data.gov.uk/def/intervals/CalendarYear> .
        ?year rdfs:label ?yearlabel .

        ?s  <http://purl.org/NET/scovo#dimension> ?gender .
        ?gender a <http://purl.org/linked-data/sdmx/2009/code#Sex> .
        ?gender rdfs:label "M".

        ?s  <http://purl.org/NET/scovo#dimension> ?icdcode .
        ?icdcode a <http://purl.bioontology.org/ontology/ICD10> .
        ?icdcode rdfs:label "[icdcode]" .

        graph ?lad {
            ?lad <http://www.w3.org/2004/02/skos/core#altLabel> ?areacode .
            ?lad a <http://statistics.data.gov.uk/def/administrative-geography/LocalAuthorityDistrict> .
        }
FILTER(xsd:int(?value) > 0)
FILTER(xsd:int(?yearlabel) = [year])
}',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'icd10rangeuri' => 'icd10rangeuri',
    'areacode' => 'areacode',
    'value' => 'value',
    'yearuri' => 'yearuri',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'icd10rangeuri' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
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
    'yearuri' => array(
      'sortable' => 0,
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 0;
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
  
/* Display: Content pane: list by LAD by year */
  $handler = $view->new_display('panel_pane', 'Content pane: list by LAD by year', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'icdcode' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'SPARQL: icdcode',
    ),
    'year' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '3',
      'fixed' => '',
      'label' => 'SPARQL: year',
    ),
  );
  
/* Display: Content pane: graph display */
  $handler = $view->new_display('panel_pane', 'Content pane: graph display', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
  $handler->display->display_options['argument_input'] = array(
    'icdcode' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'SPARQL: icdcode',
    ),
    'year' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '3',
      'fixed' => '',
      'label' => 'SPARQL: year',
    ),
  );

  $views[$view->name] = $view;

  // Exported view: indicator_years
  $view = new view;
  $view->name = 'indicator_years';
  $view->description = 'Provides a list of available years for our indicator';
  $view->tag = 'ldp';
  $view->view_php = '';
  $view->base_table = 'sparql_ep';
  $view->is_cacheable = FALSE;
  $view->api_version = 3.0-alpha1;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
/* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'View by Year';
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
    'select_clause' => 'SELECT DISTINCT ?yearlabel
WHERE { 
        ?s  <http://purl.org/NET/scovo#dimension> ?icdcode .
        ?icdcode a <http://purl.bioontology.org/ontology/ICD10> .
        ?icdcode rdfs:label "[icdcode]" .

        ?s <http://purl.org/NET/scovo#dimension> ?year .
        ?year a <http://reference.data.gov.uk/def/intervals/CalendarYear> .
        ?year rdfs:label ?yearlabel .
}
ORDER BY DESC(?yearlabel)',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: SPARQL: yearlabel */
  $handler->display->display_options['fields']['yearlabel']['id'] = 'yearlabel';
  $handler->display->display_options['fields']['yearlabel']['table'] = 'sparql_ep';
  $handler->display->display_options['fields']['yearlabel']['field'] = 'yearlabel';
  $handler->display->display_options['fields']['yearlabel']['label'] = '';
  $handler->display->display_options['fields']['yearlabel']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['yearlabel']['alter']['text'] = '<a href="/indicator/!1/mortality/LAD/year/[yearlabel]">[yearlabel]</a>';
  $handler->display->display_options['fields']['yearlabel']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['yearlabel']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['yearlabel']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['yearlabel']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['yearlabel']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['yearlabel']['alter']['html'] = 0;
  $handler->display->display_options['fields']['yearlabel']['alter']['combine_values'] = 0;
  $handler->display->display_options['fields']['yearlabel']['alter']['separator'] = '';
  $handler->display->display_options['fields']['yearlabel']['hide_empty'] = 0;
  $handler->display->display_options['fields']['yearlabel']['empty_zero'] = 0;
  /* Argument: SPARQL: icdcode */
  $handler->display->display_options['arguments']['icdcode']['id'] = 'icdcode';
  $handler->display->display_options['arguments']['icdcode']['table'] = 'sparql_ep';
  $handler->display->display_options['arguments']['icdcode']['field'] = 'icdcode';
  $handler->display->display_options['arguments']['icdcode']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['icdcode']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['icdcode']['replacement_type'] = 'arg';
  
/* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'icdcode' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'SPARQL: icdcode',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  $views[$view->name] = $view;

  return $views;
}

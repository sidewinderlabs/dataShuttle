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
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Indicator';
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
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
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
  $translatables['indicator_details'] = array(
    t('Defaults'),
    t('Indicator'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Quality Statement'),
    t('All'),
    t('IndicatorBodyContent'),
    t('View panes'),
    t('Indicator Source'),
    t('Source'),
    t('Indicator Quality Statement'),
  );

  $views[$view->name] = $view;

  // Exported view: indicator_listing
  $view = new view;
  $view->name = 'indicator_listing';
  $view->description = 'Lists all indicator nodes';
  $view->tag = 'ldp';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
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
  $handler->display->display_options['fields']['title']['alter']['path'] = 'indicator/[field_icd10_value]/[field_indicator_subject_value]/[field_indicator_geo_unit_value]/year/2009';
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
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['validate_type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vids'] = array(
    1 => 1,
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 0;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['tid']['use_synonym_for_summary_links'] = 0;
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
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'primary-links';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $translatables['indicator_listing'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Geographical Unit'),
    t('ICD 10 range'),
    t('Subject'),
    t('indicator/[field_icd10_value]/[field_indicator_subject_value]/[field_indicator_geo_unit_value]/year/2009'),
    t('All'),
    t('Page'),
    t('Block'),
  );

  $views[$view->name] = $view;

  // Exported view: indicator_results_solr
  $view = new view;
  $view->name = 'indicator_results_solr';
  $view->description = '';
  $view->tag = 'ldp';
  $view->base_table = 'solr_server_indicators';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Solr Server: area_name */
  $handler->display->display_options['fields']['area_name']['id'] = 'area_name';
  $handler->display->display_options['fields']['area_name']['table'] = 'solr_server_indicators';
  $handler->display->display_options['fields']['area_name']['field'] = 'area_name';
  $handler->display->display_options['fields']['area_name']['label'] = 'Local Authority District';
  $handler->display->display_options['fields']['area_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['area_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['area_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['area_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['area_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['area_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['area_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['area_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['area_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['area_name']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['area_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['area_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['area_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['area_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['area_name']['empty_zero'] = 0;
  /* Field: Solr Server: value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'solr_server_indicators';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = 'Value';
  $handler->display->display_options['fields']['value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['value']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['value']['empty_zero'] = 0;
  /* Argument: Solr Server: icd */
  $handler->display->display_options['arguments']['icd']['id'] = 'icd';
  $handler->display->display_options['arguments']['icd']['table'] = 'solr_server_indicators';
  $handler->display->display_options['arguments']['icd']['field'] = 'icd';
  $handler->display->display_options['arguments']['icd']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['icd']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['icd']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['icd']['not'] = 0;
  /* Argument: Solr Server: year */
  $handler->display->display_options['arguments']['year']['id'] = 'year';
  $handler->display->display_options['arguments']['year']['table'] = 'solr_server_indicators';
  $handler->display->display_options['arguments']['year']['field'] = 'year';
  $handler->display->display_options['arguments']['year']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['year']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['year']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['year']['not'] = 0;

  /* Display: Content pane: list by LAD by year */
  $handler = $view->new_display('panel_pane', 'Content pane: list by LAD by year', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'icd' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Solr Server: icd',
    ),
    'year' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '3',
      'fixed' => '',
      'label' => 'Solr Server: year',
    ),
  );

  /* Display: Content pane: graph display */
  $handler = $view->new_display('panel_pane', 'Content pane: graph display', 'panel_pane_2');
  $handler->display->display_options['argument_input'] = array(
    'icd' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Solr Server: icd',
    ),
    'year' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '3',
      'fixed' => '',
      'label' => 'Solr Server: year',
    ),
  );

  /* Display: OpenLayers Data */
  $handler = $view->new_display('openlayers', 'OpenLayers Data', 'openlayers_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'area',
    'other_lon' => 'area',
    'openlayers_wkt' => 'area',
    'other_top' => 'area',
    'other_right' => 'area',
    'other_bottom' => 'area',
    'other_left' => 'area',
    'name_field' => '',
    'keep_orig_name_field' => 1,
    'description_field' => '',
    'keep_orig_desc_field' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Content pane: Map */
  $handler = $view->new_display('panel_pane', 'Content pane: Map', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['preset'] = 'ds_indicators_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'icd' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Solr Server: icd',
    ),
    'year' => array(
      'type' => 'panel',
      'context' => 'string.html_safe',
      'context_optional' => 0,
      'panel' => '3',
      'fixed' => '',
      'label' => 'Solr Server: year',
    ),
  );
  $translatables['indicator_results_solr'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Local Authority District'),
    t('Value'),
    t('All'),
    t('Content pane: list by LAD by year'),
    t('View panes'),
    t('Content pane: graph display'),
    t('OpenLayers Data'),
    t('Content pane: Map'),
    t('Map'),
  );

  $views[$view->name] = $view;

  return $views;
}

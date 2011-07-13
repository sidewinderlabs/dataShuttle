<?php

/**
 * Implementation of hook_views_default_views().
 */
function ds_locations_views_default_views() {
  $views = array();

  // Exported view: location_listing
  $view = new view;
  $view->name = 'location_listing';
  $view->description = 'List all locations';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = 'field_location_gor_value';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Government Office Region (field_location_gor) */
  $handler->display->display_options['fields']['field_location_gor_value']['id'] = 'field_location_gor_value';
  $handler->display->display_options['fields']['field_location_gor_value']['table'] = 'node_data_field_location_gor';
  $handler->display->display_options['fields']['field_location_gor_value']['field'] = 'field_location_gor_value';
  $handler->display->display_options['fields']['field_location_gor_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_gor_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location_gor_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location_gor_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location_gor_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location_gor_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location_gor_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location_gor_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location_gor_value']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_location_gor_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location_gor_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_location_gor_value']['label_type'] = 'none';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 1;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );
  /* Filter: Node: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['title']['value'] = '0';
  $handler->display->display_options['filters']['title']['case'] = 0;
  /* Filter: Content: Government Office Region (field_location_gor) */
  $handler->display->display_options['filters']['field_location_gor_value']['id'] = 'field_location_gor_value';
  $handler->display->display_options['filters']['field_location_gor_value']['table'] = 'node_data_field_location_gor';
  $handler->display->display_options['filters']['field_location_gor_value']['field'] = 'field_location_gor_value';
  $handler->display->display_options['filters']['field_location_gor_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_location_gor_value']['case'] = 1;
  
/* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'locations';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Areas';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'primary-links';

  $views[$view->name] = $view;

  return $views;
}

<?php

/**
 * Implementation of hook_strongarm().
 */
function ds_mortality_indicators_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_passthru_servers';
  $strongarm->value = array(
    'site_default' => array(
      'machine_name' => 'site_default',
      'human_name' => 'Site Default',
      'solr_host' => 'localhost',
      'solr_port' => '8983',
      'solr_path' => '/solr',
    ),
    'indicators' => array(
      'machine_name' => 'indicators',
      'human_name' => 'Indicators',
      'solr_host' => 'localhost',
      'solr_port' => '8983',
      'solr_path' => '/solr',
    ),
  );

  $export['apachesolr_passthru_servers'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_indicator';
  $strongarm->value = 0;

  $export['comment_anonymous_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_indicator';
  $strongarm->value = '3';

  $export['comment_controls_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_indicator';
  $strongarm->value = '4';

  $export['comment_default_mode_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_indicator';
  $strongarm->value = '1';

  $export['comment_default_order_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_indicator';
  $strongarm->value = '50';

  $export['comment_default_per_page_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_indicator';
  $strongarm->value = '0';

  $export['comment_form_location_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_indicator';
  $strongarm->value = '2';

  $export['comment_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_indicator';
  $strongarm->value = '1';

  $export['comment_preview_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_indicator';
  $strongarm->value = '1';

  $export['comment_subject_field_indicator'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_indicator';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_indicator'] = $strongarm;
  return $export;
}

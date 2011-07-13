<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function ds_locations_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'areas_section';
  $context->description = 'Areas Section';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'locations' => 'locations',
        'area/*' => 'area/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'locations',
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'section-shuttles',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Areas Section');
  t('section');

  $export['areas_section'] = $context;
  return $export;
}

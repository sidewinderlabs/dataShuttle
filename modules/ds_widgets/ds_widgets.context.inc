<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function ds_widgets_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'indicator_page';
  $context->description = 'Indicator Page';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'indicator/*' => 'indicator/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds_widgets-embed' => array(
          'module' => 'ds_widgets',
          'delta' => 'embed',
          'region' => 'palette',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Indicator Page');
  t('page');

  $export['indicator_page'] = $context;
  return $export;
}

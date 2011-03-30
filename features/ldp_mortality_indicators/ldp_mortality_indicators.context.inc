<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function ldp_mortality_indicators_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'indicators_section';
  $context->description = 'Indicators section';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'indicators' => 'indicators',
        'indicator/*' => 'indicator/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'indicators',
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'section-indicators',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Indicators section');
  t('section');

  $export['indicators_section'] = $context;
  return $export;
}

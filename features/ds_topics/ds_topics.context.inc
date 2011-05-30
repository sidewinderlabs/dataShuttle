<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function ds_topics_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topics_section';
  $context->description = 'Topics Section';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'topics' => 'topics',
        'topic/*' => 'topic/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'topics',
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'section-topics',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Topics Section');
  t('section');

  $export['topics_section'] = $context;
  return $export;
}

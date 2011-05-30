<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function datashuttle_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Home Page';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-topics_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'topics_listing-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-home_topstories-block_1' => array(
          'module' => 'views',
          'delta' => 'home_topstories-block_1',
          'region' => 'content',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page');
  t('page');

  $export['home'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_section';
  $context->description = 'Home section of dataShuttle';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'page/linked-data-applications-platform-innovation' => 'page/linked-data-applications-platform-innovation',
        'video/*' => 'video/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-2' => array(
          'module' => 'menu_block',
          'delta' => 2,
          'region' => 'page_tools',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'home',
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'section-home',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home section of dataShuttle');
  t('section');

  $export['home_section'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'site_layout';
  $context->description = 'Global site layout';
  $context->tag = 'global';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-primary-links' => array(
          'module' => 'menu',
          'delta' => 'primary-links',
          'region' => 'page_tools',
          'weight' => 0,
        ),
        'search-0' => array(
          'module' => 'search',
          'delta' => 0,
          'region' => 'page_tools',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global site layout');
  t('global');

  $export['site_layout'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videos_section';
  $context->description = 'Videos section';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'video' => 'video',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-video_listing-block_1' => array(
          'module' => 'views',
          'delta' => 'video_listing-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
    'menu' => 'node/2',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Videos section');
  t('section');

  $export['videos_section'] = $context;
  return $export;
}

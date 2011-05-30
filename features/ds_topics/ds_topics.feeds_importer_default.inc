<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function ds_topics_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'topics';
  $feeds_importer->config = array(
    'name' => 'Topics',
    'description' => 'Import ICD Chapters as topics',
    'fetcher' => array(
      'plugin_key' => 'RdfImporterSparqlFetcher',
      'config' => array(
        'enable_data_queries' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'RdfImporterParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'features_topics',
        'update_existing' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'a:1:{s:31:"http://datashuttle.org/icdRange";a:1:{s:42:"http://www.w3.org/2000/01/rdf-schema#label";a:0:{}}}',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'a:1:{s:37:"http://purl.org/dc/elements/1.1/title";a:0:{}}',
            'target' => 'description',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
  );

  $export['topics'] = $feeds_importer;
  return $export;
}

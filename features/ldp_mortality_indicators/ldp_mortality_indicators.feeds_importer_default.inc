<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function ldp_mortality_indicators_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'indicators';
  $feeds_importer->config = array(
    'name' => 'Indicators',
    'description' => 'Indicators from RDF',
    'fetcher' => array(
      'plugin_key' => 'RdfImporterSparqlFetcher',
      'config' => array(
        'enable_data_queries' => '1',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'RdfImporterParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'RdfImporterNodeProcessor',
      'config' => array(
        'content_type' => 'indicator',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'a:1:{s:31:"http://datashuttle.org/icdRange";a:1:{s:42:"http://www.w3.org/2000/01/rdf-schema#label";a:0:{}}}',
            'target' => 'field_icd10',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'a:1:{s:37:"http://purl.org/dc/elements/1.1/title";a:0:{}}',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'a:1:{s:39:"http://purl.org/dc/elements/1.1/subject";a:0:{}}',
            'target' => 'field_indicator_subject',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'a:1:{s:48:"http://datashuttle.org/indicatorQualityStatement";a:0:{}}',
            'target' => 'field_indicator_quality',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'a:1:{s:39:"http://purl.org/dc/elements/1.1/spatial";a:0:{}}',
            'target' => 'field_indicator_geo_unit',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'a:1:{s:41:"http://purl.org/dc/elements/1.1/publisher";a:0:{}}',
            'target' => 'field_indicator_source',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'a:1:{s:43:"http://purl.org/dc/elements/1.1/description";a:0:{}}',
            'target' => 'body',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'arc_caching' => '1',
        'batch_size' => '10',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['indicators'] = $feeds_importer;
  return $export;
}

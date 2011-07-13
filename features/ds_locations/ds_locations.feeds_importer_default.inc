<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function ds_locations_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'locations';
  $feeds_importer->config = array(
    'name' => 'Locations',
    'description' => 'Locations ',
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
      'plugin_key' => 'RdfImporterNodeProcessor',
      'config' => array(
        'content_type' => 'location',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'a:1:{s:73:"http://statistics.data.gov.uk/def/administrative-geography/localAuthority";a:1:{s:42:"http://www.w3.org/2000/01/rdf-schema#label";a:0:{}}}',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'a:1:{s:44:"http://www.w3.org/2004/02/skos/core#notation";a:0:{}}',
            'target' => 'field_location_code',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'a:1:{s:65:"http://statistics.data.gov.uk/def/administrative-geography/region";a:1:{s:42:"http://www.w3.org/2000/01/rdf-schema#label";a:0:{}}}',
            'target' => 'field_location_gor',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'arc_caching' => '1',
        'batch_size' => '50',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['locations'] = $feeds_importer;
  return $export;
}

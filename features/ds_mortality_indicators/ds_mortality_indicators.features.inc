<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ds_mortality_indicators_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  elseif ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => 1);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function ds_mortality_indicators_node_info() {
  $items = array(
    'indicator' => array(
      'name' => t('Indicator'),
      'module' => 'features',
      'description' => t('An indicator is one or more statistics that can be categorised and associated with other nodes.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function ds_mortality_indicators_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}

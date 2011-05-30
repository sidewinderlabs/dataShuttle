<?php

/**
 * Implementation of hook_openlayers_presets().
 */
function ds_mortality_indicators_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'ds_indicators_map';
  $openlayers_presets->title = 'DS Indicators Map';
  $openlayers_presets->description = 'Google Map for DS Indicators';
  $openlayers_presets->data = array(
    'width' => '716px',
    'height' => '600px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-1.812744140547, 52.348763180486',
        'zoom' => '7',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_plus_behavior_scalepoints' => array(
        'min' => array(
          'value' => '',
          'pointRadius' => '10',
          'fillOpacity' => '0',
          'strokeWidth' => '',
        ),
        'max' => array(
          'value' => '',
          'pointRadius' => '10',
          'fillOpacity' => '1',
          'strokeWidth' => '',
        ),
        'method' => 'area',
        'distinct' => '30',
        'fields' => 'value_rendered',
        'min_label' => '-1',
      ),
      'openlayers_plus_behavior_popup' => array(),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => 'darkblue',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'indicator_results_openlayers_1',
        'point_zoom_level' => '5',
      ),
    ),
    'default_layer' => 'google_normal',
    'layers' => array(
      'google_normal' => 'google_normal',
      'osm_mapnik' => 'osm_mapnik',
      'indicator_results_openlayers_1' => 'indicator_results_openlayers_1',
    ),
    'layer_styles' => array(
      'indicator_results_openlayers_1' => array(
        'default' => 'indicator_point',
        'select' => 'indicator_point',
        'temporary' => 'indicator_point',
      ),
    ),
    'layer_activated' => array(
      'indicator_results_openlayers_1' => 'indicator_results_openlayers_1',
    ),
    'layer_switcher' => array(
      'indicator_results_openlayers_1' => 'indicator_results_openlayers_1',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
    'preset_name' => 'ds_indicators_map',
  );

  $export['ds_indicators_map'] = $openlayers_presets;
  return $export;
}

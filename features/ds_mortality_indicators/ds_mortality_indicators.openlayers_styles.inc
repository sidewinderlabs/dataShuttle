<?php

/**
 * Implementation of hook_openlayers_styles().
 */
function ds_mortality_indicators_openlayers_styles() {
  $export = array();
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'indicator_point';
  $openlayers_styles->title = 'Indicator Point';
  $openlayers_styles->description = 'Point style for indicators where radius is value.';
  $openlayers_styles->data = array(
    'pointRadius' => '${value_rendered}',
    'fillColor' => '#000000',
    'strokeColor' => '#dedede',
    'strokeWidth' => 1,
    'fillOpacity' => 0.5,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export["indicator_point"] = $openlayers_styles;
  return $export;
}

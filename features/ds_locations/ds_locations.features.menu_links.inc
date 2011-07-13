<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function ds_locations_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:locations
  $menu_links['primary-links:locations'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'locations',
    'router_path' => 'locations',
    'link_title' => 'Areas',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Areas');


  return $menu_links;
}

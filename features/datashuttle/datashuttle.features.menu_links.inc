<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function datashuttle_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:44169c2c-ab80-102e-85e7-000c29185f7f
  $menu_links['primary-links:44169c2c-ab80-102e-85e7-000c29185f7f'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => 'A Linked Data Applications Platform for Innovation',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'home',
    'uuid' => '44169c2c-ab80-102e-85e7-000c29185f7f',
  );
  // Exported menu link: primary-links:4416a4d8-ab80-102e-85e7-000c29185f7f
  $menu_links['primary-links:4416a4d8-ab80-102e-85e7-000c29185f7f'] = array(
    'menu_name' => 'primary-links',
    'router_path' => 'node/%',
    'link_title' => 'Videos',
    'options' => array(
      'attributes' => array(
        'title' => 'Why is the NIC using Linked Data?',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
    'parent_path' => 'home',
    'uuid' => '4416a4d8-ab80-102e-85e7-000c29185f7f',
  );
  // Exported menu link: primary-links:home
  $menu_links['primary-links:home'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-10',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Home');
  t('Videos');


  return $menu_links;
}

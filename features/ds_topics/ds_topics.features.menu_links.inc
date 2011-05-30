<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function ds_topics_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:topics
  $menu_links['primary-links:topics'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'topics',
    'router_path' => 'topics',
    'link_title' => 'Topics',
    'options' => array(
      'attributes' => array(
        'title' => 'List all topics',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '1',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Topics');


  return $menu_links;
}

<?php

/**
 * Implementation of preprocess_page().
 */
function ldp_preprocess_page(&$vars) {
  // Add body class for theme.
  $vars['attr']['class'] .= ' ldp';
}


// Fix Context Active menu problem
// http://drupal.org/node/586396#comment-3938142
function ldp_menu_item_link($link) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }

  // Check if we match a context rule
  $contexts = context_active_contexts();
  foreach($contexts as $context) {
    if (isset($context->reactions['menu'])
        && $context->reactions['menu'] == $link['href']) {
      $link['localized_options']['attributes']['class'] .= 'active';
    }
  }

  return l($link['title'], $link['href'], $link['localized_options']);
}
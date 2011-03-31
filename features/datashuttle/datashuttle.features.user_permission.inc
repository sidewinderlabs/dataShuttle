<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function datashuttle_user_default_permissions() {
  $permissions = array();

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}

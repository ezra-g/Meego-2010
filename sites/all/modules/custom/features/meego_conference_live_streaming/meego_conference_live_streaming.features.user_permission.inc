<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function meego_conference_live_streaming_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_live_streaming
  $permissions['edit field_live_streaming'] = array(
    'name' => 'edit field_live_streaming',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: view field_live_streaming
  $permissions['view field_live_streaming'] = array(
    'name' => 'view field_live_streaming',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}

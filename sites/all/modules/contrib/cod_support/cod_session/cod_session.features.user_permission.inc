<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_session_user_default_permissions() {
  $permissions = array();

  // Exported permission: create session content
  $permissions['create session content'] = array(
    'name' => 'create session content',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: create time_slot content
  $permissions['create time_slot content'] = array(
    'name' => 'create time_slot content',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: delete any session content
  $permissions['delete any session content'] = array(
    'name' => 'delete any session content',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: delete any time_slot content
  $permissions['delete any time_slot content'] = array(
    'name' => 'delete any time_slot content',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: delete own session content
  $permissions['delete own session content'] = array(
    'name' => 'delete own session content',
    'roles' => array(),
  );

  // Exported permission: delete own time_slot content
  $permissions['delete own time_slot content'] = array(
    'name' => 'delete own time_slot content',
    'roles' => array(),
  );

  // Exported permission: edit any session content
  $permissions['edit any session content'] = array(
    'name' => 'edit any session content',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit any time_slot content
  $permissions['edit any time_slot content'] = array(
    'name' => 'edit any time_slot content',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit field_accepted
  $permissions['edit field_accepted'] = array(
    'name' => 'edit field_accepted',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_session_confirmation
  $permissions['edit field_session_confirmation'] = array(
    'name' => 'edit field_session_confirmation',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'content administrator',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: edit field_session_slot
  $permissions['edit field_session_slot'] = array(
    'name' => 'edit field_session_slot',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit field_session_summary
  $permissions['edit field_session_summary'] = array(
    'name' => 'edit field_session_summary',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'content administrator',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: edit field_slot_datetime
  $permissions['edit field_slot_datetime'] = array(
    'name' => 'edit field_slot_datetime',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit field_sponsorship_level
  $permissions['edit field_sponsorship_level'] = array(
    'name' => 'edit field_sponsorship_level',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: edit field_track
  $permissions['edit field_track'] = array(
    'name' => 'edit field_track',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit own session content
  $permissions['edit own session content'] = array(
    'name' => 'edit own session content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own time_slot content
  $permissions['edit own time_slot content'] = array(
    'name' => 'edit own time_slot content',
    'roles' => array(),
  );

  // Exported permission: view field_accepted
  $permissions['view field_accepted'] = array(
    'name' => 'view field_accepted',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'content administrator',
      '3' => 'session organizer',
      '4' => 'site administrator',
    ),
  );

  // Exported permission: view field_session_confirmation
  $permissions['view field_session_confirmation'] = array(
    'name' => 'view field_session_confirmation',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: view field_session_slot
  $permissions['view field_session_slot'] = array(
    'name' => 'view field_session_slot',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'content administrator',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_session_summary
  $permissions['view field_session_summary'] = array(
    'name' => 'view field_session_summary',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'content administrator',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_slot_datetime
  $permissions['view field_slot_datetime'] = array(
    'name' => 'view field_slot_datetime',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: view field_track
  $permissions['view field_track'] = array(
    'name' => 'view field_track',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  return $permissions;
}

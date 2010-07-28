<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _cod_session_content_default_fields() {
  $fields = array();

  // Exported field: field_accepted
  $fields[] = array(
    'field_name' => 'field_accepted',
    'type_name' => 'session',
    'display_settings' => array(
      'weight' => '41',
      'parent' => 'group_audience',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Accepted?',
      'weight' => '41',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_day
  $fields[] = array(
    'field_name' => 'field_day',
    'type_name' => 'session',
    'display_settings' => array(
      'weight' => '33',
      'parent' => 'group_schedule',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Day',
      'weight' => '33',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_room
  $fields[] = array(
    'field_name' => 'field_room',
    'type_name' => 'session',
    'display_settings' => array(
      'weight' => '35',
      'parent' => 'group_schedule',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Room',
      'weight' => '35',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_skill_level
  $fields[] = array(
    'field_name' => 'field_skill_level',
    'type_name' => 'session',
    'display_settings' => array(
      'weight' => '40',
      'parent' => 'group_audience',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Skill Level',
      'weight' => '40',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_slot
  $fields[] = array(
    'field_name' => 'field_slot',
    'type_name' => 'session',
    'display_settings' => array(
      'weight' => '34',
      'parent' => 'group_schedule',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Time Slot',
      'weight' => '34',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_track
  $fields[] = array(
    'field_name' => 'field_track',
    'type_name' => 'session',
    'display_settings' => array(
      'weight' => '39',
      'parent' => 'group_audience',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Track',
      'weight' => '39',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  array(
    t('Accepted?'),
    t('Day'),
    t('Room'),
    t('Skill Level'),
    t('Time Slot'),
    t('Track'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_fieldgroup_default_groups().
 */
function _cod_session_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_audience
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'session',
    'group_name' => 'group_audience',
    'label' => 'Audience',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '38',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '38',
    'fields' => array(
      '0' => 'field_track',
      '1' => 'field_skill_level',
      '2' => 'field_accepted',
    ),
  );

  // Exported group: group_schedule
  $groups[] = array(
    'group_type' => 'standard',
    'type_name' => 'session',
    'group_name' => 'group_schedule',
    'label' => 'Schedule Info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '35',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '35',
    'fields' => array(
      '0' => 'field_day',
      '1' => 'field_slot',
      '2' => 'field_room',
    ),
  );

  // Translatables
  array(
    t('Audience'),
    t('Schedule Info'),
  );

  return $groups;
}

/**
 * Helper to implementation of hook_flag_default_flags().
 */
function _cod_session_flag_default_flags() {
$flags = array();
// Exported flag: "Session Attending".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'session_schedule',
  'title' => 'Session Attending',
  'global' => '0',
  'types' => 
  array (
    0 => 'session',
  ),
  'flag_short' => 'I\'m Attending',
  'flag_long' => 'Attend this session',
  'flag_message' => 'This session will be added to your schedule!',
  'unflag_short' => 'Remove from my schedule',
  'unflag_long' => '',
  'unflag_message' => '',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 2,
    ),
    'unflag' => 
    array (
      0 => 2,
    ),
  ),
  'show_on_page' => 1,
  'show_on_teaser' => 1,
  'show_on_form' => 0,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'cod_session',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
// Exported flag: "Session Vote".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'session_vote',
  'title' => 'Session Vote',
  'global' => '0',
  'types' => 
  array (
    0 => 'session',
  ),
  'flag_short' => 'Vote for this session',
  'flag_long' => 'Vote for this session',
  'flag_message' => 'Your vote has been recorded!',
  'unflag_short' => 'Retract vote',
  'unflag_long' => 'Retract your vote for this session.',
  'unflag_message' => 'Your vote has been retracted.',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 2,
    ),
    'unflag' => 
    array (
      0 => 2,
    ),
  ),
  'show_on_page' => 1,
  'show_on_teaser' => 0,
  'show_on_form' => 0,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'cod_session',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
return $flags;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _cod_session_user_default_permissions() {
  $permissions = array();

  // Exported permission: create session content
  $permissions[] = array(
    'name' => 'create session content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete own session content
  $permissions[] = array(
    'name' => 'delete own session content',
    'roles' => array(),
  );

  // Exported permission: edit field_accepted
  $permissions[] = array(
    'name' => 'edit field_accepted',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_day
  $permissions[] = array(
    'name' => 'edit field_day',
    'roles' => array(
      '0' => 'session organizer',
    ),
  );

  // Exported permission: edit field_room
  $permissions[] = array(
    'name' => 'edit field_room',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_skill_level
  $permissions[] = array(
    'name' => 'edit field_skill_level',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_slot
  $permissions[] = array(
    'name' => 'edit field_slot',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_sponsorship_level
  $permissions[] = array(
    'name' => 'edit field_sponsorship_level',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: edit field_track
  $permissions[] = array(
    'name' => 'edit field_track',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit own session content
  $permissions[] = array(
    'name' => 'edit own session content',
    'roles' => array(),
  );

  // Exported permission: view field_accepted
  $permissions[] = array(
    'name' => 'view field_accepted',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: view field_day
  $permissions[] = array(
    'name' => 'view field_day',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: view field_room
  $permissions[] = array(
    'name' => 'view field_room',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_skill_level
  $permissions[] = array(
    'name' => 'view field_skill_level',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_slot
  $permissions[] = array(
    'name' => 'view field_slot',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'session organizer',
      '3' => 'site administrator',
    ),
  );

  // Exported permission: view field_track
  $permissions[] = array(
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

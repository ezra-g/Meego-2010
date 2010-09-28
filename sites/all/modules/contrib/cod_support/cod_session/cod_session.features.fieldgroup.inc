<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function cod_session_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_audience
  $groups['session-group_audience'] = array(
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
        'weight' => '2',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'hidden',
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
    'weight' => '3',
    'fields' => array(
      '0' => 'field_topics',
      '1' => 'field_track',
    ),
  );

  // Exported group: group_schedule
  $groups['session-group_schedule'] = array(
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
        'weight' => '1',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'hidden',
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
    'weight' => '1',
    'fields' => array(
      '0' => 'field_accepted',
      '1' => 'field_session_slot',
      '2' => 'field_session_room',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Audience');
  t('Schedule Info');

  return $groups;
}

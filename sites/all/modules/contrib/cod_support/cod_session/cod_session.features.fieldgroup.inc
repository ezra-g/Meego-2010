<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function cod_session_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_schedule
  $groups['schedule_item-group_schedule'] = array(
    'group_type' => 'standard',
    'type_name' => 'schedule_item',
    'group_name' => 'group_schedule',
    'label' => 'Schedule info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_accepted',
      '1' => 'field_session_slot',
      '2' => 'field_session_room',
    ),
  );

  // Exported group: group_audience
  $groups['session-group_audience'] = array(
    'group_type' => 'standard',
    'type_name' => 'session',
    'group_name' => 'group_audience',
    'label' => 'Audience',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_vertical_tab',
        'description' => '',
      ),
      'display' => array(
        'weight' => '3',
        '4' => array(
          'format' => 'no_style',
          'exclude' => 1,
        ),
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
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
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
    'label' => 'Schedule info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_vertical_tab',
        'description' => '',
      ),
      'display' => array(
        'weight' => '2',
        '4' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
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
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '2',
    'fields' => array(
      '0' => 'field_accepted',
      '1' => 'field_session_slot',
      '2' => 'field_session_room',
      '3' => 'field_duration',
      '4' => 'field_live_streaming',
    ),
  );

  // Exported group: group_slides
  $groups['session-group_slides'] = array(
    'group_type' => 'standard',
    'type_name' => 'session',
    'group_name' => 'group_slides',
    'label' => 'Slides',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'weight' => '1',
        '4' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'label' => 'above',
        'teaser' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'description' => '',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
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
      '0' => 'field_slides',
    ),
  );

  // Exported group: group_video
  $groups['session-group_video'] = array(
    'group_type' => 'standard',
    'type_name' => 'session',
    'group_name' => 'group_video',
    'label' => 'Video',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsed',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-4',
        '4' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'description' => '',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-4',
    'fields' => array(
      '0' => 'field_video_embed',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Audience');
  t('Schedule info');
  t('Slides');
  t('Video');

  return $groups;
}

<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _cod_sponsors_content_default_fields() {
  $fields = array();

  // Exported field: field_logo
  $fields[] = array(
    'field_name' => 'field_logo',
    'type_name' => 'sponsor',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '1',
    'list_default' => 0,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Logo',
      'weight' => '32',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_related_attendees
  $fields[] = array(
    'field_name' => 'field_related_attendees',
    'type_name' => 'sponsor',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'type' => 'userreference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '2' => 0,
    ),
    'referenceable_status' => '',
    'advanced_view' => '',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => NULL,
          '_error_element' => 'default_value_widget][field_related_attendees][0][uid][uid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Related Attendees',
      'weight' => '31',
      'description' => '',
      'type' => 'userreference_autocomplete',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_sponsorship_level
  $fields[] = array(
    'field_name' => 'field_sponsorship_level',
    'type_name' => 'sponsor',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Platinum
Gold
Silver
Bronze',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sponsorship Level',
      'weight' => '33',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  array(
    t('Logo'),
    t('Related Attendees'),
    t('Sponsorship Level'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _cod_sponsors_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'context_ui',
    'attribute' => 'section',
    'value' => 'sponsors',
    'description' => 'Sponsors page',
    'views' => array(
      '0' => 'Sponsors',
    ),
    'block' => array(
      'views_Sponsors-block_1' => array(
        'module' => 'views',
        'delta' => 'Sponsors-block_1',
        'weight' => 10,
        'region' => 'content',
        'status' => '0',
        'label' => 'Sponsors: Gold Sponsor Block',
        'type' => 'context_ui',
      ),
      'views_Sponsors-block_2' => array(
        'module' => 'views',
        'delta' => 'Sponsors-block_2',
        'weight' => 11,
        'region' => 'content',
        'status' => '0',
        'label' => 'Sponsors: Silver Sponsor Block',
        'type' => 'context_ui',
      ),
      'views_Sponsors-block_3' => array(
        'module' => 'views',
        'delta' => 'Sponsors-block_3',
        'weight' => 12,
        'region' => 'content',
        'status' => '0',
        'label' => 'Sponsors: Bronze Sponsor Block',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _cod_sponsors_imagecache_default_presets() {
  $items = array(
    'sponsor_logo_bronze' => array(
      'presetname' => 'sponsor_logo_bronze',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_callout' => array(
      'presetname' => 'sponsor_logo_callout',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '200',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_gold' => array(
      'presetname' => 'sponsor_logo_gold',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '150',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_platinum' => array(
      'presetname' => 'sponsor_logo_platinum',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '200',
            'height' => '',
          ),
        ),
      ),
    ),
    'sponsor_logo_silver' => array(
      'presetname' => 'sponsor_logo_silver',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '125',
            'height' => '',
          ),
        ),
      ),
    ),
  );
  return $items;
}

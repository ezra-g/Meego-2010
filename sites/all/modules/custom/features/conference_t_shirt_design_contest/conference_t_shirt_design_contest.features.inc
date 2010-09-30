<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function conference_t_shirt_design_contest_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function conference_t_shirt_design_contest_flag_default_flags() {
$flags = array();
// Exported flag: "T-Shirt Vote".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'tshirt_vote',
  'title' => 'T-Shirt Vote',
  'global' => '0',
  'types' => 
  array (
    0 => 'tshirt_design',
  ),
  'flag_short' => 'Vote for this t-shirt! ([flag-tshirt-vote-count])',
  'flag_long' => '',
  'flag_message' => '',
  'unflag_short' => 'Remove vote for this t-shirt! ([flag-tshirt-vote-count])',
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
  'show_on_teaser' => 0,
  'show_on_form' => 0,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'conference_t_shirt_design_contest',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
return $flags;
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function conference_t_shirt_design_contest_imagecache_default_presets() {
  $items = array(
    'tshirt_grid_view' => array(
      'presetname' => 'tshirt_grid_view',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_sharpen',
          'data' => array(
            'radius' => '0.5',
            'sigma' => '0.5',
            'amount' => '100',
            'threshold' => '0.05',
          ),
        ),
      ),
    ),
    'tshirt_node_view' => array(
      'presetname' => 'tshirt_node_view',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '450',
            'height' => '',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_sharpen',
          'data' => array(
            'radius' => '0.5',
            'sigma' => '0.5',
            'amount' => '100',
            'threshold' => '0.05',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function conference_t_shirt_design_contest_node_info() {
  $items = array(
    'tshirt_design' => array(
      'name' => t('T-Shirt Design'),
      'module' => 'features',
      'description' => t('Submit a MeeGo Conference T-Shirt Design. '),
      'has_title' => '1',
      'title_label' => t('Title of Design'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('Fill in all the form fields below to have your t-shirt design considered for the MeeGo Conference 2010 in Dublin, Ireland. '),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function conference_t_shirt_design_contest_views_api() {
  return array(
    'api' => '2',
  );
}

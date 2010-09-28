<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_session_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function cod_session_flag_default_flags() {
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
  'flag_short' => 'Add to my agenda',
  'flag_long' => 'Add this session to your agenda to organize your session attendance.',
  'flag_message' => '',
  'unflag_short' => 'Remove from my agenda',
  'unflag_long' => 'Remove this session from your agenda.',
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
  'show_on_page' => 0,
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
      0 => 3,
    ),
    'unflag' => 
    array (
      0 => 3,
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
 * Implementation of hook_node_info().
 */
function cod_session_node_info() {
  $items = array(
    'room' => array(
      'name' => t('Room'),
      'module' => 'features',
      'description' => t('Rooms provide a location for each session.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'schedule_item' => array(
      'name' => t('Schedule Item'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'session' => array(
      'name' => t('Session'),
      'module' => 'features',
      'description' => t('Use this content type to propose sessions at the event. Users can vote on proposed sessions and add sessions to their individual session agendas.'),
      'has_title' => '1',
      'title_label' => t('Session Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => t('We want to encourage both commercial developers, OEMs or interested end users as 
well as the open source community behind MeeGo to get together and share three
days of presentations, discussions and showcases for products or ideas.

If you have questions about submitting a session, please refer to the <a href="/program/call-session-proposals">Call for Session Proposals</a> description.

In general we are not soliciting sales pitches, but it is ok for technical presentations to refer to (or announce)
MeeGo related products.
'),
    ),
    'time_slot' => array(
      'name' => t('Time slot'),
      'module' => 'features',
      'description' => t('Use time slots to define when sessions will occur.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cod_session_views_api() {
  return array(
    'api' => '2',
  );
}

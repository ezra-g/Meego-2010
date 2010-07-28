<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _cod_session_node_info() {
  $items = array(
    'session' => array(
      'name' => t('Session'),
      'module' => 'features',
      'description' => t('Use this content type to propose sessions at the event. Users can vote on proposed sessions and add sessions to their individual session agendas.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Session description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

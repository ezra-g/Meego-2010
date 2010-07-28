<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _cod_front_page_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'context_ui',
    'attribute' => 'section',
    'value' => 'front',
    'description' => 'Front Page',
    'path' => array(
      '<front>' => '<front>',
    ),
    'block' => array(
      'views_Sponsors-block_4' => array(
        'module' => 'views',
        'delta' => 'Sponsors-block_4',
        'weight' => 19,
        'region' => 'right',
        'status' => '0',
        'label' => 'Sponsors: Home Page Platinum Featured',
        'type' => 'context_ui',
      ),
      'views_attendees-block_1' => array(
        'module' => 'views',
        'delta' => 'attendees-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Attendee block',
        'type' => 'context_ui',
      ),
      'views_featured_sessions-block_1' => array(
        'module' => 'views',
        'delta' => 'featured_sessions-block_1',
        'weight' => 19,
        'region' => 'content',
        'status' => '0',
        'label' => 'featured_sessions: Featured Sessions',
        'type' => 'context_ui',
      ),
      'views_news-block_1' => array(
        'module' => 'views',
        'delta' => 'news-block_1',
        'weight' => 20,
        'region' => 'content',
        'status' => '0',
        'label' => 'news: Single news item block',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

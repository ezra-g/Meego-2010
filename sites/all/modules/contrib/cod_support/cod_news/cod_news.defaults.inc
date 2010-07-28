<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _cod_news_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'cod_support',
    'attribute' => 'news',
    'value' => 'news',
    'description' => '',
    'sitewide' => '1',
    'block' => array(
      'views_news-block_2' => array(
        'module' => 'views',
        'delta' => 'news-block_2',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'news: Multi news item block',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

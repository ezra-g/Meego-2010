<?php

/**
 * Implementation of hook_node_info().
 */
function cod_news_node_info() {
  module_load_include('inc', 'cod_news', 'cod_news.features.node');
  $args = func_get_args();
  return call_user_func_array('_cod_news_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function cod_news_views_default_views() {
  module_load_include('inc', 'cod_news', 'cod_news.features.views');
  $args = func_get_args();
  return call_user_func_array('_cod_news_views_default_views', $args);
}

<?php

/**
 * Implementation of hook_content_default_fields().
 */
function cod_sponsors_content_default_fields() {
  module_load_include('inc', 'cod_sponsors', 'cod_sponsors.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_sponsors_content_default_fields', $args);
}

/**
 * Implementation of hook_context_default_contexts().
 */
function cod_sponsors_context_default_contexts() {
  module_load_include('inc', 'cod_sponsors', 'cod_sponsors.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_sponsors_context_default_contexts', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function cod_sponsors_imagecache_default_presets() {
  module_load_include('inc', 'cod_sponsors', 'cod_sponsors.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_sponsors_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function cod_sponsors_node_info() {
  module_load_include('inc', 'cod_sponsors', 'cod_sponsors.features.node');
  $args = func_get_args();
  return call_user_func_array('_cod_sponsors_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function cod_sponsors_views_default_views() {
  module_load_include('inc', 'cod_sponsors', 'cod_sponsors.features.views');
  $args = func_get_args();
  return call_user_func_array('_cod_sponsors_views_default_views', $args);
}

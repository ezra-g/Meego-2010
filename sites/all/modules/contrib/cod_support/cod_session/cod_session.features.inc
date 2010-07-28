<?php

/**
 * Implementation of hook_content_default_fields().
 */
function cod_session_content_default_fields() {
  module_load_include('inc', 'cod_session', 'cod_session.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_session_content_default_fields', $args);
}

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function cod_session_fieldgroup_default_groups() {
  module_load_include('inc', 'cod_session', 'cod_session.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_session_fieldgroup_default_groups', $args);
}

/**
 * Implementation of hook_flag_default_flags().
 */
function cod_session_flag_default_flags() {
  module_load_include('inc', 'cod_session', 'cod_session.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_session_flag_default_flags', $args);
}

/**
 * Implementation of hook_node_info().
 */
function cod_session_node_info() {
  module_load_include('inc', 'cod_session', 'cod_session.features.node');
  $args = func_get_args();
  return call_user_func_array('_cod_session_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_session_user_default_permissions() {
  module_load_include('inc', 'cod_session', 'cod_session.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_session_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function cod_session_views_default_views() {
  module_load_include('inc', 'cod_session', 'cod_session.features.views');
  $args = func_get_args();
  return call_user_func_array('_cod_session_views_default_views', $args);
}

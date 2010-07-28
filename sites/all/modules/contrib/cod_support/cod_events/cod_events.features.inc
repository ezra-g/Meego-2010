<?php

/**
 * Implementation of hook_content_default_fields().
 */
function cod_events_content_default_fields() {
  module_load_include('inc', 'cod_events', 'cod_events.defaults');
  $args = func_get_args();
  return call_user_func_array('_cod_events_content_default_fields', $args);
}

<?php

/**
 * Implementation of hook_views_default_views().
 */
function cod_attendees_views_default_views() {
  module_load_include('inc', 'cod_attendees', 'cod_attendees.features.views');
  $args = func_get_args();
  return call_user_func_array('_cod_attendees_views_default_views', $args);
}

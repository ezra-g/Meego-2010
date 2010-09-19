<?php
/**
 * @file
 * Views hooks for cod_session feature
 */

/**
 * Implementation of hook_views_plugins().
 */
function cod_session_views_plugins() {
  return array(
    'style' => array(
      'cod_session_calendar' => array(
        'title' => t('Session calendar'),
        'help' => t('Display view as a table with room columns and time slot rows'),
        'handler' => 'cod_session_views_style_plugin_calendar',
        'theme' => 'cod_session_calendar',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'use sort' => FALSE,
        'use pager' => FALSE, 
        'use ajax' => FALSE, 
        'use more' => FALSE, 
        'type' => 'normal',
        'help topic' => 'style-unformatted',        
        ),
      ),
    );
}



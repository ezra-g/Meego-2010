<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function cod_session_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'session-nodes';
  $context->description = 'Settings for session specific nodes.';
  $context->tag = 'Node View';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'session' => 'session',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-sessions-block_1' => array(
          'module' => 'views',
          'delta' => 'sessions-block_1',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
        'views-sessions-block_2' => array(
          'module' => 'views',
          'delta' => 'sessions-block_2',
          'region' => 'sidebar_first',
          'weight' => 2,
        ),
      ),
    ),
    'breadcrumb' => 'program/sessions',
    'menu' => 'program/sessions',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node View');
  t('Settings for session specific nodes.');

  $export['session-nodes'] = $context;
  return $export;
}

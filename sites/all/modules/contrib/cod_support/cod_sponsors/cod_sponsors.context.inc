<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function cod_sponsors_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_ui-section-sponsors';
  $context->description = 'Sponsors page';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'sponsor' => 'sponsor',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'sponsors*' => 'sponsors*',
      ),
    ),
    'views' => array(
      'values' => array(
        'Sponsors' => 'Sponsors',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'sponsors',
    'menu' => 'sponsors',
    'theme' => array(
      'title' => '',
      'subtitle' => '',
      'class' => 'context-section-sponsors',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sponsors page');

  $export['context_ui-section-sponsors'] = $context;
  return $export;
}

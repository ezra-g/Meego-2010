<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function conference_t_shirt_design_contest_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tshirt-designs';
  $context->description = 'T-Shirt Designs context.';
  $context->tag = 'Special';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'tshirt_design' => 'tshirt_design',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'tshirt-designs' => 'tshirt-designs',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-12' => array(
          'module' => 'block',
          'delta' => 12,
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'block-13' => array(
          'module' => 'block',
          'delta' => 13,
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
      ),
    ),
    'breadcrumb' => 'tshirt-designs',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Special');
  t('T-Shirt Designs context.');

  $export['tshirt-designs'] = $context;
  return $export;
}

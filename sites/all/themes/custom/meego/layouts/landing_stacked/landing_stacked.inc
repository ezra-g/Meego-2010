<?php
// $Id: two_sidebars.inc,v 1.1.2.1 2009/12/12 15:31:55 johnalbin Exp $

/**
 * Implements hook_panels_layouts().
 */
function meego_landing_stacked_panels_layouts() {
  $items['landing_stacked'] = array(
    'title' => t('Meego Layout: Landing Stacked'),
    'icon' => 'landing-stacked.png',
    'theme' => 'meego_landing_stacked',
    'admin theme' => 'meego_landing_stacked_admin',
    'css' => 'landing-stacked.css',
    'admin css' => 'landing-stacked-admin.css',    
    'panels' => array(
      'top_left' => t('Top Left'),
      'top_right' => t('Top Right'),
      'mid_left' => t('Mid Left'),
			'mid_right' => t('Mid Right'),
			'bottom' => t('Bottom'),
    ),
  );

  return $items;
}

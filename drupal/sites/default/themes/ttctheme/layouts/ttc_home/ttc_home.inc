<?php

/**
 * Implements hook_panels_layouts()
 */
function ttctheme_ttc_home_panels_layouts() {
  $items['ttc_home'] = array(
    'title' => t('TTC: Homepage'),
    'category' => t('TTC'),
    'icon' => 'ttc_home.png',
    'theme' => 'ttc_home',
    'regions' => array(
      'top' => t('Top'),
      'middle' => t('Middle'),
      'bottom' => t('Bottom')
    )
  );
  return $items;
}


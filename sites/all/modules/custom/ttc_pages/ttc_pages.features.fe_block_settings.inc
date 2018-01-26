<?php
/**
 * @file
 * ttc_pages.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ttc_pages_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['panels_mini-ttc_abstract_faceted_search_mini'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ttc_abstract_faceted_search_mini',
    'module' => 'panels_mini',
    'node_types' => array(
      0 => 'abstract',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'ttcadmin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ttcadmin',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

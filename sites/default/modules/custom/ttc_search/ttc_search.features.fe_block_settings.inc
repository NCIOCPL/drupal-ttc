<?php
/**
 * @file
 * ttc_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ttc_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['current_search-current_abstract_faceted_search'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'current_abstract_faceted_search',
    'module' => 'current_search',
    'node_types' => array(),
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
        'region' => '',
        'status' => 0,
        'theme' => 'ttctheme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

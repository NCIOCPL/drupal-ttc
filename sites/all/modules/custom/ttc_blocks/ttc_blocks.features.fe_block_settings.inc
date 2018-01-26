<?php
/**
 * @file
 * ttc_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ttc_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-listserv_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'listserv_block',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'home
availabletechnologies',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'ttcadmin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ttcadmin',
        'weight' => 10,
      ),
      'ttctheme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}

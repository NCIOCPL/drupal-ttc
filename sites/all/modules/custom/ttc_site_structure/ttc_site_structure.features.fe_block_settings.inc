<?php
/**
 * @file
 * ttc_site_structure.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ttc_site_structure_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-site-structure'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-site-structure',
    'module' => 'menu',
    'node_types' => array(
      0 => 'page',
      1 => 'success_story',
    ),
    'pages' => 'sitemap
accessdenied
pagenotfound',
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
        'weight' => -18,
      ),
      'ttctheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -18,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}

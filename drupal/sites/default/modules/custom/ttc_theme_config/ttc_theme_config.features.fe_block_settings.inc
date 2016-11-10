<?php
/**
 * @file
 * ttc_theme_config.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ttc_theme_config_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-follow_us_footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'follow_us_footer',
    'module' => 'block',
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
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-follow_us_header'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'follow_us_header',
    'module' => 'block',
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
      'ttctheme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-logo_footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'logo_footer',
    'module' => 'block',
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
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -12,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-logo_header'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'logo_header',
    'module' => 'block',
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
      'ttctheme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -12,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-tagline'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'tagline',
    'module' => 'block',
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
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -8,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu--primary'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu--primary',
    'module' => 'menu',
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
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -10,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu--secondary'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu--secondary',
    'module' => 'menu',
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
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -9,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
      ),
      'ttctheme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
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
      'ttctheme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(
      0 => 'page',
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

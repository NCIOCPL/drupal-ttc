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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -11,
      ),
      'zurb_foundation' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zurb_foundation',
        'weight' => 0,
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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -11,
      ),
      'zurb_foundation' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zurb_foundation',
        'weight' => 0,
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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -12,
      ),
      'zurb_foundation' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zurb_foundation',
        'weight' => 0,
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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -12,
      ),
      'zurb_foundation' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zurb_foundation',
        'weight' => 0,
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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -8,
      ),
      'zurb_foundation' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zurb_foundation',
        'weight' => 0,
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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -10,
      ),
      'zurb_foundation' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zurb_foundation',
        'weight' => 0,
      ),
    ),
    'title' => '',
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
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ttctheme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ttctheme',
        'weight' => -9,
      ),
      'zurb_foundation' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'zurb_foundation',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}

<?php
/**
 * @file
 * ttc_site_structure.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ttc_site_structure_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_append_node_title';
  $strongarm->value = 0;
  $export['menu_breadcrumb_append_node_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_append_node_url';
  $strongarm->value = 0;
  $export['menu_breadcrumb_append_node_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_determine_menu';
  $strongarm->value = 1;
  $export['menu_breadcrumb_determine_menu'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_hide_on_single_item';
  $strongarm->value = 0;
  $export['menu_breadcrumb_hide_on_single_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_menus';
  $strongarm->value = array(
    'menu-site-structure' => array(
      'enabled' => 1,
      'weight' => '-11',
      'type' => 'menu',
      'title' => 'Site Structure',
      'name' => 'menu-site-structure',
    ),
    'main-menu' => array(
      'enabled' => 0,
      'weight' => '-10',
      'type' => 'menu',
      'title' => 'Main menu',
      'name' => 'main-menu',
    ),
    'management' => array(
      'enabled' => 0,
      'weight' => '-9',
      'type' => 'menu',
      'title' => 'Management',
      'name' => 'management',
    ),
    'menu-footer-menu--primary' => array(
      'enabled' => 0,
      'weight' => '-8',
      'type' => 'menu',
      'title' => 'Footer Menu (primary)',
      'name' => 'menu-footer-menu--primary',
    ),
    'menu-footer-menu--secondary' => array(
      'enabled' => 0,
      'weight' => '-7',
      'type' => 'menu',
      'title' => 'Footer Menu (secondary)',
      'name' => 'menu-footer-menu--secondary',
    ),
    'menu-information' => array(
      'enabled' => 0,
      'weight' => '-6',
      'type' => 'menu',
      'title' => 'Information For',
      'name' => 'menu-information',
    ),
    'menu_breadcrumb_default_menu' => array(
      'enabled' => 0,
      'weight' => '-5',
      'type' => 'menu_breadcrumb_default_menu',
      'title' => 'menu_breadcrumb_default_menu',
      'name' => 'menu_breadcrumb_default_menu',
    ),
    'navigation' => array(
      'enabled' => 0,
      'weight' => '-4',
      'type' => 'menu',
      'title' => 'Navigation',
      'name' => 'navigation',
    ),
    'shortcut-set-1' => array(
      'enabled' => 0,
      'weight' => '-3',
      'type' => 'menu',
      'title' => 'shortcut-set-1',
      'name' => 'shortcut-set-1',
    ),
    'user-menu' => array(
      'enabled' => 0,
      'weight' => '-2',
      'type' => 'menu',
      'title' => 'User menu',
      'name' => 'user-menu',
    ),
  );
  $export['menu_breadcrumb_menus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_menu_patterns';
  $strongarm->value = '/^book-toc-\\d+$/Books/';
  $export['menu_breadcrumb_menu_patterns'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_no_menu_use_menu_path';
  $strongarm->value = 1;
  $export['menu_breadcrumb_no_menu_use_menu_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_pattern_matches_rebuild';
  $strongarm->value = FALSE;
  $export['menu_breadcrumb_pattern_matches_rebuild'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_breadcrumb_remove_home_link';
  $strongarm->value = 0;
  $export['menu_breadcrumb_remove_home_link'] = $strongarm;

  return $export;
}

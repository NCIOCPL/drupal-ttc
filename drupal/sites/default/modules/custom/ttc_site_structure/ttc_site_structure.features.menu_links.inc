<?php
/**
 * @file
 * ttc_site_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ttc_site_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_home:home.
  $menu_links['main-menu_home:home'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:home',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');

  return $menu_links;
}

<?php
/**
 * @file
 * ttc_theme_config.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ttc_theme_config_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer-menu--primary.
  $menus['menu-footer-menu--primary'] = array(
    'menu_name' => 'menu-footer-menu--primary',
    'title' => 'Footer Menu (primary)',
    'description' => '',
  );
  // Exported menu: menu-footer-menu--secondary.
  $menus['menu-footer-menu--secondary'] = array(
    'menu_name' => 'menu-footer-menu--secondary',
    'title' => 'Footer Menu (secondary)',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Menu (primary)');
  t('Footer Menu (secondary)');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}

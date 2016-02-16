<?php
/**
 * @file
 * ttc_user_config.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function ttc_user_config_filter_default_formats() {
  $formats = array();

  // Exported format: PHP code.
  $formats['php_code'] = array(
    'format' => 'php_code',
    'name' => 'PHP code',
    'cache' => 1,
    'status' => 1,
    'weight' => 11,
    'filters' => array(),
  );

  return $formats;
}

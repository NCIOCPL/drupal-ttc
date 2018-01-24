<?php
/**
 * @file
 * ttc_user_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ttc_user_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "config_perms" && $api == "config_perms") {
    return array("version" => "1");
  }
}

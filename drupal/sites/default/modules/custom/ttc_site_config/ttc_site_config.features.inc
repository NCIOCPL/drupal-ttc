<?php
/**
 * @file
 * ttc_site_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ttc_site_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

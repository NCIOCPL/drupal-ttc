<?php
/**
 * @file
 * nci_wysiwyg_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nci_wysiwyg_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

<?php
/**
 * @file
 * ttc_content_type_file.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ttc_content_type_file_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ttc_content_type_file_node_info() {
  $items = array(
    'file' => array(
      'name' => t('File'),
      'base' => 'node_content',
      'description' => t('An uploaded item - such as a PDF or .jpg file - with a description.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

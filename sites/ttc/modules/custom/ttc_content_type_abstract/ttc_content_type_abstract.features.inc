<?php
/**
 * @file
 * ttc_content_type_abstract.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ttc_content_type_abstract_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ttc_content_type_abstract_node_info() {
  $items = array(
    'abstract' => array(
      'name' => t('Abstract'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Opportunity Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

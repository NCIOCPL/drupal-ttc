<?php
/**
 * @file
 * ttc_content_type_success_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ttc_content_type_success_story_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ttc_content_type_success_story_node_info() {
  $items = array(
    'success_story' => array(
      'name' => t('Success Story'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

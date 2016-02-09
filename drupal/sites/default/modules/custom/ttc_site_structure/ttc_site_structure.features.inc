<?php
/**
 * @file
 * ttc_site_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ttc_site_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function ttc_site_structure_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_inventors_technologies
  $nodequeues['featured_inventors_technologies'] = array(
    'name' => 'featured_inventors_technologies',
    'title' => 'Featured Inventors & Technologies',
    'subqueue_title' => '',
    'size' => 3,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 1,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'abstract',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

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

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function ttc_site_config_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['j M Y'] = 'j M Y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function ttc_site_config_date_format_types() {
  $format_types = array();
  // Exported date format type: brief_date
  $format_types['brief_date'] = 'Brief Date';
  return $format_types;
}

/**
 * Implements hook_image_default_styles().
 */
function ttc_site_config_image_default_styles() {
  $styles = array();

  // Exported image style: abstract_search_result.
  $styles['abstract_search_result'] = array(
    'label' => 'Abstract Search Result',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 225,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

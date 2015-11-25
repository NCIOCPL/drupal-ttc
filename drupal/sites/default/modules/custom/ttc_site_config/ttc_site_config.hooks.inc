<?php
/**
 * @file
 * ttc_site_config.hooks.inc
 */

/**
* Implements hook_wysiwyg_editor_settings_alter()
*/
function ttc_site_config_wysiwyg_editor_settings_alter(&$settings, $context) {
  // Check that the editor being used is CKEditor
  if ($context['profile']->editor == 'ckeditor') {
    // Set CKEditor to use the TTC theme
    $settings['contentsCss'] = array(
      base_path() . drupal_get_path('theme', 'ttctheme') . '/public/css/ttctheme.css'
    );
  }
}

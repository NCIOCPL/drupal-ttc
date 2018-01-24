<?php
/**
 * @file
 * nci_wysiwyg_config.hooks.inc
 */

/**
* Implements hook_wysiwyg_editor_settings_alter()
*/
function nci_wysiwyg_config_wysiwyg_editor_settings_alter(&$settings, $context) {
  $base_module_path = base_path() . drupal_get_path('module', 'nci_wysiwyg_config');

  // Check that the editor being used is CKEditor
  if ($context['profile']->editor == 'ckeditor') {
    // Specify the custom config file for CKEditor
    $settings['customConfig'] = $base_module_path . '/nci_ckeditor_config.js';
  }
}

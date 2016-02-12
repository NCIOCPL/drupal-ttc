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

function ttc_site_config_form_system_site_information_settings_alter(&$form, &$form_state, $form_id) {
  $disclaimer_default_text = 'This site is undergoing remediation for compliance with Section 508. ' .
      'The remediation will be complete by April 30, 2016. In the interim, ' . 
      'should you require any accessibility assistance with any content, ' . 
      'please contact the NCI Technology Transfer team at [use the tech transfer ' . 
      'email here]. Thank you!';
  
  $form['hhs_disclaimer'] = array(
    '#type' => 'fieldset',
    '#title' => 'HHS Disclaimer',
  );
  $form['hhs_disclaimer']['show_hhs_disclaimer'] = array(
    '#type' => 'checkbox',
    '#title' => 'Show Disclaimer',
    '#default_value' => variable_get('show_hhs_disclaimer', TRUE),
  );
  $form['hhs_disclaimer']['site_hhs_disclaimer'] = array(
    '#type' => 'text_format',
    '#title' => 'Disclaimer Text',
    '#default_value' => variable_get('site_hhs_disclaimer', $disclaimer_default_text)['value'],
  );
}

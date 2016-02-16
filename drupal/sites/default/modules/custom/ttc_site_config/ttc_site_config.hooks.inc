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

/**
 * Implementation of hook_field_widget_form_alter().
 *
 * Add WYSIWYG treatment to textarea summary form items.
 */
function ttc_site_config_field_widget_form_alter(&$element, &$form_state, $context) {
  if (!isset($element['summary'])) {
    return;
  }

  drupal_add_css(drupal_get_path('module', 'MY_MODULE') . '/assets/textarea-summary.css');
  drupal_add_js(drupal_get_path('module', 'MY_MODULE') . '/assets/textarea-summary.js');
  $element['summary']['#type'] = 'text_format';
  $element['summary']['#format'] = $element['#format'];
}

/**
 * Implements hook_field_attach_presave().
 */
function ttc_site_config_field_attach_presave($entity_type, $entity) {
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

  foreach (field_info_instances($entity_type, $bundle) as $instance) {
    $field = field_info_field_by_id($instance['field_id']);
    $field_name = $field['field_name'];
    if ($field['type'] !== 'text_with_summary' || empty($entity->$field_name)) {
      continue;
    }

    $language = isset($entity->language) ? $entity->language : LANGUAGE_NONE;
    foreach ($entity->{$field_name}[$language] as $id => &$value) {
      if (!is_array($value['summary'])) {
        continue;
      }

      $value['summary'] = $value['summary']['value'];
    }
  }
}

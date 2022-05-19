<?php

/**
 * @file
 * ttc_taxonomy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ttc_taxonomy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__contacts';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'description' => array(
          'default' => array(
            'visible' => FALSE,
            'weight' => '4',
          ),
        ),
      ),
      'form' => array(
        'description' => array(
          'weight' => '1',
        ),
        'name' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '15',
        ),
        'redirect' => array(
          'weight' => '16',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__contacts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_contacts_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_contacts_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_development_stage_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_development_stage_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_letterheads_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_letterheads_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_patent_status_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_patent_status_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_product_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_product_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_send_to_email_addresses_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_send_to_email_addresses_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_therapeutic_area_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_therapeutic_area_pattern'] = $strongarm;

  return $export;
}

<?php
/**
 * @file
 * ttc_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ttc_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'contacts' => array(
      'name' => 'Contacts',
      'machine_name' => 'contacts',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'development_stage' => array(
      'name' => 'Development Stage',
      'machine_name' => 'development_stage',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'letterheads' => array(
      'name' => 'PDF Letterheads',
      'machine_name' => 'letterheads',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'patent_status' => array(
      'name' => 'Patent Status',
      'machine_name' => 'patent_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -7,
    ),
    'product_type' => array(
      'name' => 'Product Type',
      'machine_name' => 'product_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
    'send_to_email_addresses' => array(
      'name' => 'Send-To Email Addresses',
      'machine_name' => 'send_to_email_addresses',
      'description' => 'A list of all email addresses available for the \'Send To\' field.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'therapeutic_area' => array(
      'name' => 'Therapeutic Area',
      'machine_name' => 'therapeutic_area',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
    ),
  );
}

<?php
/**
 * @file
 * ttc_user_config.config_perms.inc
 */

/**
 * Implements hook_config_perms().
 */
function ttc_user_config_config_perms() {
  $export = array();

  $config_perms = new stdClass();
  $config_perms->disabled = FALSE; /* Edit this to true to make a default config_perms disabled initially */
  $config_perms->api_version = 1;
  $config_perms->machine_name = 'access_generate_pdf_path';
  $config_perms->status = TRUE;
  $config_perms->name = 'access generate pdf path';
  $config_perms->path = array(
    0 => 'pdf/*',
  );
  $export['access_generate_pdf_path'] = $config_perms;

  return $export;
}

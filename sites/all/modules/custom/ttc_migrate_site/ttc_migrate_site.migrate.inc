<?php

/**
 * @file
 * Declares TTC site migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function ttc_migrate_site_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'site' => array(
        'title' => t('TTC Site Migrations'),
      ),
    ),
    'migrations' => array(
      'TTCSiteAbstract' => array(
        'class_name' => 'TTCMigrateSiteAbstractMigration',
        'group_name' => 'site',
      ),
      'TTCSiteAbstractPatentStatus' => array(
        'class_name' => 'TTCMigrateSiteAbstractPatentStatusMigration',
        'group_name' => 'site',
      ),
    ),
  );
  return $api;
}

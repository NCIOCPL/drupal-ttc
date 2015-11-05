<?php
/**
 * @file
 * ttc_user_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ttc_user_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create abstract content'.
  $permissions['create abstract content'] = array(
    'name' => 'create abstract content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any abstract content'.
  $permissions['delete any abstract content'] = array(
    'name' => 'delete any abstract content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own abstract content'.
  $permissions['delete own abstract content'] = array(
    'name' => 'delete own abstract content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in contacts'.
  $permissions['delete terms in contacts'] = array(
    'name' => 'delete terms in contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in development_stage'.
  $permissions['delete terms in development_stage'] = array(
    'name' => 'delete terms in development_stage',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in letterheads'.
  $permissions['delete terms in letterheads'] = array(
    'name' => 'delete terms in letterheads',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in patent_status'.
  $permissions['delete terms in patent_status'] = array(
    'name' => 'delete terms in patent_status',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in product_type'.
  $permissions['delete terms in product_type'] = array(
    'name' => 'delete terms in product_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in send_to_email_addresses'.
  $permissions['delete terms in send_to_email_addresses'] = array(
    'name' => 'delete terms in send_to_email_addresses',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in therapeutic_area'.
  $permissions['delete terms in therapeutic_area'] = array(
    'name' => 'delete terms in therapeutic_area',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any abstract content'.
  $permissions['edit any abstract content'] = array(
    'name' => 'edit any abstract content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own abstract content'.
  $permissions['edit own abstract content'] = array(
    'name' => 'edit own abstract content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in contacts'.
  $permissions['edit terms in contacts'] = array(
    'name' => 'edit terms in contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in development_stage'.
  $permissions['edit terms in development_stage'] = array(
    'name' => 'edit terms in development_stage',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in letterheads'.
  $permissions['edit terms in letterheads'] = array(
    'name' => 'edit terms in letterheads',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in patent_status'.
  $permissions['edit terms in patent_status'] = array(
    'name' => 'edit terms in patent_status',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in product_type'.
  $permissions['edit terms in product_type'] = array(
    'name' => 'edit terms in product_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in send_to_email_addresses'.
  $permissions['edit terms in send_to_email_addresses'] = array(
    'name' => 'edit terms in send_to_email_addresses',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in therapeutic_area'.
  $permissions['edit terms in therapeutic_area'] = array(
    'name' => 'edit terms in therapeutic_area',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}

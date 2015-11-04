<?php
/**
 * @file
 * nci_user_config.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nci_user_config_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: advanced content editor.
  $roles['advanced content editor'] = array(
    'name' => 'advanced content editor',
    'weight' => 6,
  );

  // Exported role: content author.
  $roles['content author'] = array(
    'name' => 'content author',
    'weight' => 3,
  );

  // Exported role: content editor.
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => 4,
  );

  // Exported role: site manager.
  $roles['site manager'] = array(
    'name' => 'site manager',
    'weight' => 7,
  );

  // Exported role: site moderator.
  $roles['site moderator'] = array(
    'name' => 'site moderator',
    'weight' => 5,
  );

  return $roles;
}

<?php
/**
 * @file
 * ttc_site_structure.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ttc_site_structure_user_default_roles() {
  $roles = array();

  // Exported role: advanced content editor.
  $roles['advanced content editor'] = array(
    'name' => 'advanced content editor',
    'weight' => 6,
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

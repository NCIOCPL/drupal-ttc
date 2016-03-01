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

  // Exported permission: 'access generate pdf path'.
  $permissions['access generate pdf path'] = array(
    'name' => 'access generate pdf path',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer contacts vocabulary terms'.
  $permissions['administer contacts vocabulary terms'] = array(
    'name' => 'administer contacts vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer development_stage vocabulary terms'.
  $permissions['administer development_stage vocabulary terms'] = array(
    'name' => 'administer development_stage vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer features menu items'.
  $permissions['administer features menu items'] = array(
    'name' => 'administer features menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer letterheads vocabulary terms'.
  $permissions['administer letterheads vocabulary terms'] = array(
    'name' => 'administer letterheads vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer main-menu menu items'.
  $permissions['administer main-menu menu items'] = array(
    'name' => 'administer main-menu menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer management menu items'.
  $permissions['administer management menu items'] = array(
    'name' => 'administer management menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-footer-menu--primary menu items'.
  $permissions['administer menu-footer-menu--primary menu items'] = array(
    'name' => 'administer menu-footer-menu--primary menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-footer-menu--secondary menu items'.
  $permissions['administer menu-footer-menu--secondary menu items'] = array(
    'name' => 'administer menu-footer-menu--secondary menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-information menu items'.
  $permissions['administer menu-information menu items'] = array(
    'name' => 'administer menu-information menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-site-structure menu items'.
  $permissions['administer menu-site-structure menu items'] = array(
    'name' => 'administer menu-site-structure menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer mpdf settings'.
  $permissions['administer mpdf settings'] = array(
    'name' => 'administer mpdf settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pdf_using_mpdf',
  );

  // Exported permission: 'administer navigation menu items'.
  $permissions['administer navigation menu items'] = array(
    'name' => 'administer navigation menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'administer patent_status vocabulary terms'.
  $permissions['administer patent_status vocabulary terms'] = array(
    'name' => 'administer patent_status vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer product_type vocabulary terms'.
  $permissions['administer product_type vocabulary terms'] = array(
    'name' => 'administer product_type vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer send_to_email_addresses vocabulary terms'.
  $permissions['administer send_to_email_addresses vocabulary terms'] = array(
    'name' => 'administer send_to_email_addresses vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer therapeutic_area vocabulary terms'.
  $permissions['administer therapeutic_area vocabulary terms'] = array(
    'name' => 'administer therapeutic_area vocabulary terms',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer user-menu menu items'.
  $permissions['administer user-menu menu items'] = array(
    'name' => 'administer user-menu menu items',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'create abstract content'.
  $permissions['create abstract content'] = array(
    'name' => 'create abstract content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create news_announcement content'.
  $permissions['create news_announcement content'] = array(
    'name' => 'create news_announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create success_story content'.
  $permissions['create success_story content'] = array(
    'name' => 'create success_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any abstract content'.
  $permissions['delete any abstract content'] = array(
    'name' => 'delete any abstract content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news_announcement content'.
  $permissions['delete any news_announcement content'] = array(
    'name' => 'delete any news_announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any success_story content'.
  $permissions['delete any success_story content'] = array(
    'name' => 'delete any success_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own abstract content'.
  $permissions['delete own abstract content'] = array(
    'name' => 'delete own abstract content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news_announcement content'.
  $permissions['delete own news_announcement content'] = array(
    'name' => 'delete own news_announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own success_story content'.
  $permissions['delete own success_story content'] = array(
    'name' => 'delete own success_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
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
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news_announcement content'.
  $permissions['edit any news_announcement content'] = array(
    'name' => 'edit any news_announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any success_story content'.
  $permissions['edit any success_story content'] = array(
    'name' => 'edit any success_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own abstract content'.
  $permissions['edit own abstract content'] = array(
    'name' => 'edit own abstract content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news_announcement content'.
  $permissions['edit own news_announcement content'] = array(
    'name' => 'edit own news_announcement content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own success_story content'.
  $permissions['edit own success_story content'] = array(
    'name' => 'edit own success_story content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
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

  // Exported permission: 'generate pdf using mpdf'.
  $permissions['generate pdf using mpdf'] = array(
    'name' => 'generate pdf using mpdf',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'pdf_using_mpdf',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'authenticated user' => 'authenticated user',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'filter',
  );

  return $permissions;
}

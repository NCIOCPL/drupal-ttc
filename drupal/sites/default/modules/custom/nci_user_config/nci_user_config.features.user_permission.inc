<?php
/**
 * @file
 * nci_user_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nci_user_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
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

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access statistics'.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer account settings'.
  $permissions['administer account settings'] = array(
    'name' => 'administer account settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer clean-urls'.
  $permissions['administer clean-urls'] = array(
    'name' => 'administer clean-urls',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer custom permissions'.
  $permissions['administer custom permissions'] = array(
    'name' => 'administer custom permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer date-time'.
  $permissions['administer date-time'] = array(
    'name' => 'administer date-time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer error reporting'.
  $permissions['administer error reporting'] = array(
    'name' => 'administer error reporting',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer file system'.
  $permissions['administer file system'] = array(
    'name' => 'administer file system',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer performance'.
  $permissions['administer performance'] = array(
    'name' => 'administer performance',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer recaptcha'.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer site information'.
  $permissions['administer site information'] = array(
    'name' => 'administer site information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer site maintenance'.
  $permissions['administer site maintenance'] = array(
    'name' => 'administer site maintenance',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer statistics'.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'assign advanced content editor role'.
  $permissions['assign advanced content editor role'] = array(
    'name' => 'assign advanced content editor role',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign content author role'.
  $permissions['assign content author role'] = array(
    'name' => 'assign content author role',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign content editor role'.
  $permissions['assign content editor role'] = array(
    'name' => 'assign content editor role',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign site manager role'.
  $permissions['assign site manager role'] = array(
    'name' => 'assign site manager role',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign site moderator role'.
  $permissions['assign site moderator role'] = array(
    'name' => 'assign site moderator role',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
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

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'display site configuration menu'.
  $permissions['display site configuration menu'] = array(
    'name' => 'display site configuration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'display site reports menu'.
  $permissions['display site reports menu'] = array(
    'name' => 'display site reports menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'display site structure menu'.
  $permissions['display site structure menu'] = array(
    'name' => 'display site structure menu',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site moderator' => 'site moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
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

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to archived'.
  $permissions['moderate content from published to archived'] = array(
    'name' => 'moderate content from published to archived',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
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

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
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

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view post access counter'.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
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

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced content editor' => 'advanced content editor',
      'content author' => 'content author',
      'content editor' => 'content editor',
      'site manager' => 'site manager',
      'site moderator' => 'site moderator',
    ),
    'module' => 'system',
  );

  return $permissions;
}

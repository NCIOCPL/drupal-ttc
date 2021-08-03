<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function nci_user_roles_drush_command() {
    $items = array();

    $items['user-roles-permissions-refresh'] = array(
        'description' => "Refreshes the assigned user roles with up-to-date permissions.",
        'examples' => array(
            'drush user-roles-permissions-refresh' => 'Queries all enabled modules and sets the descovered user role permissions.',
        ),
        'aliases' => array('urpr'),
        //'bootstrap' => DRUPAL_BOOTSTRAP_FULL, 
        'drupal dependencies' => array('nci_user_roles'),
    );

    return $items;
}

function drush_nci_user_roles_user_roles_permissions_refresh() {
    require_once 'nci_user_roles.install';
    drupal_set_message("Refreshing user role permissions:");
    nci_user_roles_set_permissions(TRUE);
}
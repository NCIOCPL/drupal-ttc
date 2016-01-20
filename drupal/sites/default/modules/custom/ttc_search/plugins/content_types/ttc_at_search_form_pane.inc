<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
$plugin = array(
    'single' => TRUE, // Just do this one, it is needed.
    'title' => t('TTC Available Technologies Search Form Pane'), // Title to show up on the pane screen.
    'description' => t('Search Box for Available Technologies. Redirects to availabletechnologies/* by default, but can be configured.'), // Description to show up on the pane screen.
    'category' => t('TTC Search'), // A category to put this under
    //'admin info' => 'mynci_search_form_pane_admin_info', // A function that will return the information displayed on the admin screen (optional).
    'edit form' => 'ttc_at_search_form_pane_edit_form', // A function that will return the settings form for the pane.
    'render callback' => 'ttc_at_search_form_pane_render', // A function that will return the renderable content
    //'required context' => new ctools_context_optional(t('Keywords'), 'string'),
    'required context' => new ctools_context_optional(t('Keys'), 'string'), // Node context is required
    'defaults' => array(
        'index_url' => 'availabletechnologies',
        'search_form_label' => '',
    ),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 * 
 */

/**
 * An edit form for the pane's settings.
 */
function ttc_at_search_form_pane_edit_form($form, &$form_state) {
    $conf = $form_state['conf'];

    // Index URL for this form
    $form['index_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Search Index URL'),
        '#default_value' => $conf['index_url'],
        '#required' => TRUE,
        '#description' => t('URL that you would like a user redirected to when 
          preforming the search.'),
    );
    
    // Optional Label
    $form['search_form_label'] = array(
        '#type' => 'textfield',
        '#title' => t('Optional Label'),
        '#default_value' => $conf['search_form_label'],
        '#required' => FALSE,
        '#description' => t('Enter text that you want to appear above the search field (optional).'),
    );

    return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function ttc_at_search_form_pane_edit_form_submit($form, &$form_state) {

    foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        if (isset($form_state['values'][$key])) {
            $form_state['conf'][$key] = $form_state['values'][$key];
        }
    }
}

function ttc_at_search_form_pane_render($subtype, $conf, $panel_args, $context) {

    // Get the URL from the settings on the form
    $index_url = ($conf && array_key_exists('index_url', $conf)) ? $conf['index_url'] : NULL;

    // Determine if a search argument has already been passed in
    $keys = isset($context->data) ? $context->data : NULL;
    
    $label = ($conf && array_key_exists('search_form_label', $conf)) ? $conf['search_form_label'] : NULL;


    // Get the form
    module_load_include('form.inc', 'ttc_search', 'includes/ttc_at_search');
    $form = drupal_get_form('ttc_at_search_form', $index_url, $keys, $label);

    // Output the block 
    $block = new stdClass();
    $block->content = $form;

    return $block;
}
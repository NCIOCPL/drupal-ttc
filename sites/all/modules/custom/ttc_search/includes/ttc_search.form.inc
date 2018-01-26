<?php

/**
 * Defines form for a search submission.
 * 
 * @param type $form This does nothing.
 * @param type $form_state A way to pass in variables and set things.
 * @param type $keys If when loading the form, keys have already been entered
 *      e.g. via URL.
 * @param type $index_id The index id that we are searching against.
 * @param type $index_machine The index's machine name that we are searching against.
 * @return type A form.
 */
function ttc_search_form($form, &$form_state, $index_url = NULL, $keys = NULL, $label = NULL) {

  // Set the index_url if its in the form_state and not passed in
  if (!$index_url && array_key_exists('index_url', $form_state['input']))
    $index_url = $form_state['input']['index_url'];

  // Set the keys variable if its in the form_state and not passed in
  if (!isset($keys) && array_key_exists('keys', $form_state['input']))
    $keys = $form_state['input']['keys'];

  if (!$label && array_key_exists('search_form_label', $form_state['input']))
    $label = $form_state['input']['search_form_label'];

  // Index URL element
  // Hidden
  // The URL we're targeting this search at
  $form['index_url'] = array(
    '#type' => 'hidden',
    '#default_value' => $index_url,
    '#title' => 'Index URL',
    '#title_display' => 'none',
  );

  $form['search_container'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row', '-no-margin')),
  );

  // Keys element
  // Textfield
  // What we are going to search by
  $form['search_container']['keys'] = array(
    '#type' => 'textfield',
    '#default_value' => $keys == 'all' ? '' : $keys,
    '#title' => 'Search',
    '#title_display' => 'invisible',
    //'#prefix' => '<div class="small-10 columns search-form__input-container">',
    //'#suffix' => '</div>',
    '#attributes' => array(
      //'class' => array('search-form__input'),
      'placeholder' => 'Search...',
    ),
  );

  //If the label exists, display it
  if ($label) {
    $form['search_container']['keys']['#title'] = $label;
    $form['search_container']['keys']['#attributes']['placeholder'] = $label;
  }

  // Submit element
  // Submit button
  // Activates the form
  $form['search_container']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'GO',
    //'#prefix' => '<div class="small-2 columns search-form__submit-container">',
    //'#suffix' => '</div>',
    '#attributes' => array(
      /*'class' => array(
        'button',
        'radius',
        'postfix',
        'expand',
        'search-form__submit form-submit')*/
    ),
  );

  // Return the form
  return $form;
}

/**
 * Redirects the search form to the proper URL after submission.
 * 
 * @param type $form The built form.
 * @param type $form_state The current form's state.
 */
function ttc_search_form_submit($form, &$form_state) {

  // Use an extra function to figure out where we are and where we need to
  // go based on that.
  if (array_key_exists('index_url', $form_state['values'])) {
    $url = $form_state['values']['index_url'] . '/';
    if (substr($url, -1) == '/')
      $url = substr_replace($url, '', -1);
  } else {
    $url = _ttc_search_get_main_path_from_page();
  }

  // Make sure that if the keys exist, they are stripped
  $keys = NULL;
  if (array_key_exists('keys', $form_state['values'])) {
    // Get the original keys value
    $keys = $form_state['values']['keys'];
    // Strip special characters
    $keys = preg_replace('/[^a-zA-Z0-9_ ,"\'.\\/-]/s', '', $keys);
    // If there's more than one whitespace character next to each other
    // (probably from stripping special characters), replace it with just
    // one space.
    $keys = preg_replace('!\s+!', ' ', $keys);
    // Trim any space on the ends of the string
    $keys = trim($keys);
    // Set the cleaned up keys value
    $form_state['values']['keys'] = $keys;
  }

  // If we have our index, now we will attempt to get our "keys" or what we
  // are trying to search by. But, only append to the URL if there's something
  // there.
  if ($url && $keys) {
    $url = "$url/$keys";
  }
  else
  {
    // if keys are empty, use 'all' in their place
    $url = "$url/all";
  }

  // If there are no keys, at least send the user to the main screen of the 
  // area they're trying to search. First, let's clean up the carriage returns
  // and anything else that's suspicious.
  $url = str_replace("\r", '', $url); // This is slightly old and may have been 
  // eliminated after we started stripping special characters from keys.
  // Unset a destination; The way drupal_goto is coded, a $_GET['destination']
  // will override the $url we are passing in and on 404 and 403 pages, there
  // is a $_GET['destination'] set that interferes
  unset($_GET['destination']);

  // include any current parameters to work with facet filters etc.
  $options = array('external' => FALSE, 'https' => TRUE);
  $query_parms = drupal_get_query_parameters();
  if (!empty($query_parms)) {
    $options['query'] = $query_parms;
  }

  // Go to our constructed URL OR keep the user on the same page
  if ($url) {
    drupal_goto($url, $options);
  }
}

/**
 * Internal function to detect what index we are trying to search by and to
 * return how the URL should look.
 * 
 * @return null The top path that a search should be known by, if found.
 */
function _ttc_search_get_main_path_from_page() {
  $page = page_manager_get_current_page();

  if (array_key_exists('handler', $page) & isset($page['handler']->subtask)) {

    // If we are looking at Sitwide Search Results, we should aim to the
    // top path that this is aimed at.
    if ($page['handler']->subtask == 'search') {
      if (array_key_exists('handler', $page) && isset($page['handler']->conf)) {
        $variant = $page['handler']->conf;
        if (array_key_exists('access', $variant) && array_key_exists('plugins', $variant['access'])) {
          foreach ($variant['access']['plugins'] as $plugin) {
            if ($plugin['name'] == 'path_visibility') {
              if (array_key_exists('paths', $plugin['settings'])) {
                $paths = array();
                foreach (explode("\n", $plugin['settings']['paths']) as $path) {
                  $paths[] = check_plain($path);
                }
                //dsm($paths);
                if (count($paths) > 0)
                  return 'search/' . $paths[0];
              }
              break;
            }
          }
        }
      }
    }

    // If we are looking at the directory boutique searches aka
    // the URL(s) /allaboutnci/%directory type/search/!keys where the
    // directory type is most likely people or organization(s)
    elseif ($page['handler']->subtask == 'directory_boutique_searches' && array_key_exists('subtask', $page['subtask'])) {
      return current_path();
    }
  }
  return NULL;
}

/**
 * Internal function called by page.tpl.php to get the search block at the top.
 */
function _ttc_search_get_header_form() {
  $ttc_search_form = ctools_get_plugins('ctools', 'content_types', 'ttc_search_form_pane');
  if (isset($ttc_search_form['render callback'])) {
    $subtype = array_key_exists('name', $ttc_search_form) ? $ttc_search_form['name'] : NULL;
    $blockClass = $ttc_search_form['render callback']($subtype, NULL, NULL, NULL);
    $block['content'] = isset($blockClass->content) ? $blockClass->content : array();
    $block['content']['index_url']['#value'] = 'search/content';
    print render($block);
  }
}

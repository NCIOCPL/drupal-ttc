<?php

/**
 * Implements template_preprocess_html().
 */
function ttctheme_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic', array('group' => CSS_THEME));
}

/**
 * Implements template_preprocess_page().
 */
function ttctheme_preprocess_page(&$variables) {
  // Decide whether to show the alternate header.
  // Without this, an empty <section> may be rendered.
  $variables['show_alt_header'] = (
    $variables['linked_logo'] ||
    $variables['site_name'] ||
    $variables['site_slogan'] ||
    $variables['alt_main_menu'] ||
    $variables['alt_secondary_menu']
  );
}

/**
 * Implements template_preprocess_node().
 */
function ttctheme_preprocess_node(&$variables) {
}

/**
 * Implements hook_preprocess_block().
 */
function ttctheme_preprocess_block(&$vars) {
  $block = $vars['block'];
  $machine_name = fe_block_get_machine_name($block->delta);

  if (!empty($machine_name)) {
    $vars['classes_array'][] = 'block--' . str_replace('_', '-', $machine_name);
  }
}

/**
 * Implements hook_form_alter().
 */
function ttctheme_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['#form_id']) && ($form['#form_id'] == 'search_block_form')) {
    // <FORM> element updates
    // Add the `search-form__form` class to the <form> element.
    $form += array(
      '#attributes' => array(
        'class' => array(
          'search-form__form'
        )
      )
    );

    // <INPUT> element updates
    // Add the `placeholder` attribute and `search-form__input` class to the <input> element.
    $form['search_block_form']['#attributes'] += array(
      'placeholder' => 'Search...',
      'class' => array(
        'search-form__input'
      )
    );
    // Change the prefix before the <input> from the base theme default.
    $form['search_block_form']['#prefix'] = '<div class="row -no-margin"><div class="small-10 columns search-form__input-container">';

    // <BUTTON> element updates
    // Set the text inside the <button> element.
    $form['actions']['submit']['#value'] = 'Go';
    // Remove the `secondary` class from the <button> element.
    $form['actions']['submit']['#attributes']['class'] = array_diff(
      $form['actions']['submit']['#attributes']['class'],
      array('secondary')
    );
    // Add the `primary` class from the <button> element.
    $form['actions']['submit']['#attributes']['class'][] = 'primary';
    // Remove the `search-form__submit` class from the <button> element.
    $form['actions']['submit']['#attributes']['class'][] = 'search-form__submit';
    // Change the prefix before the <button> element from the base theme default.
    $form['actions']['submit']['#prefix'] = '<div class="small-2 columns search-form__submit-container">';
  }
}

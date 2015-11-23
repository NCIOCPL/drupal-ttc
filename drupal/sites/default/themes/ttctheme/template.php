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
 * Implements template_preprocess_block().
 */
function ttc_theme_config_preprocess_block(&$vars) {
  $block = $vars['block'];

  // Add the block's machine name to its class list.
  $machine_name = fe_block_get_machine_name($block->delta);
  if (!empty($machine_name)) {
    $vars['classes_array'][] = 'block--' . str_replace('_', '-', $machine_name);
  }

  // If the block is a menu block, hide its title
  if ($block->module == 'menu') {
    $vars['title_attributes_array'] += array(
      'class' => array(
        'element-invisible'
      )
    );
  }
}

/**
 * Implements hook_form_alter().
 */
function ttctheme_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['#form_id']) && ($form['#form_id'] == 'search_block_form')) {
    $form['search_block_form']['#attributes'] += array(
      'placeholder' => 'Search...',
      'class' => array(
        'search-form__input'
      )
    );
    $form['search_block_form']['#prefix'] = '<div class="row -no-margin"><div class="small-10 columns search-form__input-container">';

    $form['actions']['submit']['#value'] = 'Go';
    $form['actions']['submit']['#attributes']['class'] = array_diff(
        $form['actions']['submit']['#attributes']['class'], array('secondary')
    );
    $form['actions']['submit']['#attributes']['class'][] = 'primary';
    $form['actions']['submit']['#attributes']['class'][] = 'search-form__submit';
    $form['actions']['submit']['#prefix'] = '<div class="small-2 columns search-form__submit-container">';
  }
}

function regex_to_lowercase($matches) {
  return strtolower($matches[0]);
}

function ttctheme_facetapi_link_inactive($variables) {

  $node = menu_get_object();

  if ($node && $node->type == 'abstract') {
    $variables['path'] = 'availabletechnologies/all';
  }

  // Builds accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $variables['text'] .= ' ' . theme('facetapi_count', $variables);
  }

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  return theme_link($variables);
}

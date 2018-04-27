<?php

/**
 * Implements template_preprocess_html().
 */
function ttctheme_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic', array('group' => CSS_THEME));

  // Send X-UA-Compatible HTTP header to force IE to use the most recent
  // rendering engine or use Chrome's frame rendering engine if available.
  // @see https://www.drupal.org/node/1203112
  if (is_null(drupal_get_http_header('X-UA-Compatible'))) {
    drupal_add_http_header('X-UA-Compatible', 'IE=edge');
  }

  // load the DTM js URL from a variable, allowing it to be overridden if needed
  $src = variable_get('adobe_dtm_js', 
      '//assets.adobedtm.com/f1bfa9f7170c81b1a9a9ecdcc6c5215ee0b03c84/satelliteLib-5ad8c106153615d0673f7263de823289c481d7df.js');
  $dtm_script = "<script src='$src'></script>\n";
  // add DTM tag
  $element = array(
      '#type' => 'markup', // use raw markup to correctly build the script tags
      '#markup' => $dtm_script,
      '#weight' => '-9999999', // push this script as high as possible
    );
    // add element to html head
    drupal_add_html_head($element, 'dtm_script_head');
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
  
  $disclaimer_default_text = array('value' => 'This site is undergoing remediation for compliance with Section 508. ' .
      'The remediation will be complete by April 30, 2016. In the interim, ' . 
      'should you require any accessibility assistance with any content, ' . 
      'please contact the NCI Technology Transfer team at [use the tech transfer ' . 
      'email here]. Thank you!');
  
  $variables['site_hhs_disclaimer'] = (variable_get('show_hhs_disclaimer', TRUE) ? filter_xss_admin(variable_get('site_hhs_disclaimer', $disclaimer_default_text)['value']) : '');
  
    $main_menu_tree = menu_tree_all_data('menu-site-structure');

  // Add the rendered output to the $main_menu_expanded variable
  $variables['menu_site_structure_expanded'] = menu_tree_output($main_menu_tree);
}

/**
 * Implements template_preprocess_node().
 */
function ttctheme_preprocess_node(&$variables) {

}

/**
 * Implements template_preprocess_block().
 */
function ttctheme_preprocess_block(&$vars) {
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

/**
 * Implements theme_field().
 */
function ttctheme_field($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . '</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Implements theme_field__field_type().
 */
function ttctheme_field__taxonomy_term_reference($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . '</div>';
  }

  // Render the items.
  $output .= '<ul class="field-items taxonomy-terms links"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item taxonomy-term ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<li class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
  }
  $output .= '</ul>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
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

function ttctheme_facetapi_link_active($variables) {
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

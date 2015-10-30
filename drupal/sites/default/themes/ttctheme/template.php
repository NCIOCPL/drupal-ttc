<?php

/**
 * Implements template_preprocess_html().
 */
function ttctheme_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic', array('group' => CSS_THEME));
}

/**
 * Implements template_preprocess_page.
 */
function ttctheme_preprocess_page(&$variables) {
}

/**
 * Implements template_preprocess_node.
 */
function ttctheme_preprocess_node(&$variables) {
}

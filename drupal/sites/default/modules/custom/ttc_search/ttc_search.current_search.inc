<?php
/**
 * @file
 * ttc_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function ttc_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'current_abstract_faceted_search';
  $item->label = 'Current Abstract Faceted Search';
  $item->settings = array(
    'items' => array(
      'active_facets' => array(
        'id' => 'active',
        'label' => 'Active Facets',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 1,
        'classes' => 'facet-selection',
        'nofollow' => 1,
        'weight' => '0',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '2',
    ),
  );
  $export['current_abstract_faceted_search'] = $item;

  return $export;
}

<?php
/**
 * @file
 * ttc_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ttc_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_node__panel_context_ce61e6fb-6c9b-46cb-a9b8-a0d6984ef738';
  $handler->task = 'search';
  $handler->subtask = 'node';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Search API Results',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3402764f-da73-4d6b-857e-b5af3a665f2c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e8d324e9-f9d0-459d-a080-597df13dd956';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'ttc_content_search_results-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'search_api_views_fulltext' => '%keywords',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e8d324e9-f9d0-459d-a080-597df13dd956';
    $display->content['new-e8d324e9-f9d0-459d-a080-597df13dd956'] = $pane;
    $display->panels['center'][0] = 'new-e8d324e9-f9d0-459d-a080-597df13dd956';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_node__panel_context_ce61e6fb-6c9b-46cb-a9b8-a0d6984ef738'] = $handler;

  return $export;
}

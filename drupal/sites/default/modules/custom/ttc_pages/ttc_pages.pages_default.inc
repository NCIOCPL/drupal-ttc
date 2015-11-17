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
  $display->title = 'Search Results';
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
      'use_pager' => 1,
      'pager_id' => '0',
      'items_per_page' => '20',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
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

/**
 * Implements hook_default_page_manager_pages().
 */
function ttc_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'available_technologies_faceted_search';
  $page->task = 'page';
  $page->admin_title = 'Available Technologies faceted search';
  $page->admin_description = '';
  $page->path = 'availabletechnologies';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Available Technologies',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_available_technologies_faceted_search__panel';
  $handler->task = 'page';
  $handler->subtask = 'available_technologies_faceted_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Faceted Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: TTC Abstract Faceted Results: Abstract Faceted Context',
        'keyword' => 'facets',
        'name' => 'view:ttc_abstract_faceted_results-ctools_context_1',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '62.969128458000284',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '37.030871541999716',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'facets',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'facets' => array(
        'type' => 'region',
        'title' => 'Facets',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'facets' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Available Technologies';
  $display->uuid = '277f2171-f017-40ff-baab-698ef998bbd8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-093fa0b3-7ce8-4633-9d88-06ccf129f2be';
    $pane->panel = 'center';
    $pane->type = 'views_view';
    $pane->subtype = 'views_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:ttc_abstract_faceted_results-ctools_context_1_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '093fa0b3-7ce8-4633-9d88-06ccf129f2be';
    $display->content['new-093fa0b3-7ce8-4633-9d88-06ccf129f2be'] = $pane;
    $display->panels['center'][0] = 'new-093fa0b3-7ce8-4633-9d88-06ccf129f2be';
    $pane = new stdClass();
    $pane->pid = 'new-59da9e71-7ec2-401e-a5f6-0a8ebb55e594';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-V0ORwTOF30Y11IwwWPxSInnNyVnSosED';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Product Type',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '59da9e71-7ec2-401e-a5f6-0a8ebb55e594';
    $display->content['new-59da9e71-7ec2-401e-a5f6-0a8ebb55e594'] = $pane;
    $display->panels['facets'][0] = 'new-59da9e71-7ec2-401e-a5f6-0a8ebb55e594';
    $pane = new stdClass();
    $pane->pid = 'new-ce03417b-f1b6-4228-95d2-e844fd2e6c4b';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Zotwmz5D6XDlXozm0prmtnI1fpQJ9msu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Development Stage',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ce03417b-f1b6-4228-95d2-e844fd2e6c4b';
    $display->content['new-ce03417b-f1b6-4228-95d2-e844fd2e6c4b'] = $pane;
    $display->panels['facets'][1] = 'new-ce03417b-f1b6-4228-95d2-e844fd2e6c4b';
    $pane = new stdClass();
    $pane->pid = 'new-cecef8cf-637f-435e-bb18-03b3ebba61f7';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-0mDxvjOxnXZdopMrqEJx0bwgV6mUZDlo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Therapeutic Area',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'cecef8cf-637f-435e-bb18-03b3ebba61f7';
    $display->content['new-cecef8cf-637f-435e-bb18-03b3ebba61f7'] = $pane;
    $display->panels['facets'][2] = 'new-cecef8cf-637f-435e-bb18-03b3ebba61f7';
    $pane = new stdClass();
    $pane->pid = 'new-6cb1a064-2aff-487d-af15-258fb4be714b';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-lBZ1VAzTznOE5gQyP8OHERh0Zq44hFsG';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Patent Status',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6cb1a064-2aff-487d-af15-258fb4be714b';
    $display->content['new-6cb1a064-2aff-487d-af15-258fb4be714b'] = $pane;
    $display->panels['facets'][3] = 'new-6cb1a064-2aff-487d-af15-258fb4be714b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-59da9e71-7ec2-401e-a5f6-0a8ebb55e594';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['available_technologies_faceted_search'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_homepage__panel_context_5d326fdf-2d40-42b2-b528-f211176abf5c';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->layout = 'ttc_home';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'top_first' => NULL,
      'top_second' => NULL,
      'top_third' => NULL,
      'top_fourth' => NULL,
      'middle_small' => NULL,
      'middle_large' => NULL,
      'middle_first' => NULL,
      'middle_second' => NULL,
      'bottom_first' => NULL,
      'bottom_second' => NULL,
      'bottom_third' => NULL,
      'bottom_fourth' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '299b2b76-2d89-4a77-88a9-8133ee604829';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}

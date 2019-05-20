<?php
/**
 * @file
 * ttc_pages.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function ttc_pages_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'ttc_abstract_faceted_search_mini';
  $mini->category = 'TTC Search';
  $mini->admin_title = 'TTC Abstract Faceted Search Minipanel';
  $mini->admin_description = 'A minipanel that displays keyword and faceted search options.';
  $mini->requiredcontexts = array();
  $mini->contexts = array(
    0 => array(
      'identifier' => 'Abstract Faceted View',
      'keyword' => 'facet_context',
      'name' => 'view:ttc_abstract_faceted_results-ctools_context_1',
      'id' => 1,
    ),
    1 => array(
      'identifier' => 'Search Keyword',
      'keyword' => 'keyword',
      'name' => 'string',
      'string' => 'all',
      'id' => 1,
    ),
  );
  $mini->relationships = array(
    0 => array(
      'identifier' => 'Abstract Faceted Relationship',
      'keyword' => 'facet_relationship',
      'name' => 'view_from_argument:ttc_abstract_faceted_results-ctools_context_1',
      'context' => array(
        0 => 'context_string_1',
      ),
      'id' => 1,
    ),
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
  $display->uuid = '46102afa-e4f2-48c8-9554-f94b2ec6cb1b';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'ttc_abstract_faceted_search_mini';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6a7be82a-efdc-4b4b-8a98-f1b66525ae6e';
  $pane->panel = 'center';
  $pane->type = 'ttc_search_form_pane';
  $pane->subtype = 'ttc_search_form_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'index_url' => 'availabletechnologies',
    'search_form_label' => 'Keywords',
    'context' => 'context_string_1',
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
  $pane->uuid = '6a7be82a-efdc-4b4b-8a98-f1b66525ae6e';
  $display->content['new-6a7be82a-efdc-4b4b-8a98-f1b66525ae6e'] = $pane;
  $display->panels['center'][0] = 'new-6a7be82a-efdc-4b4b-8a98-f1b66525ae6e';
  $pane = new stdClass();
  $pane->pid = 'new-d2ed2bcd-5b55-488f-babb-b10e17700d7d';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-V0ORwTOF30Y11IwwWPxSInnNyVnSosED';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Product Type',
    'override_title_heading' => 'div',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd2ed2bcd-5b55-488f-babb-b10e17700d7d';
  $display->content['new-d2ed2bcd-5b55-488f-babb-b10e17700d7d'] = $pane;
  $display->panels['center'][1] = 'new-d2ed2bcd-5b55-488f-babb-b10e17700d7d';
  $pane = new stdClass();
  $pane->pid = 'new-d8da55eb-9128-44ac-a3d5-3fc4faf87f6f';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-Zotwmz5D6XDlXozm0prmtnI1fpQJ9msu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Development Stage',
    'override_title_heading' => 'div',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd8da55eb-9128-44ac-a3d5-3fc4faf87f6f';
  $display->content['new-d8da55eb-9128-44ac-a3d5-3fc4faf87f6f'] = $pane;
  $display->panels['center'][2] = 'new-d8da55eb-9128-44ac-a3d5-3fc4faf87f6f';
  $pane = new stdClass();
  $pane->pid = 'new-65041783-edb0-4fce-89b6-b7c14a137378';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-0mDxvjOxnXZdopMrqEJx0bwgV6mUZDlo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Therapeutic Area',
    'override_title_heading' => 'div',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '65041783-edb0-4fce-89b6-b7c14a137378';
  $display->content['new-65041783-edb0-4fce-89b6-b7c14a137378'] = $pane;
  $display->panels['center'][3] = 'new-65041783-edb0-4fce-89b6-b7c14a137378';
  $pane = new stdClass();
  $pane->pid = 'new-026866fb-65f9-4934-8128-9e7f07fa2dd3';
  $pane->panel = 'center';
  $pane->type = 'views_feed';
  $pane->subtype = 'views_feed';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '026866fb-65f9-4934-8128-9e7f07fa2dd3';
  $display->content['new-026866fb-65f9-4934-8128-9e7f07fa2dd3'] = $pane;
  $display->panels['center'][4] = 'new-026866fb-65f9-4934-8128-9e7f07fa2dd3';
  $pane = new stdClass();
  $pane->pid = 'new-b93873de-ed43-47f0-a20a-9cb8a6e860be';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-ya9EzkEbDs5kWs4SG4O6F42ZtiD4tdUj';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Institutes and Centers',
    'override_title_heading' => 'div',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'b93873de-ed43-47f0-a20a-9cb8a6e860be';
  $display->content['new-b93873de-ed43-47f0-a20a-9cb8a6e860be'] = $pane;
  $display->panels['center'][5] = 'new-b93873de-ed43-47f0-a20a-9cb8a6e860be';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-6a7be82a-efdc-4b4b-8a98-f1b66525ae6e';
  $mini->display = $display;
  $export['ttc_abstract_faceted_search_mini'] = $mini;

  return $export;
}

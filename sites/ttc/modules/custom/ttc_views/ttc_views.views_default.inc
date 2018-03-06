<?php
/**
 * @file
 * ttc_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ttc_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'abstracts_rss';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Abstracts RSS';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TTC Available Technologies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Product Type (field_product_type) */
  $handler->display->display_options['relationships']['field_product_type_tid']['id'] = 'field_product_type_tid';
  $handler->display->display_options['relationships']['field_product_type_tid']['table'] = 'field_data_field_product_type';
  $handler->display->display_options['relationships']['field_product_type_tid']['field'] = 'field_product_type_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Meta Description */
  $handler->display->display_options['fields']['field_meta_long_desc']['id'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['table'] = 'field_data_field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['field'] = 'field_meta_long_desc';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'r';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Product Type (field_product_type) */
  $handler->display->display_options['arguments']['field_product_type_tid']['id'] = 'field_product_type_tid';
  $handler->display->display_options['arguments']['field_product_type_tid']['table'] = 'field_data_field_product_type';
  $handler->display->display_options['arguments']['field_product_type_tid']['field'] = 'field_product_type_tid';
  $handler->display->display_options['arguments']['field_product_type_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_product_type_tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_product_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_product_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_product_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_product_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_product_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_product_type_tid']['validate_options']['vocabularies'] = array(
    'product_type' => 'product_type',
  );
  $handler->display->display_options['arguments']['field_product_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_product_type_tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'abstract' => 'abstract',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Announce opportunity to GovDelivery? (field_opp_list_send) */
  $handler->display->display_options['filters']['field_opp_list_send_value']['id'] = 'field_opp_list_send_value';
  $handler->display->display_options['filters']['field_opp_list_send_value']['table'] = 'field_data_field_opp_list_send';
  $handler->display->display_options['filters']['field_opp_list_send_value']['field'] = 'field_opp_list_send_value';
  $handler->display->display_options['filters']['field_opp_list_send_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_opp_list_send_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'abstract_feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Available Technologies from the Technology Transfer Center.';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'path';
  $handler->display->display_options['row_options']['description_field'] = 'field_meta_long_desc';
  $handler->display->display_options['row_options']['creator_field'] = 'name';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'path',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['path'] = 'rss/%/abstracts.xml';
  $handler->display->display_options['sitename_title'] = 0;
  $export['abstracts_rss'] = $view;

  $view = new view();
  $view->name = 'abstracts_xml';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Abstracts XML';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TTC Abstract Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own unpublished content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Product Type (field_product_type) */
  $handler->display->display_options['relationships']['field_product_type_tid']['id'] = 'field_product_type_tid';
  $handler->display->display_options['relationships']['field_product_type_tid']['table'] = 'field_data_field_product_type';
  $handler->display->display_options['relationships']['field_product_type_tid']['field'] = 'field_product_type_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Meta Description */
  $handler->display->display_options['fields']['field_meta_long_desc']['id'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['table'] = 'field_data_field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['field'] = 'field_meta_long_desc';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'r';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Product Type (field_product_type) */
  $handler->display->display_options['arguments']['field_product_type_tid']['id'] = 'field_product_type_tid';
  $handler->display->display_options['arguments']['field_product_type_tid']['table'] = 'field_data_field_product_type';
  $handler->display->display_options['arguments']['field_product_type_tid']['field'] = 'field_product_type_tid';
  $handler->display->display_options['arguments']['field_product_type_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_product_type_tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_product_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_product_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_product_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_type_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_product_type_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_product_type_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_product_type_tid']['validate_options']['vocabularies'] = array(
    'product_type' => 'product_type',
  );
  $handler->display->display_options['arguments']['field_product_type_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_product_type_tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'abstract' => 'abstract',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Announce opportunity to GovDelivery? (field_opp_list_send) */
  $handler->display->display_options['filters']['field_opp_list_send_value']['id'] = 'field_opp_list_send_value';
  $handler->display->display_options['filters']['field_opp_list_send_value']['table'] = 'field_data_field_opp_list_send';
  $handler->display->display_options['filters']['field_opp_list_send_value']['field'] = 'field_opp_list_send_value';
  $handler->display->display_options['filters']['field_opp_list_send_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_opp_list_send_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Abstract XML Single */
  $handler = $view->new_display('views_data_export', 'Abstract XML Single', 'abstract_xml');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'pascal';
  $handler->display->display_options['style_options']['root_node'] = 'Technologies';
  $handler->display->display_options['style_options']['item_node'] = 'Technology';
  $handler->display->display_options['style_options']['no_entity_encode'] = array(
    'field_inventors' => 'field_inventors',
    'field_enumber' => 'field_enumber',
    'field_opp_rel_enum' => 'field_opp_rel_enum',
    'field_pat_status' => 'field_pat_status',
    'field_publications' => 'field_publications',
    'field_product_type' => 'field_product_type',
    'field_contact_auto' => 'field_contact_auto',
  );
  $handler->display->display_options['style_options']['cdata_wrapper'] = array(
    'field_opp_compadv_text' => 'field_opp_compadv_text',
    'field_opp_commapp_text' => 'field_opp_commapp_text',
    'field_development_stage' => 'field_development_stage',
    'field_additional_patent_document' => 'field_additional_patent_document',
  );
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Competitive Advantages */
  $handler->display->display_options['fields']['field_opp_compadv_text']['id'] = 'field_opp_compadv_text';
  $handler->display->display_options['fields']['field_opp_compadv_text']['table'] = 'field_data_field_opp_compadv_text';
  $handler->display->display_options['fields']['field_opp_compadv_text']['field'] = 'field_opp_compadv_text';
  $handler->display->display_options['fields']['field_opp_compadv_text']['label'] = 'Advantages';
  /* Field: Content: Potential Commercial Applications */
  $handler->display->display_options['fields']['field_opp_commapp_text']['id'] = 'field_opp_commapp_text';
  $handler->display->display_options['fields']['field_opp_commapp_text']['table'] = 'field_data_field_opp_commapp_text';
  $handler->display->display_options['fields']['field_opp_commapp_text']['field'] = 'field_opp_commapp_text';
  $handler->display->display_options['fields']['field_opp_commapp_text']['label'] = 'Applications';
  /* Field: Content: Development Stage */
  $handler->display->display_options['fields']['field_development_stage']['id'] = 'field_development_stage';
  $handler->display->display_options['fields']['field_development_stage']['table'] = 'field_data_field_development_stage';
  $handler->display->display_options['fields']['field_development_stage']['field'] = 'field_development_stage';
  $handler->display->display_options['fields']['field_development_stage']['label'] = 'Development Status';
  $handler->display->display_options['fields']['field_development_stage']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Meta Description */
  $handler->display->display_options['fields']['field_meta_long_desc']['id'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['table'] = 'field_data_field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['field'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['label'] = 'Abstract';
  /* Field: Content: Collaboration Opportunity */
  $handler->display->display_options['fields']['field_opp_co_dev']['id'] = 'field_opp_co_dev';
  $handler->display->display_options['fields']['field_opp_co_dev']['table'] = 'field_data_field_opp_co_dev';
  $handler->display->display_options['fields']['field_opp_co_dev']['field'] = 'field_opp_co_dev';
  $handler->display->display_options['fields']['field_opp_co_dev']['label'] = 'Collaborative Research Opportunity';
  /* Field: Content: Updated */
  $handler->display->display_options['fields']['field_updated_date']['id'] = 'field_updated_date';
  $handler->display->display_options['fields']['field_updated_date']['table'] = 'field_data_field_updated_date';
  $handler->display->display_options['fields']['field_updated_date']['field'] = 'field_updated_date';
  $handler->display->display_options['fields']['field_updated_date']['label'] = 'Updated On';
  $handler->display->display_options['fields']['field_updated_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_updated_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_updated_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Posted */
  $handler->display->display_options['fields']['field_posted_date']['id'] = 'field_posted_date';
  $handler->display->display_options['fields']['field_posted_date']['table'] = 'field_data_field_posted_date';
  $handler->display->display_options['fields']['field_posted_date']['field'] = 'field_posted_date';
  $handler->display->display_options['fields']['field_posted_date']['label'] = 'Date Published';
  $handler->display->display_options['fields']['field_posted_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_posted_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Date Unpublished */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Date Unpublished';
  $handler->display->display_options['fields']['nid']['label'] = 'Date Unpublished';
  /* Field: Content: Inventor Data */
  $handler->display->display_options['fields']['field_inventors']['id'] = 'field_inventors';
  $handler->display->display_options['fields']['field_inventors']['table'] = 'field_data_field_inventors';
  $handler->display->display_options['fields']['field_inventors']['field'] = 'field_inventors';
  $handler->display->display_options['fields']['field_inventors']['label'] = 'Inventors';
  $handler->display->display_options['fields']['field_inventors']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_inventors']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_inventors']['delta_offset'] = '0';
  /* Field: Content: Reference Number */
  $handler->display->display_options['fields']['field_enumber']['id'] = 'field_enumber';
  $handler->display->display_options['fields']['field_enumber']['table'] = 'field_data_field_enumber';
  $handler->display->display_options['fields']['field_enumber']['field'] = 'field_enumber';
  $handler->display->display_options['fields']['field_enumber']['label'] = 'Included Invention';
  /* Field: Content: Related Technologies */
  $handler->display->display_options['fields']['field_opp_rel_enum']['id'] = 'field_opp_rel_enum';
  $handler->display->display_options['fields']['field_opp_rel_enum']['table'] = 'field_data_field_opp_rel_enum';
  $handler->display->display_options['fields']['field_opp_rel_enum']['field'] = 'field_opp_rel_enum';
  $handler->display->display_options['fields']['field_opp_rel_enum']['label'] = 'Related Invention';
  $handler->display->display_options['fields']['field_opp_rel_enum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opp_rel_enum']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_opp_rel_enum']['separator'] = '|';
  /* Field: Content: Patent Status */
  $handler->display->display_options['fields']['field_pat_status']['id'] = 'field_pat_status';
  $handler->display->display_options['fields']['field_pat_status']['table'] = 'field_data_field_pat_status';
  $handler->display->display_options['fields']['field_pat_status']['field'] = 'field_pat_status';
  $handler->display->display_options['fields']['field_pat_status']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_pat_status']['delta_offset'] = '0';
  /* Field: Content: Additional Patent Documentation */
  $handler->display->display_options['fields']['field_additional_patent_document']['id'] = 'field_additional_patent_document';
  $handler->display->display_options['fields']['field_additional_patent_document']['table'] = 'field_data_field_additional_patent_document';
  $handler->display->display_options['fields']['field_additional_patent_document']['field'] = 'field_additional_patent_document';
  $handler->display->display_options['fields']['field_additional_patent_document']['label'] = 'Additonal Patent Documentation';
  /* Field: Content: Publication Data */
  $handler->display->display_options['fields']['field_publications']['id'] = 'field_publications';
  $handler->display->display_options['fields']['field_publications']['table'] = 'field_data_field_publications';
  $handler->display->display_options['fields']['field_publications']['field'] = 'field_publications';
  $handler->display->display_options['fields']['field_publications']['label'] = 'Publications';
  $handler->display->display_options['fields']['field_publications']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_publications']['delta_offset'] = '0';
  /* Field: Content: Product Type */
  $handler->display->display_options['fields']['field_product_type']['id'] = 'field_product_type';
  $handler->display->display_options['fields']['field_product_type']['table'] = 'field_data_field_product_type';
  $handler->display->display_options['fields']['field_product_type']['field'] = 'field_product_type';
  $handler->display->display_options['fields']['field_product_type']['label'] = 'Provider Classifications';
  $handler->display->display_options['fields']['field_product_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_product_type']['delta_offset'] = '0';
  /* Field: Content: Contact */
  $handler->display->display_options['fields']['field_contact_auto']['id'] = 'field_contact_auto';
  $handler->display->display_options['fields']['field_contact_auto']['table'] = 'field_data_field_contact_auto';
  $handler->display->display_options['fields']['field_contact_auto']['field'] = 'field_contact_auto';
  $handler->display->display_options['fields']['field_contact_auto']['label'] = 'Licensing Contacts';
  $handler->display->display_options['fields']['field_contact_auto']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_contact_auto']['alter']['text'] = '[field_contact_auto-tid]';
  $handler->display->display_options['fields']['field_contact_auto']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'abstract' => 'abstract',
  );
  /* Contextual filter: Content revision: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'abstract' => 'abstract',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Opportunity Year (field_opp_year) */
  $handler->display->display_options['filters']['field_opp_year_value']['id'] = 'field_opp_year_value';
  $handler->display->display_options['filters']['field_opp_year_value']['table'] = 'field_data_field_opp_year';
  $handler->display->display_options['filters']['field_opp_year_value']['field'] = 'field_opp_year_value';
  $handler->display->display_options['filters']['field_opp_year_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_opp_year_value']['value']['value'] = '2008';
  $handler->display->display_options['path'] = 'xml/abstract';
  $handler->display->display_options['segment_size'] = '50';
  $export['abstracts_xml'] = $view;

  $view = new view();
  $view->name = 'available_technologies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Available Technologies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Available Technologies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'available-technologies__list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list available-technologies';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = '';
  $handler->display->display_options['fields']['machine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<a href=\'availabletechnologies/all?f[0]=field_[machine_name]%3A[tid]\'>
<div class=\'available-technologies__block -[name]\'>
<span class=\'field-content\'><span class=\'product-label\'>[name]</span></span>
</div></a>';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_class'] = 'available-technologies__block -[name]';
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'product_type' => 'product_type',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['available_technologies'] = $view;

  $view = new view();
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Published Date */
  $handler->display->display_options['fields']['field_date_published']['id'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['table'] = 'field_data_field_date_published';
  $handler->display->display_options['fields']['field_date_published']['field'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['label'] = '';
  $handler->display->display_options['fields']['field_date_published']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_date_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_published']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<hr class="news-announcement-separator">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Published Date (field_date_published) */
  $handler->display->display_options['sorts']['field_date_published_value']['id'] = 'field_date_published_value';
  $handler->display->display_options['sorts']['field_date_published_value']['table'] = 'field_data_field_date_published';
  $handler->display->display_options['sorts']['field_date_published_value']['field'] = 'field_date_published_value';
  $handler->display->display_options['sorts']['field_date_published_value']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news_announcement' => 'news_announcement',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Published Date */
  $handler->display->display_options['fields']['field_date_published']['id'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['table'] = 'field_data_field_date_published';
  $handler->display->display_options['fields']['field_date_published']['field'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['label'] = '';
  $handler->display->display_options['fields']['field_date_published']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_date_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_published']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '800';
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<ul><li><p><br><a><h3><strong><img>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '1000',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<hr class="news-announcement-separator">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Homepage Block */
  $handler = $view->new_display('block', 'Homepage Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Announcements';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'latest-announcements small-block-grid-1  medium-block-grid-2';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'news';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'news';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Published Date */
  $handler->display->display_options['fields']['field_date_published']['id'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['table'] = 'field_data_field_date_published';
  $handler->display->display_options['fields']['field_date_published']['field'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['label'] = '';
  $handler->display->display_options['fields']['field_date_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_published']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '130';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Published Date (field_date_published) */
  $handler->display->display_options['sorts']['field_date_published_value']['id'] = 'field_date_published_value';
  $handler->display->display_options['sorts']['field_date_published_value']['table'] = 'field_data_field_date_published';
  $handler->display->display_options['sorts']['field_date_published_value']['field'] = 'field_date_published_value';
  $handler->display->display_options['sorts']['field_date_published_value']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TTC News';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'News from the Technology Transfer Center.';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'nothing_1';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['creator_field'] = 'name';
  $handler->display->display_options['row_options']['date_field'] = 'field_date_published';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Published Date */
  $handler->display->display_options['fields']['field_date_published']['id'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['table'] = 'field_data_field_date_published';
  $handler->display->display_options['fields']['field_date_published']['field'] = 'field_date_published';
  $handler->display->display_options['fields']['field_date_published']['label'] = '';
  $handler->display->display_options['fields']['field_date_published']['alter']['text'] = '[field_date_published]';
  $handler->display->display_options['fields']['field_date_published']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_date_published']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date_published']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_published']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_published']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<hr class="news-announcement-separator">';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Blank Link';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'news';
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'news';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news_announcement' => 'news_announcement',
  );
  /* Filter criterion: Content: Announce opportunity to GovDelivery? (field_opp_list_send) */
  $handler->display->display_options['filters']['field_opp_list_send_value']['id'] = 'field_opp_list_send_value';
  $handler->display->display_options['filters']['field_opp_list_send_value']['table'] = 'field_data_field_opp_list_send';
  $handler->display->display_options['filters']['field_opp_list_send_value']['field'] = 'field_opp_list_send_value';
  $handler->display->display_options['filters']['field_opp_list_send_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'rss/news.xml';
  $handler->display->display_options['sitename_title'] = 0;
  $export['news'] = $view;

  $view = new view();
  $view->name = 'success_stories';
  $view->description = '';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Success Stories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Success Stories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'success-stories__list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list success-stories';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'success_stories' => 'success_stories',
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'success-stories__image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'file',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'success-stories__title';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'success_story' => 'success_story',
  );

  /* Display: Homepage Block */
  $handler = $view->new_display('block', 'Homepage Block', 'block_home');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="success-stories__image">[field_image]</div>
<div class="success-stories__title">[title]</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'listwrapper';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
  $handler->display->display_options['sorts']['promote']['order'] = 'DESC';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';

  /* Display: Landing Page Block */
  $handler = $view->new_display('block', 'Landing Page Block', 'block_landing');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'success-stories__image';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $export['success_stories'] = $view;

  $view = new view();
  $view->name = 'ttc_abstract_faceted_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_abstract_faceted_index';
  $view->human_name = 'TTC Abstract Faceted Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = '(ascending)';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = '(descending)';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'sort' => array(
      'bef_format' => 'bef_toggle_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'abstract_sort',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'secondary_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Showing @start-@end of @total results found';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results are available that match the selected search filters.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_abstract_faceted_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Meta Description */
  $handler->display->display_options['fields']['field_meta_long_desc']['id'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['table'] = 'search_api_index_abstract_faceted_index';
  $handler->display->display_options['fields']['field_meta_long_desc']['field'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['label'] = '';
  $handler->display->display_options['fields']['field_meta_long_desc']['element_label_colon'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['field_enumber']['id'] = 'field_enumber';
  $handler->display->display_options['sorts']['field_enumber']['table'] = 'search_api_index_abstract_faceted_index';
  $handler->display->display_options['sorts']['field_enumber']['field'] = 'field_enumber';
  $handler->display->display_options['sorts']['field_enumber']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_enumber']['expose']['label'] = 'Reference Number';
  /* Sort criterion: Indexed Content: Start Date */
  $handler->display->display_options['sorts']['field_opp_start_date']['id'] = 'field_opp_start_date';
  $handler->display->display_options['sorts']['field_opp_start_date']['table'] = 'search_api_index_abstract_faceted_index';
  $handler->display->display_options['sorts']['field_opp_start_date']['field'] = 'field_opp_start_date';
  $handler->display->display_options['sorts']['field_opp_start_date']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_opp_start_date']['expose']['label'] = 'Start Date';
  /* Sort criterion: Indexed Content: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_abstract_faceted_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Date changed';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_abstract_faceted_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Contextual filter: Search: Fulltext search */
  $handler->display->display_options['arguments']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['table'] = 'search_api_index_abstract_faceted_index';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['search_api_views_fulltext']['not'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );

  /* Display: Abstract Faceted Context */
  $handler = $view->new_display('ctools_context', 'Abstract Faceted Context', 'ctools_context_1');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $handler->display->display_options['argument_input'] = array(
    'search_api_views_fulltext' => array(
      'type' => 'context',
      'context' => 'string.html_safe',
      'context_optional' => 1,
    ),
  );
  $export['ttc_abstract_faceted_results'] = $view;

  $view = new view();
  $view->name = 'ttc_content_search_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'TTC Content Search Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'TTC Content Search Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Results @start-@end of @total for ';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Search term';
  $handler->display->display_options['header']['area_text_custom']['content'] = '!1';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Content: Meta Description */
  $handler->display->display_options['fields']['field_meta_long_desc']['id'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_meta_long_desc']['field'] = 'field_meta_long_desc';
  $handler->display->display_options['fields']['field_meta_long_desc']['label'] = '';
  $handler->display->display_options['fields']['field_meta_long_desc']['element_label_colon'] = FALSE;
  /* Contextual filter: Search: Fulltext search */
  $handler->display->display_options['arguments']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['default_action'] = 'default';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_fulltext']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['search_api_views_fulltext']['not'] = 0;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'search_api_views_fulltext' => array(
      'type' => 'user',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Search: Fulltext search',
    ),
  );
  $export['ttc_content_search_results'] = $view;

  $view = new view();
  $view->name = 'workbench_abstracts';
  $view->description = 'Content overview page for Workbench.';
  $view->tag = 'Workbench';
  $view->base_table = 'node';
  $view->human_name = 'Workbench: Abstracts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Abstracts by EIR';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'view all';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access workbench';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 200';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'is_current' => 'is_current',
    'field_enumber' => 'field_enumber',
    'field_opp_year' => 'field_opp_year',
    'title' => 'title',
    'field_product_type' => 'field_product_type',
    'name' => 'name',
    'field_pat_status' => 'field_pat_status',
    'changed' => 'changed',
    'name_1' => 'name_1',
    'state' => 'state',
    'moderation_actions' => 'moderation_actions',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'is_current' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_enumber' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opp_year' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_product_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pat_status' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'moderation_actions' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There is no content available for you to edit.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  /* Field: Workbench Moderation: Current */
  $handler->display->display_options['fields']['is_current']['id'] = 'is_current';
  $handler->display->display_options['fields']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['is_current']['field'] = 'is_current';
  $handler->display->display_options['fields']['is_current']['exclude'] = TRUE;
  $handler->display->display_options['fields']['is_current']['not'] = 0;
  /* Field: Content: Reference Number */
  $handler->display->display_options['fields']['field_enumber']['id'] = 'field_enumber';
  $handler->display->display_options['fields']['field_enumber']['table'] = 'field_data_field_enumber';
  $handler->display->display_options['fields']['field_enumber']['field'] = 'field_enumber';
  /* Field: Content: Opportunity Year */
  $handler->display->display_options['fields']['field_opp_year']['id'] = 'field_opp_year';
  $handler->display->display_options['fields']['field_opp_year']['table'] = 'field_data_field_opp_year';
  $handler->display->display_options['fields']['field_opp_year']['field'] = 'field_opp_year';
  $handler->display->display_options['fields']['field_opp_year']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_opp_year']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Product Type */
  $handler->display->display_options['fields']['field_product_type']['id'] = 'field_product_type';
  $handler->display->display_options['fields']['field_product_type']['table'] = 'field_data_field_product_type';
  $handler->display->display_options['fields']['field_product_type']['field'] = 'field_product_type';
  $handler->display->display_options['fields']['field_product_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_product_type']['alter']['text'] = '[field_product_type]';
  $handler->display->display_options['fields']['field_product_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_product_type']['alter']['path'] = '/availabletechnologies/all?f[0]=field_product_type%3A[field_product_type-tid]';
  $handler->display->display_options['fields']['field_product_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_product_type']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Content: Patent Status */
  $handler->display->display_options['fields']['field_pat_status']['id'] = 'field_pat_status';
  $handler->display->display_options['fields']['field_pat_status']['table'] = 'field_data_field_pat_status';
  $handler->display->display_options['fields']['field_pat_status']['field'] = 'field_pat_status';
  $handler->display->display_options['fields']['field_pat_status']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_pat_status']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_pat_status']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pat_status']['multi_type'] = 'ul';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated';
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['name_1']['label'] = 'Last Updated By';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Workbench Moderation: Moderation links */
  $handler->display->display_options['fields']['moderation_actions']['id'] = 'moderation_actions';
  $handler->display->display_options['fields']['moderation_actions']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['moderation_actions']['field'] = 'moderation_actions';
  $handler->display->display_options['fields']['moderation_actions']['label'] = 'Actions';
  /* Sort criterion: Content: Opportunity Year (field_opp_year) */
  $handler->display->display_options['sorts']['field_opp_year_value']['id'] = 'field_opp_year_value';
  $handler->display->display_options['sorts']['field_opp_year_value']['table'] = 'field_data_field_opp_year';
  $handler->display->display_options['sorts']['field_opp_year_value']['field'] = 'field_opp_year_value';
  $handler->display->display_options['sorts']['field_opp_year_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_opp_year_value']['expose']['label'] = 'Opportunity Year';
  /* Sort criterion: Content: Reference Number (field_enumber) */
  $handler->display->display_options['sorts']['field_enumber_value']['id'] = 'field_enumber_value';
  $handler->display->display_options['sorts']['field_enumber_value']['table'] = 'field_data_field_enumber';
  $handler->display->display_options['sorts']['field_enumber_value']['field'] = 'field_enumber_value';
  $handler->display->display_options['sorts']['field_enumber_value']['expose']['label'] = 'Reference Number';
  /* Filter criterion: Content: Reference Number (field_enumber) */
  $handler->display->display_options['filters']['field_enumber_value']['id'] = 'field_enumber_value';
  $handler->display->display_options['filters']['field_enumber_value']['table'] = 'field_data_field_enumber';
  $handler->display->display_options['filters']['field_enumber_value']['field'] = 'field_enumber_value';
  $handler->display->display_options['filters']['field_enumber_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_enumber_value']['group'] = 1;
  $handler->display->display_options['filters']['field_enumber_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_enumber_value']['expose']['operator_id'] = 'field_enumber_value_op';
  $handler->display->display_options['filters']['field_enumber_value']['expose']['label'] = 'Reference Number';
  $handler->display->display_options['filters']['field_enumber_value']['expose']['operator'] = 'field_enumber_value_op';
  $handler->display->display_options['filters']['field_enumber_value']['expose']['identifier'] = 'field_enumber_value';
  $handler->display->display_options['filters']['field_enumber_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    4 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    8 => 0,
    4 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'abstract' => 'abstract',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/workbench/abstracts/all';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Abstracts by EIR';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $export['workbench_abstracts'] = $view;

  return $export;
}

<?php

/**
 * @file
 * ttc_content_type_abstract.hooks.inc
 * 
 * Contains all hooks for abstract nodes.
 */
function ttc_content_type_abstract_form_node_form_alter(&$form, &$form_state) {
  if($form['#id']=='abstract-node-form'){
    // hide machine-generated fields
    $form['field_opp_year']['#access'] = false;
    $form['field_opp_30day_warned']['#access'] = false;
    $form['field_xml']['#access'] = false;


    // hide not needed fields. These fields were asked to be deleted. we have hidden these fields so that we can restore them later if needed.

    $form['field_additional_patent_document']['#access'] = false;
    $form['field_list_intro_text']['#access'] = false;
    $form['field_notif']['#access'] = false;
    $form['field_formatted_email_list']['#access'] = false;
    $form['field_image']['#access'] = false;
    $form['field_opp_mode']['#access'] = false;




    foreach ($form['field_pat_status'][LANGUAGE_NONE] as $delta => $field) {
      if (is_numeric($delta)) {
        $form['field_pat_status']['und'][$delta]['field_add_pat_desc'] = false;
      }
    }



    foreach ($form['field_publications'][LANGUAGE_NONE] as $delta => $field) {
      if (is_numeric($delta)) {
        $form['field_publications'][LANGUAGE_NONE][$delta]['field_title'][LANGUAGE_NONE][0]['#prefix'] =
          "<div class='publication-citation-helptext'>" . $form['field_publications'][LANGUAGE_NONE][$delta]['field_title'][LANGUAGE_NONE][0]['#description']   . "</div>";

        $form['field_publications'][LANGUAGE_NONE][$delta]['field_title'][LANGUAGE_NONE][0]['#description'] = "";
        $form['field_publications'][LANGUAGE_NONE][$delta]['field_title']['#after_build'][] = '_ttc_content_type_abstract_hide_text_format';
      }
    }


    // disable old display fields
    _ttc_content_type_abstract_convert_display_field($form, 'field_opp_invs_text');
    _ttc_content_type_abstract_convert_display_field($form, 'field_opp_pubs_text');
    _ttc_content_type_abstract_convert_display_field($form, 'field_pat_status', 'field_text');

    $form['field_opp_description_text']['#after_build'][] = '_ttc_content_type_abstract_hide_text_format';
    $form['field_opp_commapp_text']['#after_build'][] = '_ttc_content_type_abstract_hide_text_format';
    $form['field_opp_compadv_text']['#after_build'][] = '_ttc_content_type_abstract_hide_text_format';
    $form['field_list_intro_text']['#after_build'][] = '_ttc_content_type_abstract_hide_text_format';
    // Limits contact list from contacts vocabulary to only active.
    _ttc_content_type_abstract_alter_contact_list($form, $form_state);


  }
}





function ttc_content_type_abstract_field_widget_form_alter(&$element, &$form_state, $context) {

  // Add a css class to widget form elements for all fields of type mytype.
  if ($context['field']['type'] == 'url' && $element['#bundle'] == 'field_publications') {
   $element['title']['#title'] = 'PMID#';
  }
}



function _ttc_content_type_abstract_hide_text_format(&$form) {
  $form[LANGUAGE_NONE][0]['format']['#access'] = false;
  return $form;
}


function _ttc_content_type_abstract_convert_display_field(&$form, $field, $subfield = false) {
  if(!$subfield) {
    $form[$field]['#disabled'] = true;
  }

  $und = array();
  
  for($ix = 0; $ix <= $form[$field]['und']['#max_delta']; $ix++) {
    if($subfield) {
      _ttc_content_type_abstract_convert_display_field($form[$field]['und'][$ix], $subfield);
      continue;
    }

    if(!empty($form[$field]['und'][$ix]['#default_value'])) {
      $und[$ix]['#markup'] = $form[$field]['und'][$ix]['#default_value'];
    }
    else if(!empty($form[$field]['und'][$ix]['value']['#default_value'])) {
      $und[$ix]['#markup'] = $form[$field]['und'][$ix]['value']['#default_value'];
    }
  }

  if(!$subfield) {
    $form[$field]['#access'] = false;

    $display = "${field}_display";

    $form[$display]['#type'] = 'fieldset';
    $form[$display]['#title'] =  $form[$field]['und']['#title'];
    $form[$display]['#weight'] =  $form[$field]['#weight'];
    $form[$display]['und'] = $und;

  }
}

function ttc_content_type_abstract_node_presave($node) {
  // declare static field sets
  static $inventor_fields = array(
    'first_name' => 'field_first_name',
    'middle_initial' => 'field_middle_initial',
    'last_name' => 'field_last_name',
    'suffix' => 'field_suffix',
    'division_name' => 'field_division_name',
    'url' => 'field_url'
  );

  static $publication_fields = array(
    'title' => 'field_title',
    'url' => 'field_url'
  );

  static $pat_status_fields = array(
    'field_application_number',
    'field_patent_authority',
    'field_patent_number',
    'field_patent_filing_date',
    'field_patent_issue_date',
    'field_add_pat_desc',
    'field_url'
  );

  // check for matching node type
  if ($node->type == 'abstract') {
    // if possible, retrieve the year from the enumber and set to the year field
    if (isset($node->field_enumber['und']['0']['value'])) {
      $enumber = $node->field_enumber['und']['0']['value'];
      $matches = array();
      $matched = preg_match('/.-...-(\d{4})/', $enumber, $matches);
      if ($matched) {
        $node->field_opp_year['und']['0']['value'] = $matches[1];
      } else {
        $node->field_opp_year['und']['0']['value'] = -1;
      }
    }

    // update display fields
    $inventors_values = _ttc_content_type_abstract_retrieve_values($node, 'field_inventors', $inventor_fields);
    $inventors_formatted = _ttc_content_type_abstract_format_inventors($inventors_values);
    _ttc_content_type_abstract_set_text($node, 'field_opp_invs_text', $inventors_formatted);

    $publications_values = _ttc_content_type_abstract_retrieve_values($node, 'field_publications', $publication_fields);
    $publications_formatted = _ttc_content_type_abstract_format_publications($publications_values);
    _ttc_content_type_abstract_set_text($node, 'field_opp_pubs_text', $publications_formatted);

    $status_values = _ttc_content_type_abstract_retrieve_values($node, 'field_pat_status', $pat_status_fields);
    $status_formatted = _ttc_content_type_abstract_format_status($status_values);
    _ttc_content_type_abstract_set_text($node, 'field_pat_status', $status_formatted, 'field_text');

  }

  // skip queueing items in draft or needs_review states
  $state = '';
  if(isset($node->workbench_moderation_state_new)) {
    $state = $node->workbench_moderation_state_new;
    if($state == 'draft' || $state == 'needs_review') {
      // clear the xml field and return.
      unset($node->field_xml[LANGUAGE_NONE]);
    }
    else {
      watchdog('ttc_content_type_abstract', "Adding %nid (%vid) in state '%state' to xml queue .",
      array('%nid' => $node->nid, '%vid' => $node->vid, '%state' => $state));
  
      // add this node to the cron queue to have its xml field filled
      _ttc_content_type_abstract_queue_xml($node);
    }
  }
  
}

function _ttc_content_type_abstract_retrieve_values($node, $collection, $subfields) {
  $collection_items = field_get_items('node', $node, $collection);

  if(!is_array($collection_items)) return false;

  $values = array();

  foreach($collection_items as $delta => $collection_item) {
    if(isset($collection_item['entity'])) {
      $entity = $collection_item['entity'];
    }
    else if(isset($collection_item['revision_id'])) {
      $entity = entity_revision_load('field_collection_item', $collection_item['revision_id']);
    }
    else if(isset($collection_item['value'])) {
      $entity = entity_load_single('field_collection_item', $collection_item['value']);
    }

    if(!$entity) {
      watchdog("ttc_content_type_abstract", "failed to load entity '%eid' in collection %collection", 
      array('%eid' => $collection_item['value'], '%collection' => $collection), WATCHDOG_WARNING, "node/$node->nid");

      continue;
    }

    foreach($subfields as $name => $subfield) {
      $items = field_get_items('field_collection_item', $entity, $subfield);

      if($items) {
        $display = array();
        if(strpos($subfield, 'date') !== false) {
          $display = array('settings' => array('format_type' => 'brief_date'));
        }

        foreach($items as $item) {
          $value = field_view_value('field_collection_item', $entity, $subfield, $item, $display);
          $values[$delta][$subfield][] = $value;
        }
      }
    }
  }

  return $values;
}

function _ttc_content_type_abstract_set_text($node, $field, $values, $subfield = false) {
  // clear existing values
  if($subfield === false) {
    unset($node->{$field}['und']);
  }

  foreach($values as $delta => $value) {
    if($subfield !== false){

      $entity = false;
      if(isset($node->{$field}['und'][$delta]['entity'])) {
        $entity = $node->{$field}['und'][$delta]['entity'];
      }
      if(!$entity && isset($node->{$field}['und'][$delta]['revision_id'])) {
        $entity = entity_revision_load('field_collection_item', $node->{$field}['und'][$delta]['revision_id']);
      }
      if(!$entity && isset($node->{$field}['und'][$delta]['value'])) {
        $entity = entity_load_single('field_collection_item', $node->{$field}['und'][$delta]['value']);
      }
  
      if($entity) {
        unset($entity->{$subfield}['und']);
        $entity->{$subfield}['und'][0]['value'] = $value;
        $entity->{$subfield}['und'][0]['format'] = 'filtered_html';

        $entity->save(true);
      }
    }
    else {
      $node->{$field}['und'][$delta]['value'] = $value;
      $node->{$field}['und'][$delta]['format'] = 'filtered_html';
    }
  }
}

function _ttc_content_type_abstract_format_inventors($values){
  $inventors = array();

  foreach($values as $delta => $inventor) {
    $parts = array();
    $org = false;

    // look up name and division
    if(isset($inventor['field_first_name'][0]['#markup'])) {
      $parts[] = $inventor['field_first_name'][0]['#markup'];
    }

    if(isset($inventor['field_middle_initial'][0]['#markup'])) {
      $parts[] = $inventor['field_middle_initial'][0]['#markup'];
    }

    if(isset($inventor['field_last_name'][0]['#markup'])) {
      $parts[] = $inventor['field_last_name'][0]['#markup'];
    }

    if(isset($inventor['field_suffix'][0]['#markup'])) {
      $parts[] = $inventor['field_suffix'][0]['#markup'];
    }

    if(isset($inventor['field_division_name'][0]['#markup'])) {
      $org = $inventor['field_division_name'][0]['#markup'];
    }

    $name = implode(' ', $parts);
    if(!empty($name)) {
      if(!empty($org))  $name = "$name ($org)";
    }
    else {
      if(!empty($org)) $name = $org;
    }

    // correct an empty attributes option, if present
    if(isset($inventor['field_url'][0]['#options']) &&
        $inventor['field_url'][0]['#options']['attributes'] === NULL) {
          $inventor['field_url'][0]['#options']['attributes'] = array();
    }

    // look up url, if any
    if(!empty($name)) {
      if(isset($inventor['field_url'][0]['#href'])) {
        // set the title of the url as the name before rendering
        $inventor['field_url'][0]['#title'] = $name;
        $inventors[$delta] = render($inventor['field_url'][0]);
      }
      else {
        $inventors[$delta] = $name;
      }
    }
    else if(isset($inventor['field_url'][0]['#href'])) {
        $inventors[$delta] = render($inventor['field_url'][0]);
    }
  }

  return array(implode(', ', $inventors));
}

function _ttc_content_type_abstract_format_publications($values){
  $publications = array();

  foreach($values as $delta => $publication) {
    $title = false;

    // look up name and division
    if(isset($publication['field_title'][0]['#markup'])) {
      $title = $publication['field_title'][0]['#markup'];
    }

    // correct an empty attributes option, if present
    if(isset($publication['field_url'][0]['#options']) &&
    $publication['field_url'][0]['#options']['attributes'] === NULL) {
      $publication['field_url'][0]['#options']['attributes'] = array();
    }

    // look up url, if any
    if(!empty($title)) {
      if(isset($publication['field_url'][0]['#href'])) {
        $end_p_pos = strripos($title, '</p>');

        if($end_p_pos !== false) {
          $publications[$delta] = substr_replace($title, ' [' . render($publication['field_url'][0]) .']', $end_p_pos, 0);
        }
        else {
          $publications[$delta] = $title . ' [' . render($publication['field_url'][0]) .']';
        }
      }
      else {
        $publications[$delta] = $title;
      }
    }
    else if(isset($publication['field_url'][0]['#href'])) {
      $publications[$delta] = render($publication['field_url'][0]);
    }
  }

  return $publications;
}

function _ttc_content_type_abstract_format_status($values){
  $statii = array();

  foreach($values as $delta => $status) {
    $application = false;

    // look up name and division
    if(isset($status['field_application_number'][0]['#markup'])) {
      $application = $status['field_application_number'][0]['#markup'];
    }
    
    if(isset($status['field_patent_filing_date'][0]['#markup'])) {
      $app_date = trim(drupal_html_to_text($status['field_patent_filing_date'][0]['#markup']));
      $application = $application ? "Provisional Application No. $application filed $app_date" : "Filed $app_date";
    }

    $patent = false;
    if(isset($status['field_patent_number'][0]['#markup'])) {
      $patent = $status['field_patent_number'][0]['#markup'];
    }

    if(isset($status['field_patent_issue_date'][0]['#markup'])) {
      $issue_date = trim(drupal_html_to_text($status['field_patent_issue_date'][0]['#markup']));
      $patent = $patent ? "$patent issued $issue_date" : "Issued $issue_date";
    }

    $parts = array();

    if(isset($status['field_patent_authority'][0]['#markup'])) {
      $parts[] = $status['field_patent_authority'][0]['#markup'];
    }

    if($application) {
      $parts[] = $patent ? "$application, $patent" : "$application";
    }
    else if($patent) {
      $parts[] = $patent;
    }

    if(isset($status['field_add_pat_desc'][0]['#markup'])) {
      $parts[] = $status['field_add_pat_desc'][0]['#markup'];
    }

    $collected = implode(' ', $parts);

    // correct an empty attributes option, if present
    if(isset($status['field_url'][0]['#options']) &&
        $status['field_url'][0]['#options']['attributes'] === NULL) {
      $status['field_url'][0]['#options']['attributes'] = array();
    }

    // look up url, if any
    if(!empty($collected)) {
      if(isset($status['field_url'][0]['#href'])) {
        // set the title of the url as the name before rendering
        $status['field_url'][0]['#title'] = $collected;

        $statii[$delta] = render($status['field_url'][0]);
      }
      else {
        $statii[$delta] = $collected;
      }
    }
    else if(isset($status['field_url'][0]['#href'])) {
        $statii[$delta] = render($status['field_url'][0]);
    }
  }

  return $statii;
}

/**
 * Callback to generate the xml for an abstract node and populate the related field.
 */
function _ttc_content_type_abstract_populate_xml($node) {
  // if the 'node' is instead the xml cache request, do that instead
  if($node == 'cache_xml') {
    ttc_content_type_abstract_cache_xml();
    return;
  }

  $nid = isset($node->nid) ? $node->nid : null;
  $vid = isset($node->vid) ? $node->vid : null;
  if(empty($nid) || empty($vid)) {
    watchdog('ttc_content_type_abstract', "Cannot generate xml: nid='%nid' vid='%vid'.",
      array('%nid' => $nid, '%vid' => $vid), WATCHDOG_ERROR);

      return;
  }

  // switch to the admin user
  global $user;
  $account = $user;
  $user = user_load(1);

  // clear the node's cache so that the view gets the latest version
  $xml = views_embed_view('abstracts_xml','abstract_xml', $nid, $vid);

  watchdog('ttc_content_type_abstract', "Generated xml for %nid (%vid):\n'%xml'",
    array('%nid' => $nid, '%vid' => $vid, '%xml' => $xml));

  preg_match('@\<Technology\>(.*)\</Technology\>@s', $xml, $matches);

  if(isset($matches[1])) {
    $transaction = db_transaction();
    try {
      //$node = node_load($nid);
      $update_node = new stdClass();
      $update_node->nid = $nid;
      $update_node->vid = $vid;
      $update_node->type = 'abstract';
      $update_node->field_xml[LANGUAGE_NONE]['0']['value'] = $matches[1];
      field_attach_presave('node', $update_node);
      field_attach_update('node', $update_node);
      entity_get_controller('node')->resetCache(array($nid));

    } catch (Exception $e) {
      $transaction->rollback();

      // switch back to the original user
      $user = $account;

      throw $e;
    }

  }

  // switch back to the original user
  $user = $account;

}

/**
* Specify a cron queue for filling xml info on abstract nodes after saving
*/
function ttc_content_type_abstract_cron_queue_info() {
  $queues['xml_generation'] = array(
    'worker callback' => '_ttc_content_type_abstract_populate_xml',
    'time' => 60,
  );
  return $queues;
}

/**
* Creates a queue item to generate the node's xml later
*/
function _ttc_content_type_abstract_queue_xml($node) {
  // create a queue item
  $queue = DrupalQueue::get('xml_generation');
  $queue->createItem($node);
}

/**
 * Builds a query object that finds each abstract's publiched or archived nid and vid, and also filters for
 * published items with send_to_ott set and for unpublished items in the archived state.  Can be extended 
 * to check for additional fields.
 */
function _ttc_content_type_abstract_build_current_query() {
  //This is the inner query to get the node, type and latest version.
  $history = db_select('workbench_moderation_node_history', 'h');
  
  // join on node id
  $history->join('node', 'n', 'n.nid = h.nid');
  
  //add conditions
  $history->condition('n.type', 'abstract')
    ->condition(db_or()
      ->condition(db_and()->condition('n.status', 1)->condition('h.state', 'published'))
      ->condition(db_and()->condition('n.status', 0)->condition('h.state', 'archived')))
    ->groupBy('h.nid');
  $history->addField('h', 'nid');
  $history->addField('h', 'state');
  $history->addField('n', 'type');
  $history->addExpression('max(n.vid)', 'vid');

  //This is used to filter the contents
  $fullQuery = db_select($history, 'h');

  // add 'send to ott' filter for pub
  $fullQuery->join('field_revision_field_send_to_ott', 'ott', 'ott.entity_id = h.nid AND ott.revision_id = h.vid');
  // filter for nodes with send_to_ott set or with in archived state
  $fullQuery->condition(db_or()->condition('ott.field_send_to_ott_value', '1')->condition('h.state', 'archived'));
  $fullQuery->addField('h', 'nid');
  $fullQuery->addField('h', 'type');
  $fullQuery->addField('h', 'vid');

  return $fullQuery;
}

/**
 * Limits contact list from contacts vocabulary to only active.
 *
 */

function _ttc_content_type_abstract_alter_contact_list(&$form, &$form_state){
  $current_options = $form['field_contact_auto'][LANGUAGE_NONE]['#options'];

  $name = 'contacts';
  $myvoc = taxonomy_vocabulary_machine_name_load($name);
  $tree = taxonomy_get_tree($myvoc->vid);
  foreach ($tree as $term) {

    $term =  taxonomy_term_load($term->tid);
    if(!isset($term->field_status[LANGUAGE_NONE]) ||$term->field_status[LANGUAGE_NONE][0]['value'] != 1) {
      unset($current_options[$term->tid]);
    }

  }
  $form['field_contact_auto'][LANGUAGE_NONE]['#options'] =  $current_options;
}


function ttc_content_type_abstract_node_validate($node, $form, &$form_state) {
  if ( $node->type == "abstract") {
    if(_ttc_content_type_abstract_enumber_exists($node->nid, $node->field_enumber[LANGUAGE_NONE][0]['value'])) {
      form_set_error('field_enumber', t('An abstract with the reference number already exists.'));
    }

    if(strlen($node->field_meta_long_desc[LANGUAGE_NONE][0]['value']) > 1024){
      form_set_error('field_meta_long_desc', t('Field Summary length exceeds character limit 1024'));
    }

  }
}


function _ttc_content_type_abstract_enumber_exists($current_nid, $e_number){


  $query1 = db_select('field_data_field_enumber', 'e')
    ->condition('e.entity_id', $current_nid, '!=')
    ->condition('e.field_enumber_value', $e_number, '=')
    ->fields('e', array('entity_id'))
    ->execute();
  $num_nodes = $query1->rowCount();


  $query2 = db_select('field_revision_field_enumber', 'er')
    ->condition('er.entity_id', $current_nid, '!=')
    ->condition('er.field_enumber_value', $e_number, '=')
    ->fields('er', array('entity_id'))
    ->execute();
  $num_nodes_revs = $query2->rowCount();

  if($num_nodes >  0 or $num_nodes_revs > 0 ){
    return true;
  }else{
    return false;
  }


}

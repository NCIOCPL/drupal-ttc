<?php

/**
 * @file
 * ttc_content_type_abstract.hooks.inc
 * 
 * Contains all hooks for abstract nodes.
 */
function ttc_content_type_abstract_form_node_form_alter(&$form, &$form_state) {
  // hide machine-generated fields
  $form['field_opp_year']['#access'] = false;
  $form['field_opp_list_lastsent']['#access'] = false;
  $form['field_opp_30day_warned']['#access'] = false;
  $form['field_formatted_email_list']['#access'] = false;

  // disable old display fields
  _ttc_content_type_abstract_convert_display_field($form, 'field_opp_invs_text');
  _ttc_content_type_abstract_convert_display_field($form, 'field_opp_pubs_text');
  _ttc_content_type_abstract_convert_display_field($form, 'field_pat_status', 'field_text');
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
	
    // Set the list of emails (listserv & manual entries, comma-separated) for the 
    // email blast rule.
    $node->field_formatted_email_list['und']['0']['value'] = _abstract_get_formatted_email_list($node);

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
}

function _ttc_content_type_abstract_retrieve_values($node, $collection, $subfields) {
  $collection_items = field_get_items('node', $node, $collection);

  $values = array();

  foreach($collection_items as $delta => $collection_item) {
    $entity = $collection_item['entity'];

    foreach($subfields as $name => $subfield) {
      $items = field_get_items('field_collection_item', $entity, $subfield);

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

  return $values;
}

function _ttc_content_type_abstract_set_text($node, $field, $values, $subfield = false) {
  // clear existing values
  if($subfield === false) {
    unset($node->{$field}['und']);
  }

  foreach($values as $delta => $value) {
    if($subfield !== false && isset($node->{$field}['und'][$delta]['entity'])) {
      unset($node->{$field}['und'][$delta]['entity']->{$subfield}['und']);
      $node->{$field}['und'][$delta]['entity']->{$subfield}['und'][0]['value'] = $value;
      $node->{$field}['und'][$delta]['entity']->{$subfield}['und'][0]['format'] = 'filtered_html';
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

    // look up url, if any
    if(!empty($name)) {
      if(isset($inventor['field_url'][0]['#href'])) {
        // set the title of the url as the name before rendering
        $inventor['field_url'][0]['#title'] = $name;

        $inventors[] = render($inventor['field_url'][0]);
      }
      else {
        $inventors[] = $name;
      }
    }
    else if(isset($inventor['field_url'][0]['#href'])) {
        $inventors[] = render($inventor['field_url'][0]);
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

    // look up url, if any
    if(!empty($title)) {
      if(isset($publication['field_url'][0]['#href'])) {
        $publications[] = $title . ' [' . render($publication['field_url'][0]) .']';
      }
      else {
        $publications[] = $title;
      }
    }
    else if(isset($publication['field_url'][0]['#href'])) {
      $publications[] = render($publication['field_url'][0]);
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
      $app_date = drupal_html_to_text($status['field_patent_filing_date'][0]['#markup']);
      $application = $application ? "Provisional Application No. $application filed $app_date" : "Filed $app_date";
    }

    if(isset($status['field_patent_number'][0]['#markup'])) {
      $patent = $status['field_patent_number'][0]['#markup'];
    }

    if(isset($status['field_patent_issue_date'][0]['#markup'])) {
      $issue_date = drupal_html_to_text($status['field_patent_issue_date'][0]['#markup']);
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

    // look up url, if any
    if(!empty($collected)) {
      if(isset($status['field_url'][0]['#href'])) {
        // set the title of the url as the name before rendering
        $status['field_url'][0]['#title'] = $collected;

        $statii[] = render($status['field_url'][0]);
      }
      else {
        $statii[] = $collected;
      }
    }
    else if(isset($status['field_url'][0]['#href'])) {
        $statii[] = render($status['field_url'][0]);
    }
  }

  return $statii;
}
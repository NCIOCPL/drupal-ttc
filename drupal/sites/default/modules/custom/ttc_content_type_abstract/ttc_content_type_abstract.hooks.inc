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
}

function ttc_content_type_abstract_node_presave($node) {
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
  }
}

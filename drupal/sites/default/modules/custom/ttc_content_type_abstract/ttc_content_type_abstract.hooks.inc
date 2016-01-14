<?php

/**
 * @file
 * ttc_content_type_abstract.hooks.inc
 * 
 * Contains all hooks for abstract nodes.
 */
function ttc_content_type_abstract_form_node_form_alter(&$form, &$form_state) {
  if (function_exists('dsm')) {
    dsm($form, 'node form');
  }
  
  // hide machine-generated fields
  $form['field_opp_year']['#access'] = false;
  $form['field_opp_list_lastsent']['#access'] = false;
  $form['field_opp_30day_warned']['#access'] = false;
  
  // generate formatted email list for email blast
  $form['field_notif']['und']['0']['field_formatted_email_list']['#access'] = false;
  $form['field_notif']['und']['0']['field_formatted_email_list']['und']['value']['#default_value'] = _format_abstract_emails($form);

  if (function_exists('dsm')) {  
    dsm($form['field_notif']['und']['0']['field_formatted_email_list']['und']['value']['#default_value'], 'All email recipients');
  }
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
  }
}

/*
* Get the values from the checked listserv box(es) and any manually entered emails, concatenate
* into one string, and format to comply with RFC 2822 for the Rules "Send mail" action.
*/
/**
TODO:
 - Clean up
 - Move into .module?
 - Remove DSM for email list
 - Format strings for rules 
 - Change field value in rules config
 */
function _format_abstract_emails($form) {
  $all_emails = array();

  // Get the 'email' field collection value from zero or more checked listserv fields
  if (isset($form['field_notif']['und']['0']['field_send_to']['und']['#default_value'])) {
    $listserv_tids = $form['field_notif']['und']['0']['field_send_to']['und']['#default_value'];
    foreach($listserv_tids as $listserv_tid) {
      if (isset($listserv_tid)) {
        $listserv_email = taxonomy_term_load($listserv_tid);
        array_push($all_emails, '<' . $listserv_email->field_email['und']['0']['email'] . '>');
      }
    }
  }
  
  // Get the value from any manually entered email addresses
  if (isset($form['field_notif']['und']['0']['field_notif_manual']['und'])) {
    $manual_emails = $form['field_notif']['und']['0']['field_notif_manual']['und'];
    foreach($manual_emails as $manual_email) {
      if (isset($manual_email['email']['#default_value'])) {
        array_push($all_emails, '<' . $manual_email['email']['#default_value'] . '>');
      }
    }
  }

  $formatted_emails = implode(",", $all_emails);
  return $formatted_emails;
}
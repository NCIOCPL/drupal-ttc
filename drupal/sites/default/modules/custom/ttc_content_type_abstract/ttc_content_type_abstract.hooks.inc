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
}
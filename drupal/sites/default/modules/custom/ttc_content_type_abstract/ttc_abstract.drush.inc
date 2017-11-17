<?php

/**
 * @file
 * TTC Abstract drush commands.
 */

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 */
function ttc_abstract_drush_command() {
    $items = array();

    // The 'abstract-set-sendto' command.
    $items['ttc-abstract-notif-sendto'] = array(
        'description' => "Sets all existing abstract nodes to use the given sendto term id.",
        'arguments' => array(
            'tid' => 'The id of the term to set into field_notif on all abstracts.',
        ),
        'options' => array(
            'start' => array(
                'description' => 'Comma delimited list of spreads.',
                'example-value' => '0',
            ),
            'span' => array(
                'description' => 'Comma delimited list of spreads.',
                'example-value' => '50',
            ),
            'limit' => array(
                'description' => 'Comma delimited list of spreads.',
                'example-value' => '1000',
            ),
        ),
        'examples' => array(
            'drush tans 79 --limit=10' => 'Update just the first 10 records.',
        ),
        'aliases' => array('tans'),
        // require full site
        'bootstrap' => 'DRUSH_BOOTSTRAP_FULL',
    );

    // The 'abstract-export-excel' command.
    $items['ttc-abstract-export-excel'] = array(
        'description' => "Generates an Excel document containing node field information.",
        'options' => array(
            /* 'start' => array(
              'description' => 'Comma delimited list of spreads.',
              'example-value' => '0',
              ),
              'span' => array(
              'description' => 'Comma delimited list of spreads.',
              'example-value' => '50',
              ), */
            'limit' => array(
                'description' => 'Comma delimited list of spreads.',
                'example-value' => '1000',
            ),
            'filename' => array(
                'description' => 'Path and filename of Excel export.',
                'example-value' => 'c:\tmp\abstracts.xls',
            ),
        ),
        'examples' => array(
            'drush taee --limit=10' => 'Export just the first 10 abstracts.',
        ),
        'aliases' => array('taee'),
        // require full site
        'bootstrap' => 'DRUSH_BOOTSTRAP_FULL',
    );

    // The 'abstract-import-excel' command.
    $items['ttc-abstract-import-excel'] = array(
        'description' => "Parses an Excel document to find and update listed nodes.",
        'options' => array(
            'nids' => array(
                'description' => 'Comma delimited list of node ids.',
                'example-value' => '1351,2000',
            ),
            'filename' => array(
                'description' => 'Filename of Excel import.',
                'example-value' => 'abstracts.xls',
            ),
            'trim-extras' => array(
                'description' => 'Remove extra field collections for nodes with present data.',
                'example-value' => 'true',
            ),
            'list-extras' => array(
                'description' => 'Lists nodes containing fields with extra entries vs. the data.',
                'example-value' => 'true',
            ),
        ),
        'examples' => array(
            'drush taie --limit=10' => 'Import just the first 10 abstracts.',
        ),
        'aliases' => array('taie'),
        // require full site
        'bootstrap' => 'DRUSH_BOOTSTRAP_FULL',
    );

    return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'. This hook is optional. If a command
 * does not implement this hook, the command's description is used instead.
 *
 * This hook is also used to look up help metadata, such as help
 * category title and summary.  See the comments below for a description.
 */
function ttc_abstract_drush_help($section) {
    switch ($section) {
        case 'drush:ttc-abstract-notif-sendto':
            return dt("This command will update or overwrite field_notif on all existing abstracts with the given term id.");
        case 'drush:ttc-abstract-export-excel':
            return dt("This command will export existing Abstract nodes to an Excel file.");
        case 'drush:ttc-abstract-import-excel':
            return dt("This command will import Abstract data from an Excel file.");

        // The 'title' meta item is used to name a group of
        // commands in `drush help`.  If a title is not defined,
        // the default is "All commands in ___", with the
        // specific name of the commandfile (e.g. sandwich).
        // Command files with less than four commands will
        // be placed in the "Other commands" section, _unless_
        // they define a title.  It is therefore preferable
        // to not define a title unless the file defines a lot
        // of commands.
        case 'meta:ttc_abstract:title':
            return dt("TTC Abstract commands");

        // The 'summary' meta item is displayed in `drush help --filter`,
        // and is used to give a general idea what the commands in this
        // command file do, and what they have in common.
        case 'meta:ttc_abstract:summary':
            return dt("Drush commands for working with TTC Abstract items.");
    }
}

/**
 * Implements drush_hook_COMMAND_validate().
 *
 * The validate command should exit with
 * `return drush_set_error(...)` to stop execution of
 * the command.  In practice, calling drush_set_error
 * OR returning FALSE is sufficient.  See drush.api.php
 * for more details.
 */
function drush_ttc_abstract_notif_sendto_validate($tid) {
    if (!is_numeric($tid)) {
        return drush_set_error('NON_NUMERIC_TID', dt('Please provide a numeric TID.'));
    }

    // load the term from the id
    $term = taxonomy_term_load($tid);

    if (!isset($term->vocabulary_machine_name) ||
            $term->vocabulary_machine_name != 'send_to_email_addresses') {
        return drush_set_error('WRONG_PARENT_VOCAB', dt("Term $tid does not belong to vocabulary 'send_to_email_addresses'."));
    }

    $start = drush_get_option('start', 0);
    $limit = drush_get_option('limit', 1000);
    $span = drush_get_option('span', 50);

    if (!is_numeric($start))
        return drush_set_error('NON_NUMERIC_START', dt('Please provide a numeric start option.'));
    if (!is_numeric($span))
        return drush_set_error('NON_NUMERIC_SPAN', dt('Please provide a numeric span option.'));
    if (!is_numeric($limit))
        return drush_set_error('NON_NUMERIC_LIMIT', dt('Please provide a numeric limit option.'));
}

/**
 * Implements drush_hook_COMMAND_validate().
 *
 * The validate command should exit with
 * `return drush_set_error(...)` to stop execution of
 * the command.  In practice, calling drush_set_error
 * OR returning FALSE is sufficient.  See drush.api.php
 * for more details.
 */
function drush_ttc_abstract_export_excel_validate() {
    // test loading of phpexcel
    $module = module_load_include('inc', 'phpexcel');

    if ($module === FALSE) {
        return drush_set_error('PHPEXCEL_MISSING', dt('Unable to load PHPExcel library.'));
    }

    drush_log("Found PHPExcel library at $module", 'ok');

    $limit = drush_get_option('limit', -1);

    if (!is_numeric($limit))
        return drush_set_error('NON_NUMERIC_LIMIT', dt('Please provide a numeric limit option.'));
}

/**
 * Implements drush_hook_COMMAND_validate().
 *
 * The validate command should exit with
 * `return drush_set_error(...)` to stop execution of
 * the command.  In practice, calling drush_set_error
 * OR returning FALSE is sufficient.  See drush.api.php
 * for more details.
 */
function drush_ttc_abstract_import_excel_validate() {
    // test loading of phpexcel
    $module = module_load_include('inc', 'phpexcel');

    if ($module === FALSE) {
        return drush_set_error('PHPEXCEL_MISSING', dt('Unable to load PHPExcel library.'));
    }

    drush_log("Found PHPExcel library at $module", 'ok');

    $nid_list = drush_get_option('nids', '-1');
    $nids = explode(',', $nid_list);

    foreach($nids as $nid) {
        if (!is_numeric($nid)) {
            return drush_set_error('NON_NUMERIC_NID', dt('Non-numeric nid of %nid found in input string %nid_list.',
            array('%nid' => $nid, '%nid_list' => $nid_list)));
        }
    }
}

/**
 * Implements drush_hook_COMMAND().
 *
 * The command callback is where the action takes place.
 *
 * The function name should be same as command name but with dashes turned to
 * underscores and 'drush_commandfile_' prepended, where 'commandfile' is
 * taken from the file 'commandfile.drush.inc', which in this case is
 * 'sandwich'. Note also that a simplification step is also done in instances
 * where the commandfile name is the same as the beginning of the command name,
 * "drush_example_example_foo" is simplified to just "drush_example_foo".
 * To also implement a hook that is called before your command, implement
 * "drush_hook_pre_example_foo".  For a list of all available hooks for a
 * given command, run drush in --debug mode.
 *
 * If for some reason you do not want your hook function to be named
 * after your command, you may define a 'callback' item in your command
 * object that specifies the exact name of the function that should be
 * called.
 *
 * In this function, all of Drupal's API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * @see drush_invoke()
 * @see drush.api.php
 */
function drush_ttc_abstract_notif_sendto($tid) {
    $start = drush_get_option('start', 0);
    $limit = drush_get_option('limit', 1000);
    $span = drush_get_option('span', 50);

    $pos = $start;
    $found = 0;
    do {
        if (($pos + $span) > $limit) {
            $span = $limit - $pos;
        }

        $found = _ttc_abstract_reset_notify_term($tid, $pos, $span);
        $pos += $found;
    } while (($limit > $pos) && ($found >= $span));

    drush_log("Parsed $pos abstract nodes.", 'ok');

    return;
}

function _ttc_abstract_reset_notify_term($tid, $start = 0, $length = 10) {
    drush_log("Finding $length nodes, beginning from $start", 'notice');

    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'abstract')
            ->range($start, $length);

    $result = $query->execute();

    if (isset($result['node'])) {
        $nids = array_keys($result['node']);

        drush_log("Found " . sizeof($nids) . ' abstract nodes');

        $updated_count = 0;
        $empty_count = 0;
        $skipped_count = 0;
        $existing_count = 0;

        foreach ($nids as $nid) {
            $wrapper = entity_metadata_wrapper('node', $nid, array('bundle' => 'abstract'));

            $notif_raw = $wrapper->field_notif->value();

            if (empty($notif_raw)) {
                $empty_count++;

                // Create a new field collection and set it to the node
                $notif_item = entity_create('field_collection_item', array('field_name' => 'field_notif'));
                $notif_item->setHostEntity('node', $wrapper->value());

                // create wrapper for item
                $notif_wrapper = entity_metadata_wrapper('field_collection_item', $notif_item, array('bundle' => 'field_notif'));
            } else {
                $notif_wrapper = entity_metadata_wrapper('field_collection_item', $notif_raw, array('bundle' => 'field_notif'));

                if ($notif_wrapper->field_send_to[0]->value()->tid == $tid) {
                    $skipped_count++;
                    continue;
                }

                $existing_count++;
            }

            try {
                // set field_send_to
                $notif_wrapper->field_send_to[0] = $tid;

                // save field and node wrappers
                $notif_wrapper->save();
                $wrapper->save();

                $updated_count++;
            } catch (Exception $e) {
                drush_log('Exception: ' . $e->getMessage() . '\n' . $e->getTraceAsString(), 'error');
            }
        }

        if ($empty_count)
            drush_log("Found " . $empty_count . ' empty abstract nodes');
        if ($existing_count)
            drush_log("Found " . $existing_count . ' abstract nodes with different term already set');
        if ($updated_count)
            drush_log("Updated " . $updated_count . ' abstract nodes');
        if ($skipped_count)
            drush_log("Skipped " . $skipped_count . ' abstract nodes with term already set');

        return sizeof($nids);
    }
}

/**
 * Implements drush_hook_COMMAND().
 *
 * The command callback is where the action takes place.
 *
 * The function name should be same as command name but with dashes turned to
 * underscores and 'drush_commandfile_' prepended, where 'commandfile' is
 * taken from the file 'commandfile.drush.inc', which in this case is
 * 'sandwich'. Note also that a simplification step is also done in instances
 * where the commandfile name is the same as the beginning of the command name,
 * "drush_example_example_foo" is simplified to just "drush_example_foo".
 * To also implement a hook that is called before your command, implement
 * "drush_hook_pre_example_foo".  For a list of all available hooks for a
 * given command, run drush in --debug mode.
 *
 * If for some reason you do not want your hook function to be named
 * after your command, you may define a 'callback' item in your command
 * object that specifies the exact name of the function that should be
 * called.
 *
 * In this function, all of Drupal's API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * @see drush_invoke()
 * @see drush.api.php
 */
function drush_ttc_abstract_export_excel() {
    $limit = drush_get_option('limit', 50);

    drush_log("Export Excel called with a limit of $limit", 'ok');

    // Store the file in sites/default/files
    $dir = file_stream_wrapper_get_instance_by_uri('public://')->realpath();
    $filename = drush_get_option('filename', 'abstracts.xls');
    $path = "$dir/$filename";

    module_load_include('inc', 'phpexcel');
    $data = array();
    $headers = array();
    $registry = array();
    // First worksheet
    // Get the nodes
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'abstract');
    if ($limit > 0) {
        $query->range(0, $limit);
    }

    $result = $query->execute();

    if (isset($result['node'])) {
        $count = sizeof($result['node']);
        $abstract_nids = array_keys($result['node']);
        $abstract_items = entity_load('node', $abstract_nids);
        $headers = array();
        $data = array();

        _build_field_sheet($headers, $data, $abstract_items, 'field_opp_invs_text', 
                'Inventors', 'field_inventors', 'field_collection_item',
                array('field_first_name', 'field_last_name', 'field_url|value',
                    'field_is_lead', 'field_division_name'), 10);
        
        _build_field_sheet($headers, $data, $abstract_items, 'field_opp_pubs_text', 
                'Publications', 'field_publications', 'field_collection_item', 
                array('field_title', 'field_url|value', 'field_url|title'),
                 10);

        _build_field_sheet($headers, $data, $abstract_items, 'field_pat_status', 
                'Patent Status', 'field_pat_status', 'field_collection_item', 
                array('field_application_number', 'field_patent_authority', 'field_patent_number', 
                'field_patent_filing_date', 'field_patent_issue_date', 'field_is_related_patent'), 
                1);

        drush_log("Generated data for $count nodes.  Found headers:", 'ok');
        print_r($headers);
    }

    // Use the .xls format
    $options = array('format' => 'xls');
    $export_result = phpexcel_export($headers, $data, $path, $options);
    if ($export_result == PHPEXCEL_SUCCESS) {
        drush_log("Successfully exported Excel file to $path", 'ok');
    } else {
        drush_log("Failed to export Excel file with error $export_result", 'error');
    }

    return;
}

function _build_field_sheet(&$headers, &$data, $nodes, $field_name, $field_label, $dest_field, $input_type, $input_fields, $input_copies) {
    // set up column indexes
    $field_sheet = array();

    foreach ($nodes as $node) {
        foreach ($node->$field_name as $lang => $lang_entries) {
            foreach ($lang_entries as $ix => $entry) {
                $row = array();
                $row[] = $node->nid;
                $row[] = $node->title;
                $value = $entry['value'];
                if($field_name == 'field_pat_status') {
                    $entity = field_collection_item_load($value);
                    if($entity) {
                        $wrapper = entity_metadata_wrapper('field_collection_item', $entity);
                        $value = trim($wrapper->field_text->value());
                        if(empty($value)) {
                            // empty text field; skip this row.
                            continue;
                        }
                        $row[] = $value;
                        unset($wrapper);
                        unset($entity);
                    }
                    else {
                        // no status found
                        drush_log("No patent status found for nid $node->nid and status id $value", 'warning');
                        continue;
                    }
                }
                else {
                    $row[] = trim($value);
                }

                // create empty rows to space out dest_field and input_type columns
                for ($input_ix = 0; $input_ix < $input_copies; $input_ix++) {
                    foreach ($input_fields as $input_field) {
                        $row[] = "";
                    }
                }

                $row[] = $dest_field;
                $row[] = $input_type;

                $field_sheet[] = $row;
            }
        }
    }

    $data[$field_label] = $field_sheet;
    $headers[$field_label] = array('nid', 'title', $field_label);
    // add the specified number of input field copies
    for ($input_ix = 0; $input_ix < $input_copies; $input_ix++) {
        foreach ($input_fields as $input_field) {
            $headers[$field_label][] = "$input_ix|$input_field";
        }
    }

    $headers[$field_label][] = 'dest_field';
    $headers[$field_label][] = 'input_type';
}

/**
 * Implements drush_hook_COMMAND().
 */
function drush_ttc_abstract_import_excel() {
    $nid_list = drush_get_option('nids', '');
    $nids = array();
    if(!empty($nid_list)) {
        $nids = explode(',', $nid_list);
    }

    // Store the file in sites/default/files
    $dir = file_stream_wrapper_get_instance_by_uri('public://')->realpath();
    $filename = drush_get_option('filename', 'abstracts.xls');
    $path = "$dir/$filename";

    //drush_log("Import Excel called with a filename of $path", 'ok');

    module_load_include('inc', 'phpexcel');
    $result = phpexcel_import($path);
    $data = array();

    if (is_array($result)) {
        foreach ($result as $pageno => $page) {
            foreach ($page as $rowno => $row) {
                //drush_log("Checking row $rowno of page $pageno:", 'ok');
                _import_parse_row($row, $data, $nids);
            }
        }
    } else {
        drush_log(t("Failed to load Excel file at path $path."), 'error');
    }
    
    // if any data exists, import it.
    if(!empty($data)) {
        _import_node_data($data);
    }
    else {
        drush_log("No node data found.", "warning");
    }
}

function _import_parse_row($row, &$data, $nids) {
    $nid = null;
    $dest_field = null;
    $input_type = null;
    $values = array();
    
    foreach($row as $key => $value) {
        $trimmed_value = trim($value);
        
        if(empty($trimmed_value)) continue;
        
        switch($key) {
            case "nid":
                // skip this row if nids is not empty and this nid is not listed
                if(!empty($nids) && !in_array($value, $nids)) {
                    drush_log("Skipping nid $value, not present in nid list.", 'debug');
                    return;
                }

                // falls through intentionally if nid is not rejected
            case "dest_field":
            case "input_type":
                $$key = $value;
                break;
            default:
                $key_parts = explode('|', $key);
                $parts_length = sizeof($key_parts);
                $last_part = $parts_length - 1;
                // if there's a path to a field value...
                if($parts_length > 1) {
                    $path = &$values;
                    foreach($key_parts as $index => $key_part) {
                        // if this is not the last part, then ensure the array path to the desired value can exist.
                        if($index < $last_part ) {
                            if(!isset($path[$key_part])) {
                                $path[$key_part] = array();
                            }
                            $path = &$path[$key_part];
                        }
                        // if this is the last item, then set the final key to the value.
                        else {
                            $path[$key_part] = $value;
                        }
                    }
                }
                break;
        }
    }
    
    // combine values with existing node values (if any)
    if($nid != null && !empty($values)) {
        $data[$nid][$dest_field]['input_type'] = $input_type;
        foreach($values as $value) {
            $data[$nid][$dest_field]['values'][] = $value;
        }
    }
}

function _import_node_data($data) {
    $list_extras = drush_get_option('list-extras', false);
    $trim_extras = drush_get_option('trim-extras', false);

    $failed_nids = array();
    $failed_items = array();
    $failed_item_count = 0;

    foreach($data as $nid => $fields) {
        try {
            drush_log("Starting node $nid", 'debug');
            $node = node_load($nid);

            if($node === false) {
                drush_log("Could not load node $nid", 'warning');
                continue;
            }
            
            foreach($fields as $dest_field => $datum) {
                $input_type = $datum['input_type'];
                $values = $datum['values'];
                $value_count = sizeof($values);

                drush_log("Importing $value_count values into $dest_field of type $input_type on node $nid", 'debug');

                // create and save entities without regard to existing entities first
                $fc_items = array();
                foreach($values as $ix => $value_map) {
                    try {
                        //create the field collection if needed
                        $eid = false;
                        $fc_item = false;
                        
                        // only preserve patent status items, as there's data there not set by this import
                        if($dest_field == 'field_pat_status' && isset($node->{$dest_field}[LANGUAGE_NONE][$ix]['value'])) {
                            $eid = $node->{$dest_field}[LANGUAGE_NONE][$ix]['value'];
                            $vid = $node->{$dest_field}[LANGUAGE_NONE][$ix]['revision_id'];
                            if($vid) {
                                $fc_item = entity_revision_load('field_collection_item', $vid);
                            }
                            else {
                                $fc_item = entity_load_single('field_collection_item', $eid);
                            }

                            if(!$fc_item) {
                                drush_log("FAILED to load $dest_field collection! (EID $eid, VID $vid).", 'warning');
                            }
                            else {
                                drush_log("USING EXISTING $dest_field item at delta $ix with id '$fc_item->item_id', revision '$fc_item->revision_id'.", 'notice');
                            }
                        }

                        if(!$fc_item) {
                            drush_log("CREATING NEW $dest_field item at delta $ix on node $nid.", 'notice');
                            
                            $fc_item = entity_create('field_collection_item', 
                                array('field_name' => $dest_field));
                            $fc_item->setHostEntity('node', $node, LANGUAGE_NONE, false);
                        }

                        if(!$eid) $eid = 'new';

                        $hostType = $fc_item->hostEntityType();
                        $delta = $fc_item->delta();
                        drush_log("Collection $dest_field (eid '$eid', delta '$delta') has host type '$hostType'", notice);

                        foreach($value_map as $field => $value) {
                            $field_info = field_info_field($field);
                            $max_length = false;
                            if(isset($field_info['settings']['max_length'])) {
                                $max_length = $field_info['settings']['max_length'];
                            }

                            if($field == 'field_title') {
                                $value = array('value' => $value, 'format' => 'filtered_html');
                            }

                            // append the rest of the date stamp format for date fields
                            if($field == 'field_patent_filing_date' ||
                                    $field == 'field_patent_issue_date') {
                                $value.='T00:00:00';
                            }

                            // limit field lengths
                            if(is_array($value)) {
                                foreach($value as $key => $sub_value) {
                                    if($max_length && strlen($sub_value) > $max_length) {
                                        drush_log("Truncating ${field}[$key] in ${dest_field}[$ix] on node $nid, value longer than max of $max_length", 'warning');
                                        $sub_value = substr($sub_value, 0, $max_length);
                                    }

                                    drush_log("Set ${field}[$key] in ${dest_field}[$ix] (field collection item '$eid') on node $nid to $sub_value", 'debug');
                                    $fc_item->{$field}[LANGUAGE_NONE][0][$key] = $sub_value;
                                }
                            }
                            else {
                                if($max_length && strlen($value) > $max_length) {
                                    drush_log("Truncating $field in ${dest_field}[$ix] on node $nid, value longer than max of $max_length", 'warning');
                                    $value = substr($value, 0, $max_length);
                                }
                                
                                drush_log("Set $field in ${dest_field}[$ix] (entity $eid) on node $nid to $value", 'debug');
                                $fc_item->{$field}[LANGUAGE_NONE][0]['value'] = $value;
                            }
                        }

                        // save this wrapper and keep it for setting to node wrapper later
                        drush_log("Saving ${dest_field}[$ix] (eid '$eid') on node $nid.", 'debug');
                        $fc_item->save(true);

                        $hostType = $fc_item->hostEntityType();
                        $delta = $fc_item->delta();
                        
                        $fc_items[] = $fc_item;

                        drush_log("Saved ${dest_field}[$delta] (EID '$fc_item->item_id', VID '$fc_item->revision_id', host type '$hostType') on node $nid", 'notice');
                    }
                    catch(Exception $e) {
                        drush_log("Failed updating $dest_field $ix for field collection $input_type.", 'error');
                        drush_log("Error message: " . $e->getMessage(), 'warning');
                        drush_log($e->getTraceAsString(), 'warning');
                        drush_log("Attempted values: ", 'warning');
                        var_dump($value_map);

                        $failed_items[$nid][$dest_field][] = $delta;
                        $failed_item_count++;
                        continue;
                    }
                }

                // apply the wrappers to the node wrapper's dest field
                if(!empty($fc_items)) {
                    // clear and refill node field values
                    unset($node->{$dest_field}[LANGUAGE_NONE]);

                    foreach($fc_items as $fc_item) {
                        $node->{$dest_field}[LANGUAGE_NONE][] = array(
                            'value' => $fc_item->item_id,
                            'revision_id' => $fc_item->revision_id
                        );
                    }
                }
            }

            node_save($node);
            drush_log("Saved node $nid", 'ok');
        }
        catch(Exception $e) {
            drush_log("Failed loading or saving node $nid", 'error');
            drush_log("Error message: " . $e->getMessage(), 'error');
            $failed_nids[] = $nid;
            continue;
        }
    }

    drush_log("Failed the following nodes:", 'warning');
    var_dump($failed_nids);

    drush_log("Failed $failed_item_count field collection items:", 'warning');
    var_dump($failed_items);
}

function _import_check_row($row) {
    if (isset($row['nid'])) {
        $nid = $row['nid'];
        $node = node_load($nid);

        if ($node === FALSE) {
            drush_log("Failed to load node $nid", 'warning');
            return FALSE;
        }

        // drush_log("Loaded node $nid.", 'ok');

        foreach ($row as $header => $value) {
            $value = trim($value);
            if (strlen($value) == 0) {
                // drush_log("Skipping empty value for column $header of node $nid", 'ok');
                continue;
            }

            // check header for entity-containing fields
            $field_parts = explode("!", $header);
            $current_element = null;
            $entity = $node;

            foreach ($field_parts as $part_ix => $field_part) {
                $field_path = explode('|', $field_part);

                // if current element is set (as it would be if a loop has completed)
                // then load it as an entity
                if ($current_element != null) {
                    // retreive the entity type from the start of the path
                    $entity_type = array_shift($field_path);
                    $entity = entity_revision_load($entity_type, $current_element);
                    if ($entity !== FALSE) {
                        //drush_log("Loaded $entity_type entity for path $header in node $nid", 'ok');
                    } else {
                        drush_log("Failed to load $entity_type entity with revision $current_element in path $header.", 'warning');
                        break;
                    }
                }

                // retrieve the field name to find in the current entity
                $field_name = array_shift($field_path);

                //drush_log("Looking for field $field_name in current entity.", 'ok');
                // select current field from entity
                if (isset($entity->$field_name)) {
                    $current_element = $entity->$field_name;
                } else {
                    drush_log("Cannot find field $field_name in current entity.", 'warning');
                    break;
                }

                foreach ($field_path as $path_fragment) {
                    if (isset($current_element[$path_fragment])) {
                        // drush_log("Found fragment $path_fragment in $header.", 'ok');
                        $current_element = $current_element[$path_fragment];
                    } else {
                        drush_log("Could not find $path_fragment in $header of node $nid.", 'warning');
                        unset($current_element);
                        break;
                    }
                }
            }

            if (isset($current_element)) {
                $comp = strcmp(trim($current_element), $value);

                if ($comp !== 0) {
                    drush_log("Value mismatch at path $header for node $nid, comp = $comp", 'ok');
                } else {
                    // drush_log("Value matched at path $header for node $nid.", 'ok');
                }
            }
        }
    }
}

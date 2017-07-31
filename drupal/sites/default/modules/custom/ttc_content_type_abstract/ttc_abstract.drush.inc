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
                null, 'Inventors', 
                'field_inventors', 'field_collection_item',
                array('field_first_name', 'field_last_name', 'field_url|value',
                    'field_is_lead', 'field_division_name'), 10);
        
        _build_field_sheet($headers, $data, $abstract_items, 'field_opp_pubs_text', 
                null, 'Publications', 
                'field_publications', 'field_collection_item', 
                array('field_title', 'field_url|value', 'field_url|title'),
                 10);

        _build_field_sheet($headers, $data, $abstract_items, 'field_pat_status', 
                array('field_patent_status', 'field_text'), 'Patent Status', 
                'field_pat_status', 'field_collection_item', 
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

function _build_field_sheet(&$headers, &$data, $nodes, $field_name, $collection_fields, $field_label, 
        $dest_field, $input_type, $input_fields, $input_copies) {
    // set up column indexes
    $field_sheet = array();

    foreach ($nodes as $node) {
        foreach ($node->$field_name as $lang => $lang_entries) {
            foreach ($lang_entries as $ix => $entry) {
                $row = array();
                $row[] = $node->nid;
                $row[] = $node->title;
                if(!is_array($collection_fields)) {
                    $row[] = trim($entry['value']);
                }
                else {
                    // load the field collection represented by this value, and then retrieve the given field
                    $entity_id = $entry['value'];
                    $collection = entity_load_single('field_collection_item', $entity_id);
                    $wrapper = entity_metadata_wrapper('field_collection_item', $collection);
                    foreach($collection_fields as $field) {
                        $value = '';
                        try {
                            switch ($field) {
                                case 'field_patent_status':
                                    $value = $wrapper->field_patent_status->name->value();
                                    break;
                                
                                case 'field_text':
                                    $value = $wrapper->field_text->value();
                                    break;
                            }
                        }
                        catch (Exception $e) {
                            drush_log("Failed to access field $field on node $node->nid", 'error');
                            drush_log($e->getMessage(), 'error');
                        }
                        $row[] = trim($value);
                    }
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
    $headers[$field_label] = array('nid', 'title');
    if(is_array($collection_fields)) {
        $headers[$field_label] = array_merge($headers[$field_label], $collection_fields);
    }
    else {
        $headers[$field_label][] = $field_label;
    }
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
                    drush_log("Skipping nid $value, not present in nid list.", 'notice');
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

    foreach($data as $nid => $fields) {
        $node = node_load($nid);
        $node_wrapper = entity_metadata_wrapper('node', $node, array('bundle' => 'abstract'));
        $node_prop_info = $node_wrapper->getPropertyInfo();
        
        foreach($fields as $dest_field => $datum) {
            $input_type = $datum['input_type'];
            $values = $datum['values'];
            $value_count = sizeof($values);

            drush_log("Importing $value_count values into $dest_field of type $input_type on node $nid", 'notice');

            if(isset($node_prop_info[$dest_field])) {
                // handle any bad entries currently in the field
                _field_clear_errors($node_wrapper, $dest_field);

                $entity_count = $node_wrapper->$dest_field->count();
                drush_log("Found $entity_count entities in $dest_field on node $nid", 'notice');

                // create and save entities without regard to existing entities first
                foreach($values as $ix => $value_map) {
                    foreach($value_map as $field => $value) {
                        try {
                            $eid = 'new';
                            //create the field collection if needed
                            if(!$node_wrapper->$dest_field->offsetExists($ix)) {
                                drush_log("Creating new $dest_field item at delta $ix on node $nid.", 'notice');
                                
                                $fc_item = entity_create('field_collection_item', 
                                    array('field_name' => $dest_field));
                                $fc_item->setHostEntity('node', $node, LANGUAGE_NONE, false);

                                $node_wrapper->$dest_field->offsetSet($ix, $fc_item);
                            }
                            else {
                                $eid = $node_wrapper->{$dest_field}[$ix]->getIdentifier();
                                drush_log("Loading entity $eid from $dest_field $ix on node $nid", 'notice');
                                $collection_items = entity_load('field_collection_item', array($eid), array(), true);
                                $fc_item = reset($collection_items);
                            }

                            if(is_array($value)) {
                                foreach($value as $key => $sub_value) {
                                    drush_log("Set ${field}[$key] in ${dest_field}[$ix] (entity $eid) on node $nid to $sub_value", 'notice');
                                    $fc_item->{$field}[LANGUAGE_NONE][0][$key] = $sub_value;
                                }
                            }
                            else {
                                drush_log("Set $field in ${dest_field}[$ix] (entity $eid) on node $nid to $value", 'notice');
                                $fc_item->{$field}[LANGUAGE_NONE][0]['value'] = $value;
                            }
                            $fc_item->save(TRUE);

                            
                        }
                        catch(Exception $e) {
                            drush_log("Failed setting $field in $dest_field $ix to $value for field collection $input_type.", 'warning');
                            echo $e;
                            return;
                        }
                    }
                }
                
                if($list_extras != false || $trim_extras != false) {
                    // find any extra entities and delete them
                    foreach($node_wrapper->$dest_field as $delta => $field_wrapper) {
                        $entity_id = $field_wrapper->getIdentifier();
                        
                        if(!isset($values[$delta])) {
                            if($trim_extras == false) {
                                drush_log("Found extra entry $delta for $dest_field on node $nid with entity id $entity_id", 'ok');
                            }
                            else {
                                // delete the current field collection item.
                                drush_log("Deleting extra entry $delta for $dest_field on node $nid with entity id $entity_id", 'ok');

                                $fc_item = entity_load_single($input_type, $entity_id);
                                $fc_item->delete();

                                $node_wrapper->$dest_field->offsetUnset($delta);
                            }
                        }
                    }
                }
            }
            else {
                drush_log("Could not find target field $dest_field in abstract $nid", 'warning');
            }
        }

        $node_wrapper->save();
    }
}

function _field_clear_errors($node_wrapper, $field_name) {
    $nid = $node_wrapper->getIdentifier();
    $changed = false;
    try {
        // load existing entity or create new one.
        foreach ($node_wrapper->$field_name->getIterator() as $delta => $fc_wrapper) {
            if($fc_wrapper == null) {
                drush_log("Null field wrapper at delta $delta in field $field_name on node $nid.", "warning");
                $node_wrapper->$field_name->offsetUnset($delta);
                drush_log("Unset delta $delta in $field_name on node $nid.", 'ok');
                $changed = true;
                continue;
            }
            else if($fc_wrapper->value() == null) {
                drush_log("Null field value at delta $delta in field $field_name on node $nid.", "warning");
                $node_wrapper->$field_name->offsetUnset($delta);
                drush_log("Unset delta $delta in $field_name on node $nid.", 'ok');
                $changed = true;
                continue;
            }
        }

        if($changed) {
            drush_log("Saving node $nid after clearing null entries in $field_name", 'ok');
            $node_wrapper->save();
        }
    }
    catch (Exception $e) {
        drush_log("_field_clear_errors(): Failed accessing item $delta in $field_name on node $nid", 'warning');
        echo $e;
    }
}

function _wrapper_debug($w, $k) {
  $values = array();
  foreach ($w->getPropertyInfo() as $key => $val) {
      if($k == $key) {
          $values[$key] = $w->$key->value();
      }
      else {
          $values[$key] = 'found';
      }
  }
  return $values;
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

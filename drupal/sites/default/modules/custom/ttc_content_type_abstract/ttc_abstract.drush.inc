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

    // The 'abstract-set-sendto' command.
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
        ),
        'examples' => array(
            'drush taee --limit=10' => 'Export just the first 10 abstracts.',
        ),
        'aliases' => array('taee'),
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
        $abstract_nids = array_keys($result['node']);
        $abstract_items = entity_load('node', $abstract_nids);

        // set up column indexes
        $nid_ix = _get_column_index($registry, 'nid');
        $title_ix = _get_column_index($registry, 'title');

        $field_name = 'field_opp_invs_text';
        foreach ($abstract_items as $abstract) {
            $abstract_row = array();
            $abstract_row[$nid_ix] = $abstract->nid;
            $abstract_row[$title_ix] = $abstract->title;

            _fill_field_column($registry, $abstract_row, $abstract, 'field_opp_invs_text');
            _fill_field_column($registry, $abstract_row, $abstract, 'field_opp_pubs_text');

            $data[] = $abstract_row;
        }

        $headers = $registry;
    }

    var_dump($headers);
    var_dump($data);

    // Store the file in sites/default/files
    $dir = file_stream_wrapper_get_instance_by_uri('public://')->realpath();
    $filename = 'export1.xls';
    $path = "$dir/$filename";
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

function _get_column_index(&$registry, $name) {
    $index = array_search($name, $registry);
    if ($index === FALSE) {
        $registry[] = $name;

        $index = array_search($name, $registry);
    }

    return $index;
}

function _fill_field_column(&$registry, &$row, $node, $field_name) {
    foreach ($node->$field_name as $lang => $lang_entries) {
        foreach ($lang_entries as $ix => $entry) {
            $path = "$field_name|$lang|$ix|value";
            $path_ix = _get_column_index($registry, $path);

            $row[$path_ix] = trim($entry['value']);
        }
    }
}

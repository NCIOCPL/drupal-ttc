<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php 
try {
    $writer = new XMLWriter();
    $writer->openMemory();
    $writer->setIndent(true);

    foreach($row->field_field_pat_status as $delta => $status) {
        if(isset($status['raw']['value'])) {
            $status_id = $status['raw']['value'];
            $status_item = entity_load_single('field_collection_item', $status_id);
            if($status_item) {
                $wrapper = entity_metadata_wrapper('field_collection_item', $status_item);

                $is_related = $wrapper->field_is_related_patent->value();
                $patent_status_term = $wrapper->field_patent_status->value();
                $patent_status = isset($patent_status_term->name) ? $patent_status_term->name : '';
                $application_number = $wrapper->field_application_number->value();
                $patent_authority = $wrapper->field_patent_authority->value();
                $patent_number = $wrapper->field_patent_number->value();
                $additional_patent_description = $wrapper->field_add_pat_desc->value();
                $filing_date_value = $wrapper->field_patent_filing_date->value();
                $filing_date = $filing_date_value ? format_date($filing_date_value, 'custom', 'Y-m-d') : '';
                $issue_date_value = $wrapper->field_patent_issue_date->value();
                $issue_date = $issue_date_value ? format_date($issue_date_value, 'custom', 'Y-m-d') : '';

                unset($wrapper);
                unset($status_item);

                if(!$is_related) {
                    $writer->startElement('IncludedPatent');
                }
                else {
                    $writer->startElement('RelatedPatent');
                }
                    $writer->startElement('Patent');
                        $writer->writeElement('ApplicationNumber', $application_number);
                        $writer->writeElement('ApplicationFiledOn', $filing_date);
                        $writer->writeElement('PatentIssuedOn', $issue_date);
                        $writer->writeElement('PatentNumber', $patent_number);
                        $writer->writeElement('PatentAuthority', $patent_authority);
                        $writer->writeElement('AdditionalPatentDescription', $additional_patent_description);
                        $writer->writeElement('PatentStatus', $patent_status);
                    $writer->endElement(); // Patent
                $writer->endElement(); // IncludedPatent/RelatedPatent
            }
        }
    }

    $output = $writer->outputMemory(true);
    print $output;

    $writer->flush();
    unset($writer);
}
catch(Exception $e) {
    watchdog("ttctheme->views-view-field--views-data-export--field-pat-status.tpl.php",
        $e->getMessage());
}
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

    foreach($row->extracted_values['field_field_pat_status'] as $delta => $status) {
        $is_related = isset($status['field_is_related_patent']['value']) ? $status['field_is_related_patent']['value'] : '';
        $patent_status = isset($status['field_patent_status']['taxonomy_term']->name) 
            ? $status['field_patent_status']['taxonomy_term']->name: '' ;
        $application_number = isset($status['field_application_number']['value']) ? $status['field_application_number']['value'] : '';
        $patent_authority = isset($status['field_patent_authority']['value']) ? $status['field_patent_authority']['value'] : '' ;
        $patent_number = isset($status['field_patent_number']['value']) ? $status['field_patent_number']['value'] : '' ;
        $additional_patent_description = isset($status['field_add_pat_desc']['value']) ? $status['field_add_pat_desc']['value'] : '';
        $filing_date = isset($status['field_patent_filing_date']['value']) ? $status['field_patent_filing_date']['value'] : false;
        if($filing_date) $filing_date = (new DateTime($filing_date))->format('Y-m-d');
        $issue_date = isset($status['field_patent_issue_date']['value']) ? $status['field_patent_issue_date']['value'] : false;
        if($issue_date) $issue_date = (new DateTime($issue_date))->format('Y-m-d');

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

    $output = $writer->outputMemory(true);
    print $output;

    $writer->flush();
    unset($writer);
}
catch(Exception $e) {
    watchdog("ttctheme->views-view-field--views-data-export--field-pat-status.tpl.php",
        $e->getMessage());
}
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
$writer = new XMLWriter();
$writer->openMemory();
$writer->setIndent(true);

try {
    foreach($row->field_field_inventors as $delta => $inventor) {
        if(isset($inventor['raw']['value'])) {
            $inventor_id = $inventor['raw']['value'];
            $inventor_item = entity_load_single('field_collection_item', $inventor_id);
            if($inventor_item) {
                $wrapper = entity_metadata_wrapper('field_collection_item', $inventor_item);

                $is_lead = $wrapper->field_is_lead->value() ? 'true' : 'false';
                $first_name = $wrapper->field_first_name->value();
                $middle_initial = $wrapper->field_middle_initial->value();
                $last_name = $wrapper->field_last_name->value();
                $name_suffix = $wrapper->field_suffix->value();
                $url_value = $wrapper->field_url->value();
                $url = isset($url_value['value']) ? $url_value['value'] : '';
                $division_name = $wrapper->field_division_name->value();

                unset($wrapper);
                unset($inventor_item);

                $writer->startElement('Inventor');
                    $writer->writeElement('IsLead', $is_lead);
                    $writer->startElement('Person');
                        $writer->writeElement('FirstName', $first_name);
                        $writer->writeElement('MiddleInitial', $middle_initial);
                        $writer->writeElement('LastName', $last_name);
                        $writer->startElement('NameSuffixes');
                            $writer->writeElement('NameSuffix', $name_suffix);
                        $writer->endElement(); //NameSuffixes
                        $writer->startElement('LinkoutURLs');
                            $writer->startElement('URL');
                                $writer->writeElement('Href', $url);
                            $writer->endElement(); //URL
                        $writer->endElement(); //LinkoutURLs
                    $writer->endElement(); // Person
                    $writer->startElement('Organizations');
                        $writer->startElement('Organization');
                            $writer->startElement('Divisions');
                                $writer->startElement('Division');
                                    $writer->writeElement('DivisionName', $division_name);
                                $writer->endElement(); //Division
                            $writer->endElement(); //Divisions
                        $writer->endElement(); //Organization
                    $writer->endElement(); //Organizations
                $writer->endElement(); // Inventor
            }
        }
    }

    $output = $writer->outputMemory(true);
    print $output;
}
catch(Exception $e) {
    echo "Error occurred loading entity $entity_id";
}

$writer->flush();
unset($writer);
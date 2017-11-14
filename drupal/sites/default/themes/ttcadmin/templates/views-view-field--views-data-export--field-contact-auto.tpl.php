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
try {
    $writer = new XMLWriter();
    $writer->openMemory();
    $writer->setIndent(true);

    $contact = taxonomy_term_load($output);
    if($contact !== FALSE) {
        $wrapper = entity_metadata_wrapper('taxonomy_term', $contact);

        $first_name = $wrapper->field_first_name->value();
        $last_name = $wrapper->field_last_name->value();
        $suffix = $wrapper->field_suffix->value();
        $address = $wrapper->field_address->value();
        $city = $wrapper->field_city->value();
        $state = $wrapper->field_state->value();
        $postal_code = $wrapper->field_postal_code->value();
        $phone_number = $wrapper->field_contact_phone->value();
        $fax_number = $wrapper->field_fax_number->value();
        $org = $wrapper->field_organization_name->value();
        $fax_number = $wrapper->field_fax_number->value();
        $email = $wrapper->field_contact_email->value();

        unset($wrapper);
        unset($contact);

        $writer->startElement('Contact');
            $writer->startElement('Person');
                $writer->writeElement('FirstName', $first_name);
                $writer->writeElement('LastName', $last_name);
                $writer->startElement('NameSuffixes');
                    $writer->writeElement('NameSuffix', $suffix);
                $writer->endElement(); //NameSuffixes
                $writer->startElement('Addresses');
                     $writer->startElement('Address');
                        $writer->writeElement('AddressLine1', $address);
                        $writer->writeElement('City', $city);
                        $writer->writeElement('StateProvince', $state);
                        $writer->writeElement('PostalCode', $postal_code);
                    $writer->endElement(); //Address
                $writer->endElement(); //Addresses
                $writer->startElement('PhoneNumbers');
                    $writer->startElement('PhoneNumber');
                        $writer->writeElement('Number', $phone_number);
                    $writer->endElement(); //PhoneNumber
                $writer->endElement(); //PhoneNumbers
                $writer->startElement('FaxNumbers');
                     $writer->startElement('FaxNumber');
                        $writer->writeElement('Number', $fax_number);
                    $writer->endElement(); //FaxNumber
                $writer->endElement(); //FaxNumbers
                $writer->startElement('Emails');
                     $writer->startElement('Email');
                        $writer->writeElement('EmailID', $email);
                    $writer->endElement(); //Email
                $writer->endElement(); //Emails
            $writer->endElement(); //Person
            $writer->startElement('Organizations');
                $writer->startElement('Organization');
                    $writer->writeElement('Name', $org);
                $writer->endElement(); //Organization
            $writer->endElement(); //Organizations
        $writer->endElement(); //Contact
    }
    $output = $writer->outputMemory(true);
    print $output;

    $writer->flush();
    unset($writer);
}
catch(Exception $e) {
    print "";
}
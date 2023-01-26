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

  // load John Hewes' taxonomy term (or the currently configured term ID) as the contact for all abstracts
  //$tid = variable_get('contacts_default_term', 35);
    $tid = $output;
    $contact = taxonomy_term_load($tid);
    if($contact !== FALSE) {

        $first_name = isset($contact->field_first_name['und'][0]['value']) ? $contact->field_first_name['und'][0]['value'] : '';
        $last_name = isset($contact->field_last_name['und'][0]['value']) ? $contact->field_last_name['und'][0]['value'] : '';
        $suffix = isset($contact->field_suffix['und'][0]['value']) ? $contact->field_suffix['und'][0]['value'] : '';
        $address = isset($contact->field_address['und'][0]['value']) ? $contact->field_address['und'][0]['value'] : '';
        $city = isset($contact->field_city['und'][0]['value']) ? $contact->field_city['und'][0]['value'] : '';
        $state = isset($contact->field_state['und'][0]['value']) ? $contact->field_state['und'][0]['value'] : '';
        $postal_code = isset($contact->field_postal_code['und'][0]['value']) ? $contact->field_postal_code['und'][0]['value'] : '';
        $phone_number = isset($contact->field_contact_phone['und'][0]['value']) ? $contact->field_contact_phone['und'][0]['value'] : '';
        $fax_number = isset($contact->field_fax_number['und'][0]['value']) ? $contact->field_fax_number['und'][0]['value'] : '';
        $org = isset($contact->field_organization_name['und'][0]['value']) ? $contact->field_organization_name['und'][0]['value'] : '';
        $fax_number = isset($contact->field_fax_number['und'][0]['value']) ? $contact->field_fax_number['und'][0]['value'] : '';
        $email = isset($contact->field_contact_email['und'][0]['email']) ? $contact->field_contact_email['und'][0]['email'] : '';
        $cc_email = isset($contact->field_contact_email_cc['und'][0]['email']) ? $contact->field_contact_email_cc['und'][0]['email'] : '';
        $bcc_email = isset($contact->field_contact_email_bcc['und'][0]['email']) ? $contact->field_contact_email_bcc['und'][0]['email'] : '';

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
                    $writer->startElement('CC');
                      $writer->writeElement('EmailID', $cc_email);
                    $writer->endElement(); //CC Email
                    $writer->startElement('BCC');
                      $writer->writeElement('EmailID', $bcc_email);
                    $writer->endElement(); //BCC Email
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

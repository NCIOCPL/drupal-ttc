<?php
/**
 * @file
 * ttc_field_collections.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ttc_field_collections_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_inventors-field_division_name'.
  $field_instances['field_collection_item-field_inventors-field_division_name'] = array(
    'bundle' => 'field_inventors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_division_name',
    'label' => 'IC Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_inventors-field_first_name'.
  $field_instances['field_collection_item-field_inventors-field_first_name'] = array(
    'bundle' => 'field_inventors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_first_name',
    'label' => 'First Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_inventors-field_is_lead'.
  $field_instances['field_collection_item-field_inventors-field_is_lead'] = array(
    'bundle' => 'field_inventors',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_is_lead',
    'label' => 'Is Lead',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_inventors-field_last_name'.
  $field_instances['field_collection_item-field_inventors-field_last_name'] = array(
    'bundle' => 'field_inventors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_inventors-field_middle_initial'.
  $field_instances['field_collection_item-field_inventors-field_middle_initial'] = array(
    'bundle' => 'field_inventors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_middle_initial',
    'label' => 'Middle Initial',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_inventors-field_suffix'.
  $field_instances['field_collection_item-field_inventors-field_suffix'] = array(
    'bundle' => 'field_inventors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_suffix',
    'label' => 'Suffix',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_inventors-field_url'.
  $field_instances['field_collection_item-field_inventors-field_url'] = array(
    'bundle' => 'field_inventors',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'url',
        'settings' => array(
          'nofollow' => FALSE,
          'trim_length' => 80,
        ),
        'type' => 'url_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'title_fetch' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'url',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'url_external',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_add_pat_desc'.
  $field_instances['field_collection_item-field_pat_status-field_add_pat_desc'] = array(
    'bundle' => 'field_pat_status',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_add_pat_desc',
    'label' => 'Additional Patent Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_application_number'.
  $field_instances['field_collection_item-field_pat_status-field_application_number'] = array(
    'bundle' => 'field_pat_status',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_application_number',
    'label' => 'Application Number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_is_related_patent'.
  $field_instances['field_collection_item-field_pat_status-field_is_related_patent'] = array(
    'bundle' => 'field_pat_status',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'This patent is only related to the technology, and not directly applicable.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_is_related_patent',
    'label' => 'Is Related Patent',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_patent_authority'.
  $field_instances['field_collection_item-field_pat_status-field_patent_authority'] = array(
    'bundle' => 'field_pat_status',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_patent_authority',
    'label' => 'Patent Authority (Country)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_patent_filing_date'.
  $field_instances['field_collection_item-field_pat_status-field_patent_filing_date'] = array(
    'bundle' => 'field_pat_status',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_patent_filing_date',
    'label' => 'Filing Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'custom',
        'input_format_custom' => 'Y-m-d',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(
          0 => 'year',
        ),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_patent_issue_date'.
  $field_instances['field_collection_item-field_pat_status-field_patent_issue_date'] = array(
    'bundle' => 'field_pat_status',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_patent_issue_date',
    'label' => 'Patent Issue Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'custom',
        'input_format_custom' => 'Y-m-d',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(
          0 => 'year',
        ),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_patent_number'.
  $field_instances['field_collection_item-field_pat_status-field_patent_number'] = array(
    'bundle' => 'field_pat_status',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_patent_number',
    'label' => 'Patent Number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_patent_status'.
  $field_instances['field_collection_item-field_pat_status-field_patent_status'] = array(
    'bundle' => 'field_pat_status',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_patent_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pat_status-field_url'.
  $field_instances['field_collection_item-field_pat_status-field_url'] = array(
    'bundle' => 'field_pat_status',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'url',
        'settings' => array(
          'nofollow' => FALSE,
          'trim_length' => 80,
        ),
        'type' => 'url_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'title_fetch' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'url',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'url_external',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_publications-field_title'.
  $field_instances['field_collection_item-field_publications-field_title'] = array(
    'bundle' => 'field_publications',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<b> Format for Authors </b><br>
                <ul>
                <li> If an article has a single author, enter last name, first initial, last initial, e.g., Rosenberg SA</li>
                 <li>If an article has two or more authors, enter first author only, followed by “et al.”, e.g., Rosenberg SA, et al.</li>
                 </ul>
                 <p>Example: Rosenberg SA, et al. Adoptive cell transfer as personalized immunotherapy for human cancer.</p>
         <b> Format for Book Citations</b><br>
         <ul>
         <li>
         Insert author name, title of book or book chapter title, editors, year; meeting name, dates, place
          </li>
          </ul>   ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_title',
    'label' => 'Citation',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_publications-field_url'.
  $field_instances['field_collection_item-field_publications-field_url'] = array(
    'bundle' => 'field_publications',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<b>  URLs</b><br>
         <ul>
                     <li>The URL for PubMed abstracts is https://www.ncbi.nlm.nih.gov/pubmed/xxxxxxxx(insert the PubMed ID#), e.g., https://www.ncbi.nlm.nih.gov/pubmed/23214925.</li>
          </ul>    
          <b> PMIDs</b><br>
            <ul>
           <li>The caption for PubMed abstracts should read [PMID xxxxxxxx] (insert the PubMed ID#), e.g., [PMID 23214925].</li>
           </ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'url',
        'settings' => array(
          'nofollow' => FALSE,
          'trim_length' => 80,
        ),
        'type' => 'url_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'title_fetch' => 1,
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'url',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'url_external',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<b>  URLs</b><br>
         <ul>
                     <li>The URL for PubMed abstracts is https://www.ncbi.nlm.nih.gov/pubmed/xxxxxxxx(insert the PubMed ID#), e.g., https://www.ncbi.nlm.nih.gov/pubmed/23214925.</li>
          </ul>    
          <b> PMIDs</b><br>
            <ul>
           <li>The caption for PubMed abstracts should read [PMID xxxxxxxx] (insert the PubMed ID#), e.g., [PMID 23214925].</li>
           </ul>');
  t('<b> Format for Authors </b><br>
                <ul>
                <li> If an article has a single author, enter first initial, middle initial, last name, e.g., C.M. Micklitsch</li>
                 <li>If an article has two authors, enter first initial, middle initial, last name for first only, e g., D.H. Appella and C.M. Micklitsch</li>
                 <li>If an article has three or more authors, enter first author only, followed by “et al.”, e.g., C.M. Micklitsch et al.</li>
                 </ul>
         <b> Format for Book Citations</b><br>
         <ul>
         <li>
         Insert author name, title of book or book chapter title, editors, year; meeting name, dates, place
          </li>
          </ul>   ');
  t('Additional Patent Description');
  t('Application Number');
  t('Citation');
  t('Filing Date');
  t('First Name');
  t('IC Name');
  t('Is Lead');
  t('Is Related Patent');
  t('Last Name');
  t('Middle Initial');
  t('Patent Authority (Country)');
  t('Patent Issue Date');
  t('Patent Number');
  t('Status');
  t('Suffix');
  t('Text');
  t('This patent is only related to the technology, and not directly applicable.');
  t('URL');

  return $field_instances;
}

<?php

class TTCMigrateSiteAbstractMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    
    $this->description = t('Migration of Abstracts from a copy of the existing TTC site database.');
    
    $query = Database::getConnection()
        ->select('codev_opps', 'opp')
        ->fields('opp', array(
      'counter',
      'opp_id',
      'opp_version',
      'opp_title',
      'opp_enum',
      'opp_rel_enum',
      'meta_desc',
      'meta_keywords',
      'opp_description_text',
      'opp_commapp_text',
      'opp_compadv_text',
      'opp_invs_text',
      //'opp_ds_basic',
      //'opp_ds_discovery',
      //'opp_ds_preclinical',
      //'opp_ds_prototype',
      //'opp_ds_ind',
      //'opp_ds_clinical',
      //'opp_ds_commready',
      'opp_pubs_text',
      //'pat_us_none',
      //'pat_us_text_none',
      //'pat_us_filed',
      //'pat_us_text_filed',
      //'pat_us_issued',
      //'pat_us_text_issued',
      //'pat_for_none',
      //'pat_for_text_none',
      //'pat_for_filed',
      //'pat_for_text_filed',
      //'pat_for_issued',
      //'pat_for_text_issued',
      'opp_imgs',
      'contact_auto',
      'internal_notes',
      'list_intro_text',
      'pdf_img',
      'notif_state',
      'notif_auto',
      'notif_manual',
      'opp_mode',
      //'opp_start_date',
      //'opp_end_date',
      //'opp_last_updated',
      'opp_list_send',
      //'opp_list_lastsent',
      'opp_30day_warned',
    ));

    // convert datetime fields to unix
    $query->addExpression('UNIX_TIMESTAMP(opp_start_date)', 'opp_start_date_unix');
    $query->addExpression('UNIX_TIMESTAMP(opp_end_date)', 'opp_end_date_unix');
    $query->addExpression('UNIX_TIMESTAMP(opp_last_updated)', 'opp_last_updated_unix');
    $query->addExpression('UNIX_TIMESTAMP(opp_list_lastsent)', 'opp_list_lastsent_unix');

    // compile development stage columns
    $query->addExpression("FIELD('1', 
      opp_ds_basic,
      opp_ds_discovery,
      opp_ds_preclinical,
      opp_ds_prototype,
      opp_ds_ind,
      opp_ds_clinical,
      opp_ds_commready)", 'opp_ds');

    // create and join the product type table
    $pt_query = db_select('cat_product_type')
        ->fields('cat_product_type', array(
      'pt_therapeutics',
      'pt_software',
      'pt_vaccines',
    ));

    // combine various pt columns
    // 
    // compile rrt columns
    $pt_query->addExpression("FIELD('1', 
      rrt_biomarkers,
      rrt_celllines,
      rrt_htscreening,
      rrt_imaging,
      rrt_immunoassays,
      rrt_microarrays,
      rrt_proteomics,
      rrt_reagents,
      rrt_tissue)", 'pt_rrt');

    // compile devices columns
    $pt_query->addExpression("FIELD('1', 
      dev_drug,
      dev_surgical,
      dev_analytical,
      dev_imaging,
      dev_microarrays)", 'pt_dev');

    // compile diagnostics columns
    $pt_query->addExpression("FIELD('1', 
      diag_diagnostics,
      diag_biomarkers,
      diag_drug,
      diag_analytical,
      diag_imaging,
      diag_biopsy,
      diag_microarrays,
      diag_controlled)", 'pt_diag');

    // select pt.opp_id and opp_version as uniquely-named columns
    $pt_query->addField('cat_product_type', 'opp_id', 'pt_opp_id');
    $pt_query->addField('cat_product_type', 'opp_version', 'pt_opp_version');

    $query->join($pt_query, 'pt', 'opp.opp_id = pt_opp_id AND opp.opp_version = pt_opp_version');

    // combine the six columns into one for use in a handler function
    // compile diagnostics columns
    $query->addExpression("CONCAT_WS(',', 
      pt_therapeutics,
      pt_software,
      pt_vaccines,
      pt_rrt,
      pt_dev,
      pt_diag)", 'opp_pt');


    // create and join the therapeutic area table
    $ta_query = db_select('cat_therapeutic_area')
        ->fields('cat_therapeutic_area', array(
      'ta_nervous',
      'ta_gastro',
      'ta_hsemd',
      'ta_infectious',
      'ta_kidney',
      'ta_musculoskeletal',
      'ta_reproductive',
      'ta_skin',
    ));

    // combine various ta columns
    // 
    // compile cneo columns
    $ta_query->addExpression("FIELD('1', 
      cneo_breast,
      cneo_blood,
      cneo_bone,
      cneo_cancer,
      cneo_digestive,
      cneo_cns,
      cneo_female,
      cneo_liporal,
      cneo_male,
      cneo_softtissue,
      cneo_respiratory,
      cneo_skin,
      cneo_endocrine,
      cneo_urinary)", 'ta_cneo');

    // compile card columns
    $ta_query->addExpression("FIELD('1', 
      card_angina,
      card_blcs,
      card_cardio,
      card_stroke,
      card_thrombosis)", 'ta_card');

    // compile ee columns
    $ta_query->addExpression("FIELD('1', 
      ee_glaucoma,
      ee_macular,
      ee_nerve,
      ee_retinitis,
      ee_retinopathy,
      ee_ear)", 'ta_ee');

    // compile isi columns
    $ta_query->addExpression("FIELD('1', 
      isi_arthritis,
      isi_autoimmune,
      isi_inflammation,
      isi_transplantation)", 'ta_isi');

    // select pt.opp_id and opp_version as uniquely-named columns
    $ta_query->addField('cat_therapeutic_area', 'opp_id', 'ta_opp_id');
    $ta_query->addField('cat_therapeutic_area', 'opp_version', 'ta_opp_version');

    $query->join($ta_query, 'ta', 'opp.opp_id = ta_opp_id AND opp.opp_version = ta_opp_version');

    // combine the six columns into one for use in a handler function
    // compile diagnostics columns
    $query->addExpression("CONCAT_WS(',', 
      ta_cneo,
      ta_card,
      ta_nervous,
      ta_ee,
      ta_gastro,
      ta_hsemd,
      ta_isi,
      ta_infectious,
      ta_kidney,
      ta_musculoskeletal,
      ta_reproductive,
      ta_skin)", 'opp_ta');

    // filter to the latest opportunities
    $filtered_opp_query = db_select('codev_opps', 'co');
    $filtered_opp_query->addField('co', 'opp_id', 'co_opp_id');
    $filtered_opp_query->addExpression('MAX(co.opp_version)', 'latest_version');
    $filtered_opp_query->groupBy('co_opp_id');

    $query->join($filtered_opp_query, 'fo', 'opp_id = co_opp_id AND opp_version = latest_version');

    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('abstract', array('text_format' => 'filtered_html'));

    $this->map = new MigrateSQLMap($this->machineName, array(
      'opp_id' => array('type' => 'int',
        'size' => 'big',
        'not null' => FALSE,
        'description' => t('Opportunity ID'),
      )
        ), MigrateDestinationNode::getKeySchema()
    );

    // FIELD MAPPINGS
    // non-mapped fields
    $this->addUnmigratedSources(
        array(
          'counter',
          'opp_id',
          'opp_version'),
        'Legacy');

    // title and enumbers
    $this->addFieldMapping('title', 'opp_title');
    $this->addFieldMapping('field_enumber', 'opp_enum');
    $this->addFieldMapping('field_opp_rel_enum', 'opp_rel_enum')
        ->callbacks(array($this, 'explodeAndTrim'));

    // published state and revision note
    $this->addFieldMapping('status', 'notif_state')
        ->callbacks(array($this, 'statusByNotifState'));
    $this->addFieldMapping('workbench_moderation_state_new', 'notif_state')
        ->callbacks(array($this, 'stateByNotifState'));
    $this->addFieldMapping('log', 'internal_notes');

    // meta description and keywords
    $this->addFieldMapping('field_meta_desc', 'meta_desc');
    $this->addFieldMapping('field_meta_keywords', 'meta_keywords')
        ->callbacks(array($this, 'explodeAndTrim'));

    // description, application and competitive advantages
    $this->addFieldMapping('field_opp_description_text', 'opp_description_text');
    $this->addFieldMapping('field_opp_commapp_text', 'opp_commapp_text');
    $this->addFieldMapping('field_opp_compadv_text', 'opp_compadv_text');

    // development stage taxonomy
    $this->addFieldMapping('field_development_stage', 'opp_ds')
        ->callbacks(array($this, 'explodeDevStage'));
    $this->addFieldMapping('field_development_stage:create_term')
        ->defaultValue(TRUE);

    // product type taxonomy
    $this->addFieldMapping('field_product_type', 'opp_pt')
        ->callbacks(array($this, 'explodeProdType'));
    $this->addFieldMapping('field_product_type:create_term')
        ->defaultValue(TRUE);

    // product type taxonomy
    $this->addFieldMapping('field_therapeutic_area', 'opp_ta')
        ->callbacks(array($this, 'explodeTherArea'));
    $this->addFieldMapping('field_therapeutic_area:create_term')
        ->defaultValue(TRUE);

    // field collections (inventors and publications)
    // $this->addFieldMapping('field_opp_invs_text', 'opp_invs_text');
    //$this->addFieldMapping('field_opp_pubs_text', 'opp_pubs_text');
    // image field
    //$this->addFieldMapping('field_opp_imgs', 'opp_imgs');


    $this->addFieldMapping('field_list_intro_text', 'list_intro_text');
    $this->addFieldMapping('field_opp_mode', 'opp_mode');

    // flags for listserv sent and 30 day warning
    $this->addFieldMapping('field_opp_list_send', 'opp_list_send');
    $this->addFieldMapping('field_opp_30day_warned', 'opp_30day_warned');

    // unix time fields (start and end date, update, and last sent)
    $this->addFieldMapping('field_opp_start_date', 'opp_start_date_unix');
    $this->addFieldMapping('field_opp_end_date', 'opp_end_date_unix');
    $this->addFieldMapping('changed', 'opp_last_updated_unix');
    $this->addFieldMapping('field_opp_list_lastsent', 'opp_list_lastsent_unix');

    // patent field collection
    /*
      $this->addFieldMapping('field_pat_us_none', 'pat_us_none');
      $this->addFieldMapping('field_pat_us_filed', 'pat_us_filed');
      $this->addFieldMapping('field_pat_us_issued', 'pat_us_issued');
      $this->addFieldMapping('field_pat_for_none', 'pat_for_none');
      $this->addFieldMapping('field_pat_for_filed', 'pat_for_filed');
      $this->addFieldMapping('field_pat_for_issued', 'pat_for_issued');
     * 
      $this->addFieldMapping('field_pat_us_text_none', 'pat_us_text_none');
      $this->addFieldMapping('field_pat_us_text_filed', 'pat_us_text_filed');
      $this->addFieldMapping('field_pat_us_text_issued', 'pat_us_text_issued');
      $this->addFieldMapping('field_pat_for_text_none', 'pat_for_text_none');
      $this->addFieldMapping('field_pat_for_text_filed', 'pat_for_text_filed');
      $this->addFieldMapping('field_pat_for_text_issued', 'pat_for_text_issued');
     */

    // notification field collection
    //$this->addFieldMapping('field_notif_auto', 'notif_auto');
    //$this->addFieldMapping('field_notif_manual', 'notif_manual');
    // contact taxonomy
    $this->addFieldMapping('field_contact_auto', 'contact_auto');
    $this->addFieldMapping('field_contact_auto:create_term')
        ->defaultValue(TRUE);

    // pdf letterhead taxonomy
    $this->addFieldMapping('field_pdf_img', 'pdf_img');
    $this->addFieldMapping('field_pdf_img:create_term')
        ->defaultValue(TRUE);
  }

  protected function explodeAndTrim($value) {
    $output = array_map('trim', explode(',', $value));
    return $output;
  }

  protected function explodeDevStage($value) {
    // expects a base-1 integer with values in the following
    // order:
    //  1: opp_ds_basic
    //  2: opp_ds_discovery
    //  3: opp_ds_preclinical
    //  4: opp_ds_prototype
    //  5: opp_ds_ind
    //  6: opp_ds_clinical
    //  7: opp_ds_commready

    switch ($value) {
      case 1:
        return 'Basic (Target Identification)';
      case 2:
        return 'Discovery (Lead Identification)';
      case 3:
        return 'Pre-clinical (in vivo)';
      case 4:
        return 'Prototype';
      case 5:
        return 'ind';
      case 6:
        return 'Clinical';
      case 7:
        return 'Prototype';
    }

    return NULL;
  }

  protected function explodeProdType($value) {
    // expects a comma-delimited set of term counts in the following
    // order:
    //  pt_therapeutics
    //  pt_software
    //  pt_vaccines
    //  pt_rrt
    //  pt_dev
    //  pt_diag
    // break up csv string into variables
    list($pt_therapeutics,
        $pt_software,
        $pt_vaccines,
        $pt_rrt,
        $pt_dev,
        $pt_diag) = explode(',', $value);

    $output = array();

    if ($pt_therapeutics) {
      $output[] = 'Therapeutics';
    }
    if ($pt_software) {
      $output[] = 'Software';
    }
    if ($pt_vaccines) {
      $output[] = 'Vaccines';
    }
    if ($pt_rrt) {
      $output[] = 'Research Materials';
    }
    if ($pt_dev) {
      $output[] = 'Devices';
    }
    if ($pt_diag) {
      $output[] = 'Diagnostics';
    }

    return $output;
  }

  protected function explodeTherArea($value) {
    // expects a comma-delimited set of term counts in the following
    // order:
    //  ta_cneo
    //  ta_card
    //  ta_nervous
    //  ta_ee
    //  ta_gastro
    //  ta_hsemd
    //  ta_isi
    //  ta_infectious
    //  ta_kidney
    //  ta_musculoskeletal
    //  ta_reproductive
    //  ta_skin
    //  
    // break up csv string into variables
    list($ta_cneo,
        $ta_card,
        $ta_nervous,
        $ta_ee,
        $ta_gastro,
        $ta_hsemd,
        $ta_isi,
        $ta_infectious,
        $ta_kidney,
        $ta_musculoskeletal,
        $ta_reproductive,
        $ta_skin) = explode(',', $value);

    $output = array();

    if ($ta_cneo) {
      $output[] = 'Cancer/Neoplasm';
    }
    if ($ta_card) {
      $output[] = 'Cardiovascular Systems';
    }
    if ($ta_nervous) {
      $output[] = 'Central Nervous System, Mental and Behavioral, Pain';
    }
    if ($ta_ee) {
      $output[] = 'Eye and Ear';
    }
    if ($ta_gastro) {
      $output[] = 'Gastrointestinal';
    }
    if ($ta_hsemd) {
      $output[] = 'Hormonal Systems, Endocrine, and Metabolic Diseases';
    }
    if ($ta_isi) {
      $output[] = 'Immune System and Inflammation';
    }
    if ($ta_infectious) {
      $output[] = 'Infectious Diseases';
    }
    if ($ta_kidney) {
      $output[] = 'Kidney and the Genitourinary';
    }
    if ($ta_musculoskeletal) {
      $output[] = 'Musculoskeletal';
    }
    if ($ta_reproductive) {
      $output[] = 'Reproductive';
    }
    if ($ta_skin) {
      $output[] = 'Skin and Subcutaneous Tissue';
    }

    return $output;
  }

  protected function statusByNotifState($value) {
    return ($value === '6' || $value === '4' ? 1 : 0);
  }

  protected function stateByNotifState($value) {
    return ($value === '6' || $value === '4' ? 'published' : 'draft');
  }

}

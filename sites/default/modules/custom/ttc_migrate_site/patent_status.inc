<?php

class TTCMigrateSiteAbstractPatentStatusMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Patent Status field collection migration for TTC Abstracts.');
    $this->dependencies = array('TTCSiteAbstract');

    // create a six-part union to generate one row per active patent status

    $us_none_query = db_select('codev_opps', 'us_none')
        ->fields('us_none', array('opp_id', 'opp_version'));
    $us_none_query->addExpression("'pat_us_none'", 'status_type');
    $us_none_query->addExpression('pat_us_text_none', 'pat_text');
    $us_none_query->condition('pat_us_none', 1);

    $us_filed_query = db_select('codev_opps', 'us_filed')
        ->fields('us_filed', array('opp_id', 'opp_version'));
    $us_filed_query->addExpression("'pat_us_filed'", 'status_type');
    $us_filed_query->addExpression('pat_us_text_filed', 'pat_text');
    $us_filed_query->condition('pat_us_filed', 1);

    $us_issued_query = db_select('codev_opps', 'us_issued')
        ->fields('us_issued', array('opp_id', 'opp_version'));
    $us_issued_query->addExpression("'pat_us_issued'", 'status_type');
    $us_issued_query->addExpression('pat_us_text_issued', 'pat_text');
    $us_issued_query->condition('pat_us_issued', 1);

    $for_none_query = db_select('codev_opps', 'for_none')
        ->fields('for_none', array('opp_id', 'opp_version'));
    $for_none_query->addExpression("'pat_for_none'", 'status_type');
    $for_none_query->addExpression('pat_for_text_none', 'pat_text');
    $for_none_query->condition('pat_for_none', 1);

    $for_filed_query = db_select('codev_opps', 'for_filed')
        ->fields('for_filed', array('opp_id', 'opp_version'));
    $for_filed_query->addExpression("'pat_for_filed'", 'status_type');
    $for_filed_query->addExpression('pat_for_text_filed', 'pat_text');
    $for_filed_query->condition('pat_for_filed', 1);

    $for_issued_query = db_select('codev_opps', 'for_issued')
        ->fields('for_issued', array('opp_id', 'opp_version'));
    $for_issued_query->addExpression("'pat_for_issued'", 'status_type');
    $for_issued_query->addExpression('pat_for_text_issued', 'pat_text');
    $for_issued_query->condition('pat_for_issued', 1);

    // union these queries
    $us_none_query
        ->union($us_filed_query)
        ->union($us_issued_query)
        ->union($for_none_query)
        ->union($for_filed_query)
        ->union($for_issued_query);

    // create encapsulating query
    $pat_status_query = db_select($us_none_query, 'pat_status')
        ->fields('pat_status', array('opp_id', 'status_type', 'pat_text'));

    // add copy of opp_id to use as foreign key to the abstract
    $pat_status_query->addField('pat_status', 'opp_id', 'host_id');

    // filter to the latest opportunities
    $filtered_opp_query = db_select('codev_opps', 'co');
    $filtered_opp_query->addField('co', 'opp_id', 'co_opp_id');
    $filtered_opp_query->addExpression('MAX(co.opp_version)', 'latest_version');
    $filtered_opp_query->groupBy('co_opp_id');

    $pat_status_query->join($filtered_opp_query, 'fo', 'opp_id = co_opp_id AND opp_version = latest_version');

    $this->source = new MigrateSourceSQL($pat_status_query);

    $this->destination = new MigrateDestinationFieldCollection(
        'field_pat_status', array('host_entity_type' => 'node')
    );

    $this->map = new MigrateSQLMap($this->machineName, array(
      'opp_id' => array('type' => 'int',
        'size' => 'big',
        'not null' => FALSE,
        'description' => t('Opportunity ID'),
      ),
      'status_type' => array('type' => 'varchar',
        'length' => '255',
        'description' => t('Patent Status'),
      )
        ), MigrateDestinationFieldCollection::getKeySchema()
    );

    $this->addFieldMapping('host_entity_id', 'host_id')->sourceMigration('TTCSiteAbstract');
    $this->addFieldMapping('field_patent_status', 'status_type')
        ->callbacks(array($this, 'convertPatentStatusTerm'));
    $this->addFieldMapping('field_patent_status:create_term')
        ->defaultValue(TRUE);
    $this->addFieldMapping('field_text', 'pat_text');
  }

  protected function explodeAndTrim($value) {
    $output = array_map('trim', explode(',', $value));
    return $output;
  }

  protected function convertPatentStatusTerm($value) {
    switch ($value) {
      case 'pat_us_none':
      case 'pat_for_none':
        return 'Not Patented';
      case 'pat_us_filed':
        return 'U.S. Filed';
      case 'pat_us_issued':
        return 'U.S. Issued';
      case 'pat_for_filed':
        return 'Foreign Filed';
      case 'pat_for_issued':
        return 'Foreign Issued';
      default:
        return 'Unrecognized';
    }
  }

  /**
   * Run after a patent status import - finds all nodes with null patent statuses
   * and sets all found to 'Not Patented'.
   */
  public function postImport() {
    parent::postImport();

    // look for 'not patented' term
    $npTerms = taxonomy_get_term_by_name('Not Patented');
    $npTerm = array_shift($npTerms);

    if ($npTerm) {
      // if term exists, 
      // find all abstracts with empty patent status field collections
      $notNullQuery = new EntityFieldQuery();

      $notNullQuery->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'abstract')
          ->propertyCondition('status', NODE_PUBLISHED)
          ->fieldCondition('field_pat_status', 'value', 'NULL', '!=');

      $notNullResult = $notNullQuery->execute();

      if (isset($notNullResult['node'])) {
        $notNullNids = array_keys($notNullResult['node']);

        // find all abstracts not in the returned list (that have null statuses)
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'abstract')
            ->propertyCondition('status', NODE_PUBLISHED)
            ->entityCondition('entity_id', $notNullNids, 'NOT IN');
        $nullResult = $query->execute();

        // if nodes are returned...
        if (isset($nullResult['node'])) {
          // load the null-patent-status nodes
          $nullNids = array_keys($nullResult['node']);
          $nullNodes = entity_load('node', $nullNids);

          foreach ($nullNodes as $node) {
            // Create a new field collection 
            $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_pat_status'));

            // add field_patent_status
            $field_collection_item->field_patent_status['und'][]['tid'] = $npTerm->tid;

            // Save field collection item
            $field_collection_item->setHostEntity('node', $node);
            $field_collection_item->save(TRUE);
            
            // save node
            node_save($node);
          }
        }
      }
    }
  }

}

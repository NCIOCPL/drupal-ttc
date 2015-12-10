<?php

class TTCMigrateSiteAbstractPublicationsMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Publications field collection migration for TTC Abstracts.');
    $this->dependencies = array('TTCSiteAbstract');

    $query = Database::getConnection()
        ->select('codev_opps', 'opp')
        ->fields('opp', array(
      'opp_id',
      'opp_version',
      'opp_pubs_text',
    ));
    
    
    // add copy of opp_id to use as foreign key to the abstract
    $query->addField('opp', 'opp_id', 'host_id');

    // filter to the latest opportunities
    $filtered_opp_query = db_select('codev_opps', 'co');
    $filtered_opp_query->addField('co', 'opp_id', 'co_opp_id');
    $filtered_opp_query->addExpression('MAX(co.opp_version)', 'latest_version');
    $filtered_opp_query->groupBy('co_opp_id');

    $query->join($filtered_opp_query, 'fo', 'opp_id = co_opp_id AND opp_version = latest_version');

    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationFieldCollection(
        'field_opp_pubs_text', array('host_entity_type' => 'node')
    );

    $this->map = new MigrateSQLMap($this->machineName, array(
      'opp_id' => array('type' => 'int',
        'size' => 'big',
        'not null' => FALSE,
        'description' => t('Opportunity ID'),
      )
        ), MigrateDestinationFieldCollection::getKeySchema()
    );

    $this->addFieldMapping('host_entity_id', 'host_id')->sourceMigration('TTCSiteAbstract');
    $this->addFieldMapping('field_long_text', 'opp_pubs_text');
  }

  protected function explodeAndTrim($value) {
    $output = array_map('trim', explode(',', $value));
    return $output;
  }

}

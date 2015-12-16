<?php
/**
 * @file
 * ttc_site_config.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ttc_site_config_default_rules_configuration() {
  $items = array();
  $items['ttc_site_config_rules_abstract_email_blast'] = entity_import('rules_config', '{ "ttc_site_config_rules_abstract_email_blast" : {
      "LABEL" : "Abstract Email Blast",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workbench_moderation" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "abstract" : "abstract" } }
          }
        },
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
        { "data_is" : { "data" : [ "node:field-opp-mode" ], "value" : "1" } },
        { "data_is" : { "data" : [ "node:field-opp-list-send" ], "value" : "1" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:field-notif:field_send_to]",
            "subject" : "New NIH Partnering Opportunity",
            "message" : "To learn more about the opportunity [node:title] and for contact information, please go to [node:url]",
            "language" : [ "node:language" ]
          }
        },
        { "data_set" : { "data" : [ "node:field-opp-list-send" ], "value" : "0" } }
      ]
    }
  }');
  return $items;
}

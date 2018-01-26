<?php
/**
 * @file
 * ttc_content_type_news_announcement.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ttc_content_type_news_announcement_default_rules_configuration() {
  $items = array();
  $items['rules_404_news_nodes'] = entity_import('rules_config', '{ "rules_404_news_nodes" : {
      "LABEL" : "404 news nodes",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php" ],
      "ON" : { "node_view--news_announcement" : { "bundle" : "news_announcement" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [ { "php_eval" : { "code" : "drupal_not_found();" } } ]
    }
  }');
  return $items;
}

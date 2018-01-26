<?php
/**
 * @file
 * ttc_workbench.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ttc_workbench_default_rules_configuration() {
  $items = array();
  $items['rules_email_alert_for_review_state'] = entity_import('rules_config', '{ "rules_email_alert_for_review_state" : {
      "LABEL" : "Email alert for review state",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "workbench_moderation_after_moderation_transition" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "needs_review" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "youngdr@mail.nih.gov",
            "subject" : "TTC - Review Needed for \\u0022[node:title]\\u0022",
            "message" : "The TTC content \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E has been moved to the Needs Review state.  Please visit the page to review and approve the content.",
            "from" : [ "site:mail" ]
          }
        }
      ]
    }
  }');
  return $items;
}

<?php
/**
 * @file
 * ttc_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ttc_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function ttc_search_default_search_api_index() {
  $items = array();
  $items['abstract_faceted_index'] = entity_import('search_api_index', '{
    "name" : "Abstract Faceted Index",
    "machine_name" : "abstract_faceted_index",
    "description" : "This index will be used for faceted search of abstract content items.",
    "server" : "ttc",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "abstract" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "abstract" : "abstract" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "Title2",
                "type" : "fulltext",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              },
              "search_api_aggregation_2" : {
                "name" : "Reference Number2",
                "type" : "fulltext",
                "fields" : [ "field_enumber" ],
                "description" : "A Fulltext aggregation of the following fields: Reference Number."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "nid" : true,
              "vid" : true,
              "title" : true,
              "changed" : true,
              "field_meta_keywords" : true,
              "field_meta_long_desc" : true,
              "field_enumber" : true,
              "field_opp_rel_enum" : true,
              "field_opp_start_date" : true,
              "field_opp_year" : true,
              "field_contact_auto" : true,
              "field_development_stage" : true,
              "field_product_type" : true,
              "field_therapeutic_area" : true,
              "field_pat_status" : true,
              "search_api_language" : true,
              "search_api_aggregation_1" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_opp_description_text:value" : true,
              "field_development_stage:name" : true,
              "field_pat_status:field_text" : true,
              "field_opp_invs_text:value" : true,
              "field_opp_pubs_text:value" : true,
              "field_pat_status:field_send_to:name" : true,
              "field_pat_status:field_patent_status:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "nid" : true,
              "vid" : true,
              "title" : true,
              "changed" : true,
              "field_meta_keywords" : true,
              "field_meta_long_desc" : true,
              "field_enumber" : true,
              "field_opp_rel_enum" : true,
              "field_opp_start_date" : true,
              "field_opp_year" : true,
              "field_contact_auto" : true,
              "field_development_stage" : true,
              "field_product_type" : true,
              "field_therapeutic_area" : true,
              "field_pat_status" : true,
              "search_api_language" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_opp_description_text:value" : true,
              "field_development_stage:name" : true,
              "field_pat_status:field_text" : true,
              "field_opp_invs_text:value" : true,
              "field_opp_pubs_text:value" : true,
              "field_pat_status:field_send_to:name" : true,
              "field_pat_status:field_patent_status:name" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_meta_keywords" : true,
              "field_meta_long_desc" : true,
              "field_enumber" : true,
              "field_opp_rel_enum" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_opp_description_text:value" : true,
              "field_development_stage:name" : true,
              "field_pat_status:field_text" : true,
              "field_opp_invs_text:value" : true,
              "field_opp_pubs_text:value" : true,
              "field_pat_status:field_send_to:name" : true,
              "field_pat_status:field_patent_status:name" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027\\\\-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "field_contact_auto" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_development_stage" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_development_stage:name" : { "type" : "text" },
        "field_enumber" : { "type" : "text" },
        "field_meta_keywords" : { "type" : "list\\u003Ctext\\u003E" },
        "field_meta_long_desc" : { "type" : "text" },
        "field_opp_commapp_text:value" : { "type" : "text" },
        "field_opp_compadv_text:value" : { "type" : "text" },
        "field_opp_description_text:value" : { "type" : "text" },
        "field_opp_invs_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_opp_pubs_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_opp_rel_enum" : { "type" : "list\\u003Ctext\\u003E" },
        "field_opp_start_date" : { "type" : "date" },
        "field_opp_year" : { "type" : "integer" },
        "field_pat_status" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_pat_status:field_patent_status:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_pat_status:field_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_product_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_therapeutic_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "string" },
        "search_api_aggregation_2" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "vid" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "ttc",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "abstract" : "abstract",
              "page" : "page",
              "success_story" : "success_story"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_meta_long_desc" : true,
              "field_meta_keywords" : true,
              "field_enumber" : true,
              "field_opp_year" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_pat_status:field_text" : true,
              "field_opp_invs_text:value" : true,
              "field_opp_pubs_text:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_meta_keywords" : true,
              "field_enumber" : true,
              "field_opp_year" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_pat_status:field_text" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_meta_keywords" : true,
              "field_enumber" : true,
              "field_opp_year" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_pat_status:field_text" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_meta_keywords" : true,
              "field_enumber" : true,
              "field_opp_year" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_pat_status:field_text" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "field_enumber" : { "type" : "text" },
        "field_meta_keywords" : { "type" : "list\\u003Ctext\\u003E", "boost" : "3.0" },
        "field_meta_long_desc" : { "type" : "text" },
        "field_opp_commapp_text:value" : { "type" : "text" },
        "field_opp_compadv_text:value" : { "type" : "text" },
        "field_opp_description_text:value" : { "type" : "text" },
        "field_opp_invs_text:value" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_opp_pubs_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_opp_year" : { "type" : "text" },
        "field_pat_status" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_pat_status:field_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "title" : { "type" : "text", "boost" : "5.0" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ttc_search_default_search_api_server() {
  $items = array();
  $items['ttc'] = entity_import('search_api_server', '{
    "name" : "TTC",
    "machine_name" : "ttc",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 0,
      "indexes" : {
        "default_node_index" : {
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_enumber" : {
            "table" : "search_api_db_default_node_index_text",
            "column" : "field_enumber",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_year" : {
            "table" : "search_api_db_default_node_index_text",
            "column" : "field_opp_year",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_meta_keywords" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "3.0"
          },
          "field_pat_status" : {
            "table" : "search_api_db_default_node_index_field_pat_status",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_description_text:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_commapp_text:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_compadv_text:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_url" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "field_meta_long_desc" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_invs_text:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "2.0"
          },
          "field_opp_pubs_text:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_pat_status:field_text:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        },
        "abstract_faceted_index" : {
          "field_development_stage" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "field_development_stage",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_product_type" : {
            "table" : "search_api_db_abstract_faceted_index_field_product_type",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_therapeutic_area" : {
            "table" : "search_api_db_abstract_faceted_index_field_therapeutic_area",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_pat_status" : {
            "table" : "search_api_db_abstract_faceted_index_field_pat_status",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_meta_keywords" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "vid" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "vid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_enumber" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "column" : "field_enumber",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_start_date" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "field_opp_start_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "column" : "title",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_description_text:value" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_rel_enum" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_opp_year" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "field_opp_year",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_meta_long_desc" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_commapp_text:value" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_compadv_text:value" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_contact_auto" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "field_contact_auto",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_development_stage:name" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_opp_invs_text:value" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_opp_pubs_text:value" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_pat_status:field_patent_status:name" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_abstract_faceted_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_pat_status:field_text:value" : {
            "table" : "search_api_db_abstract_faceted_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_abstract_faceted_index",
            "type" : "string",
            "boost" : "1.0",
            "column" : "search_api_aggregation_1"
          },
          "search_api_aggregation_2" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "search_api_aggregation_2",
            "type" : "string",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

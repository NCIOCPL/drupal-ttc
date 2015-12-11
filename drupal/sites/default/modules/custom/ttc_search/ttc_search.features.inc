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
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
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
        "changed" : { "type" : "date" },
        "field_development_stage" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_enumber" : { "type" : "string" },
        "field_meta_keywords" : { "type" : "list\\u003Ctext\\u003E" },
        "field_opp_start_date" : { "type" : "date" },
        "field_pat_status" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_pat_status:field_patent_status" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_product_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_therapeutic_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "string" },
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
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
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
              "field_enumber" : true,
              "field_opp_year" : true,
              "field_meta_desc" : true,
              "field_meta_keywords" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_opp_invs_text:field_opp_invs_name" : true,
              "field_pat_status:field_text" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_enumber" : true,
              "field_opp_year" : true,
              "field_meta_desc" : true,
              "field_meta_keywords" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_opp_invs_text:field_opp_invs_name" : true,
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
              "field_enumber" : true,
              "field_opp_year" : true,
              "field_meta_desc" : true,
              "field_meta_keywords" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_opp_invs_text:field_opp_invs_name" : true,
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
              "field_enumber" : true,
              "field_opp_year" : true,
              "field_meta_desc" : true,
              "field_meta_keywords" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_opp_description_text:value" : true,
              "field_opp_commapp_text:value" : true,
              "field_opp_compadv_text:value" : true,
              "field_opp_invs_text:field_opp_invs_name" : true,
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
        "field_meta_desc" : { "type" : "text" },
        "field_meta_keywords" : { "type" : "list\\u003Ctext\\u003E", "boost" : "3.0" },
        "field_meta_long_desc" : { "type" : "text" },
        "field_opp_commapp_text:value" : { "type" : "text" },
        "field_opp_compadv_text:value" : { "type" : "text" },
        "field_opp_description_text:value" : { "type" : "text" },
        "field_opp_invs_text" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_opp_pubs_text" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_opp_year" : { "type" : "text" },
        "field_pat_status" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_pat_status:field_text" : { "type" : "list\\u003Ctext\\u003E" },
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
          "field_meta_desc" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_meta_keywords" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "3.0"
          },
          "field_opp_invs_text" : {
            "table" : "search_api_db_default_node_index_field_opp_invs_text",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_opp_pubs_text" : {
            "table" : "search_api_db_default_node_index_field_opp_pubs_text",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
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
          "field_pat_status:field_text" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
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
          "field_pat_status:field_patent_status" : {
            "table" : "search_api_db_abstract_faceted_index_field_pat_status_field_pa",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
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
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "field_enumber",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_opp_start_date" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "field_opp_start_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_abstract_faceted_index",
            "column" : "title",
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

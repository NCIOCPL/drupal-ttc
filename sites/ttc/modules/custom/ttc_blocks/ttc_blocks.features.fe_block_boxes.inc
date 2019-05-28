<?php
/**
 * @file
 * ttc_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ttc_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Listserv Block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'listserv_block';
  $fe_block_boxes->body = '<div><!-- placeholder html for block body --></div>';

  $export['listserv_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Subscribe Button';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'subscribe_button';
  $fe_block_boxes->body = '<div><!-- placeholder html for block body --></div>';

  $export['subscribe_button'] = $fe_block_boxes;

  return $export;
}

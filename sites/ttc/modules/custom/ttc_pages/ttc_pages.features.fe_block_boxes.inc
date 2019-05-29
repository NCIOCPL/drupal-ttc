<?php
/**
 * @file
 * ttc_pages.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ttc_pages_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Listserv Block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'listserv_block';
  $fe_block_boxes->body = '
<form class="footer-subscribe" action="/" method="post" id="" accept-charset="UTF-8" style=\'text-align:center;\'>
    <div class="container-inline">
      <h4 class="field-content" style=\'color:#215d73\'>SUBSCRIBE</h4>
      <div class="">Subscribe to our Available Technology Listserv to receive the latest announcements.</div>
      <div class="row">
        <div class="small-8 columns search-form__input-container">
          <div class="form-item form-type-textfield form-item-search-block-form">
            <input title="Enter the terms you wish to search for." placeholder="Your Email Address..." class="search-form__input form-text" type="text" id="edit-search-block-form--2" name="search_block_form" value="" size="15" maxlength="128" />
          </div>
        </div>
        <div class="small-4 columns search-form__submit-container">
	      <button class="button radius postfix expand primary search-form__submit form-submit" id="edit-submit" name="op" value="Subscribe" type="submit">Subscribe</button>
        </div>
      </div>
    </div>
</form>';

  $export['listserv_block'] = $fe_block_boxes;



  $fe_subscribe_button = new stdClass();
  $fe_subscribe_button->info = 'Subscribe Button';
  $fe_subscribe_button->format = 'full_html';
  $fe_subscribe_button->machine_name = 'subscribe_button';
  $fe_subscribe_button->body = '

';

  $export['subscribe_button'] = $fe_subscribe_button;


  return $export;
}

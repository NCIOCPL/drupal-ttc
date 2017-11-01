<?php
/**
 * @file
 * ttc_theme_config.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ttc_theme_config_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Follow Us (footer)';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'follow_us_footer';
  $fe_block_boxes->body = '<div class="follow-us">
  <ul class="follow-us__list">
    <li class="follow-us__list-item"><a class="icon -size-54 -icon-linkedin--white" href="https://www.linkedin.com/groups/4688463" title="LinkedIn"><span class="fa fa-linkedin" aria-hidden="true"></span><span class="element-invisible">follow us on LinkedIn</span></a></li>
    <li class="follow-us__list-item"><a class="icon -size-54 -icon-twitter--white" href="https://twitter.com/NCITechTransfer" title="Twitter"><span class="fa fa-twitter" aria-hidden="true"></span><span class="element-invisible">follow us on Twitter</span></a></li>
    <li class="follow-us__list-item"><a class="icon -size-54 -icon-email--white" href="mailto:FAKEEMAIL@FAKEEMAIL.FAKEEMAIL" title="Email"><span class="fa fa-envelope" aria-hidden="true"></span><span class="element-invisible">email us</span></a></li>
  </ul>
</div>';

  $export['follow_us_footer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Follow Us (header)';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'follow_us_header';
  $fe_block_boxes->body = '<div class="follow-us">
  <span class="follow-us__label">Follow Us</span>
  <ul class="follow-us__list">
    <li class="follow-us__list-item"><a class="icon -size-36 -icon-linkedin" href="https://www.linkedin.com/groups/4688463" title="LinkedIn"><span class="fa fa-linkedin" aria-hidden="true"></span><span class="element-invisible">follow us on LinkedIn</span></a></li>
    <li class="follow-us__list-item"><a class="icon -size-36 -icon-twitter" href="https://twitter.com/NCITechTransfer" title="Twitter"><span class="fa fa-twitter" aria-hidden="true"></span><span class="element-invisible">follow us on Twitter</span></a></li>
    <li class="follow-us__list-item"><a class="icon -size-36 -icon-govdelivery" href="https://public.govdelivery.com/accounts/USNIHNCI/subscriber/new?category_id=USNIHNCI_C25" title="Subscribe via GovDelivery"><span class="fa" aria-hidden="true"></span><span class="element-invisible">subscribe via GovDelivery</span></a></li>
  </ul>
</div>';

  $export['follow_us_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Logo (footer)';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'logo_footer';
  $fe_block_boxes->body = '<div class="logo">
  <a class="logo__link" href="/" title="Home">
    <img alt="Technology Transfer Center of the National Cancer Institute" class="logo__image--white" onerror="this.src=\'/sites/default/themes/ttctheme/public/images/ttc-logo--white.png\'; this.removeAttribute(\'onerror\');" src="/sites/default/themes/ttctheme/public/images/ttc-logo--white.svg" />
  </a>
</div>';

  $export['logo_footer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Logo (header)';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'logo_header';
  $fe_block_boxes->body = '<div class="logo">
  <a class="logo__link" href="/" title="Home">
    <img alt="Technology Transfer Center of the National Cancer Institute" class="logo__image" onerror="this.src=\'/sites/default/themes/ttctheme/public/images/ttc-logo.png\'; this.removeAttribute(\'onerror\');" src="/sites/default/themes/ttctheme/public/images/ttc-logo.svg" />
  </a>
</div>';

  $export['logo_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Tagline';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'tagline';
  $fe_block_boxes->body = '<div class="row">
  <div class="tagline">NIH &hellip; Turning Discovery Into Health<sup>&reg;</sup></div>
</div>';

  $export['tagline'] = $fe_block_boxes;

  return $export;
}

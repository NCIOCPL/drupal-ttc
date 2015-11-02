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
    <li class="follow-us__list-item"><a href="https://www.linkedin.com/groups/4677463" title="LinkedIn" class="icon -size-54 -icon-linkedin--white"><span class="element-invisible">follow us on LinkedIn</span></a></li>
    <li class="follow-us__list-item"><a href="https://twitter.com/NCITechTransfer" title="Twitter" class="icon -size-54 -icon-twitter--white"><span class="element-invisible">follow us on Twitter</span></a></li>
    <li class="follow-us__list-item"><a href="mailto:FAKEEMAIL@FAKEEMAIL.FAKEEMAIL" title="Email" class="icon -size-54 -icon-email--white"><span class="element-invisible">email us</span></a></li>
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
    <li class="follow-us__list-item"><a href="https://www.linkedin.com/groups/4677463" title="LinkedIn" class="icon -size-36 -icon-linkedin"><span class="element-invisible">follow us on LinkedIn</span></a></li>
    <li class="follow-us__list-item"><a href="https://twitter.com/NCITechTransfer" title="Twitter" class="icon -size-36 -icon-twitter"><span class="element-invisible">follow us on Twitter</span></a></li>
    <li class="follow-us__list-item"><a href="mailto:FAKEEMAIL@FAKEEMAIL.FAKEEMAIL" title="Email" class="icon -size-36 -icon-email"><span class="element-invisible">email us</span></a></li>
  </ul>
</div>';

  $export['follow_us_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Logo (footer)';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'logo_footer';
  $fe_block_boxes->body = '<div class="logo l-logo">
  <a href="/" title="Home" class="logo__link">
    <img src="/sites/default/themes/ttctheme/public/images/ttc-logo--white.svg" alt="Technology Transfer Center of the National Cancer Institute" onerror="this.src=\'/sites/default/themes/ttctheme/public/images/ttc-logo--white.png\'; this.removeAttribute(\'onerror\');">
  </a>
</div>';

  $export['logo_footer'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Logo (header)';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'logo_header';
  $fe_block_boxes->body = '<div class="logo l-logo">
  <a href="/" title="Home" class="logo__link">
    <img src="/sites/default/themes/ttctheme/public/images/ttc-logo.svg" alt="Technology Transfer Center of the National Cancer Institute" onerror="this.src=\'/sites/default/themes/ttctheme/public/images/ttc-logo.png\'; this.removeAttribute(\'onerror\');">
  </a>
</div>';

  $export['logo_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Tagline';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'tagline';
  $fe_block_boxes->body = '<div class="row">
  <div class="tagline">NIH … Turning Discovery Into Health<sup>®</sup></div>
</div>';

  $export['tagline'] = $fe_block_boxes;

  return $export;
}

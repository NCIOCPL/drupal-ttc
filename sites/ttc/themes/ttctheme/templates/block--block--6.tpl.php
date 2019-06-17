<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user module
 *     is responsible for handling the default user navigation block. In that case
 *     the class would be "block-user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */
?>
<?php if ($block->delta != 'main'): ?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php endif; ?>

  <?php print render($title_prefix); ?>
  <?php if ($block->subject): ?>
    <span<?php print $title_attributes; ?>><?php print $block->subject ?></span>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php !empty($content_attributes) ? print '<div ' . $content_attributes . '>' : ''; ?>
  <?php print $content ?>
  <?php !empty($content_attributes) ? print '</div>' : ''; ?>

  <?php $block->delta != 'main' ? print '</div>' : ''; ?>


<?php /// If this page should contain the subscription form, render the block and subscribe field ?>
<?php if(stristr($classes, 'block--listserv-block') != FALSE): ?>
  <div class="listserv-subscribe-block-wrapper row">
    <form id="GD-snippet-form" action="https://public.govdelivery.com/accounts/USNIHNCI/subscribers/qualify" class="listserv-subscribe-block" target="_blank" accept-charset="UTF-8" method="post">
      <input name="utf8" type="hidden" value="&#x2713;" />
      <input type="hidden" name="authenticity_token" value="NbWlxeuxWUI5bV49T0epIil4bZhHHIPhDXOaTkIa4XNU1OCf5LcfC/my+aU4yrWGPR2cfeXn5NqhjzuwZ8EDJQ==" />
      <input type="hidden" name="category_id" id="category_id" value="USNIHNCI_C25" />
      <input type="hidden" name="subscription_type" id="subscription_type" value="email" />
      <div class="container-inline">
        <div><a class="exit-off-canvas right-bar-cross"></a></div>
        <div class="listserv-subscribe-message">Subscribe to our Available Technology Emails:</div>
        
        <div class="row1">
          <div class="small-12 columns listserv-input-container">
            <div class="form-item form-type-textfield">
              <label class="element-invisible" for="email">Enter Your Email Address</label>  
              <input type="text" name="email" id="email" title="Enter an email address to subscribe." placeholder="Your Email Address..." class="subscribe-form-input-text" />
            </div>
          </div>
          <div class="small-12 columns listserv-submit-container">
            <button class="button radius postfix expand primary form-submit" id="edit-submit" name="commit" value="Subscribe" type="submit">Subscribe</button>
          </div>
        </div>
      </div>
    </form>
  </div>
<?php endif //End block--listserv-block ?>
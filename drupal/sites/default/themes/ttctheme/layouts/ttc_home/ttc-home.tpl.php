<?php
/**
 * @file
 * Template for the homepage.
 *
 * This template provides a the layout for the TTC homepage. See panel regions for more.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['middle']: Content in the middle row.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<?php !empty($css_id) ? print '<div id="' . $css_id . '">' : ''; ?>
  <div class="row">
    <div class="medium-12 columns"><?php print $content['top']; ?></div>
  </div>

  <div class="row">
    <div class="medium-12 columns"><?php print $content['middle']; ?></div>
  </div>

  <div class="row">
    <div class="medium-12 columns"><?php print $content['bottom']; ?></div>
  </div>
<?php !empty($css_id) ? print '</div>' : ''; ?>

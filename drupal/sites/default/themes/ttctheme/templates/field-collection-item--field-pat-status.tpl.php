<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>

<?php
  $hasDesc = isset($content['field_text']);
  $hasLink = isset($content['field_url']);

  $patentStatus = $content['field_patent_status'][0]['#title'];
  $patentLink = $hasLink ? $content['field_url'][0]['#href'] : null;
  $patentDesc = $hasDesc ? $content['field_text'][0]['#markup'] : null;
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="field-pat-status__item"<?php print $content_attributes; ?>>
    <span class="field-pat-status__item-label">
      <?php if (!$hasDesc && $hasLink): ?>
        <a href="<?php print $patentLink; ?>">
      <?php endif; ?>

      <?php print $patentStatus; ?><?php if ($hasDesc): ?>:&nbsp;<?php endif; ?>

      <?php if (!$hasDesc && $hasLink): ?>
        </a>
      <?php endif; ?>
    </span>

    <?php if ($hasDesc): ?>
      <span class="field-pat-status__item-content">
        <?php if ($hasLink): ?>
          <a href="<?php print $patentLink; ?>">
        <?php endif; ?>

        <?php print $patentDesc; ?>

        <?php if ($hasLink): ?>
          </a>
        <?php endif; ?>
      </span>
    <?php endif; ?>
    </span>
  </div>
</div>

<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php

$count = count($rows);
$index = 0;
foreach ($rows as $id => $row): ?>

  <?php if($index ==  floor($count/2) ): ?>
    <div class="flex-break"></div>
  <?php endif; ?>

  <?php $index++; ?>

  <div<?php if ($classes_array[$id]): ?> class="<?php print $classes_array[$id]; ?>"<?php endif; ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>

<?php

/**
 * @file
 * Default template for feed displays that use the RSS style.
 *
 * @ingroup views_templates
 */
?>
<?php print "<?xml"; ?> version="1.0" encoding="UTF-8" <?php print "?>"; ?>

<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
  <?php print $items; ?>
</urlset>

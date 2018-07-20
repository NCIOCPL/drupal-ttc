<?php
/**
 * @file
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
    <url><loc><?php print $link; ?></loc><lastmod><?php print $row->description; ?></lastmod><changefreq>yearly</changefreq></url>

<?php

/**
 * @file
 * Generates the PDF version using dompdf.
 *
 * This file is included by the print_pdf_dompdf module and includes the
 * functions that interface with the dompdf library.
 *
 * @ingroup print
 */

/**
 * Implements hook_print_pdf_generate().
 */
function print_pdf_dompdf_print_pdf_generate($html, $meta, $paper_size = NULL, $page_orientation = NULL) {
  module_load_include('inc', 'print', 'includes/print');

  $pdf_tool = explode('|', variable_get('print_pdf_pdf_tool', PRINT_PDF_PDF_TOOL_DEFAULT));
  if (empty($paper_size)) {
    $paper_size = variable_get('print_pdf_paper_size', PRINT_PDF_PAPER_SIZE_DEFAULT);
  }
  if (empty($page_orientation)) {
    $page_orientation = variable_get('print_pdf_page_orientation', PRINT_PDF_PAGE_ORIENTATION_DEFAULT);
  }
  $images_via_file = variable_get('print_pdf_images_via_file', PRINT_PDF_IMAGES_VIA_FILE_DEFAULT);
  $unicode = TRUE;

  if (variable_get('print_pdf_autoconfig', PRINT_PDF_AUTOCONFIG_DEFAULT)) {
    $font_subsetting = variable_get('print_pdf_dompdf_font_subsetting', PRINT_PDF_DOMPDF_FONT_SUBSETTING_DEFAULT);
    $unicode = variable_get('print_pdf_dompdf_unicode', PRINT_PDF_DOMPDF_UNICODE_DEFAULT);

    if (!defined('DOMPDF_ENABLE_PHP')) {
      define('DOMPDF_ENABLE_PHP', FALSE);
    }
    if (!defined('DOMPDF_ENABLE_REMOTE')) {
      define('DOMPDF_ENABLE_REMOTE', TRUE);
    }
    if (!defined('DOMPDF_TEMP_DIR')) {
      define('DOMPDF_TEMP_DIR', file_directory_temp());
    }
    if (!defined('DOMPDF_UNICODE_ENABLED')) {
      define('DOMPDF_UNICODE_ENABLED', $unicode);
    }
    if (!defined('DOMPDF_ENABLE_FONTSUBSETTING')) {
      define('DOMPDF_ENABLE_FONTSUBSETTING', $font_subsetting);
    }
    if (!defined('DOMPDF_FONT_CACHE')) {
      define('DOMPDF_FONT_CACHE', drupal_realpath('public://print_pdf/print_pdf_dompdf/fonts/'));
    }
  }

  $version = print_pdf_dompdf_pdf_tool_version($pdf_tool[1]);
  if (version_compare($version, '0.7', '<')) {
    // Version of dompdf is 0.6.* or 0.5.*.
    if (version_compare($version, '0.6', '<')) {
      // Version of dompdf is 0.5.
      spl_autoload_register('DOMPDF_autoload');
    }
    // Earlier dompdf versions could generate xml errors. Tell libxml to
    // hide them.
    libxml_use_internal_errors(TRUE);
    $dompdf = new DOMPDF();
  }
  else {
    // Version of dompdf is >= 0.7.
    $tool_path = dirname($pdf_tool[1]) . '/../autoload.inc.php';
    if (file_exists($tool_path)) {
      require_once $tool_path;
    }
    else {
      watchdog('print_pdf', 'Configured PDF tool does not exist at path: %path', array('%path' => $tool_path), WATCHDOG_ERROR);
      throw new Exception("Configured PDF tool does not exist, unable to generate PDF.");
    }

    $dompdf = new \Dompdf\Dompdf();
    $unicode = TRUE;

    if (variable_get('print_pdf_autoconfig', PRINT_PDF_AUTOCONFIG_DEFAULT)) {
      $dompdf->set_option('enable_php', FALSE);
      $dompdf->set_option('enable_remote', TRUE);
      $dompdf->set_option('temp_dir', file_directory_temp());
      $dompdf->set_option('enable_font_subsetting', $font_subsetting);
      $dompdf->set_option('font_cache', drupal_realpath('public://print_pdf/print_pdf_dompdf/fonts/'));
    }
  }

  // Allow third-party modules to alter the dompdf object.
  drupal_alter('print_pdf_dompdf', $dompdf);

  // Try to use local file access for image files.
  $html = _print_access_images_via_file($html, $images_via_file);
  // Remove all scripts due to security concerns.
  $html = preg_replace('!<script(.*?)>(.*?)</script>!is', '', $html);

  // Spaces in img URLs must be replaced with %20, when using external access.
  if (!$images_via_file) {
    $pattern = '!<(img\s[^>]*?)>!is';
    $html = preg_replace_callback($pattern, '_print_replace_spaces', $html);
  }

  // It seems dompdf has problems with something in system.css, don't use it.
  $html = preg_replace('!<link.*?modules/system/system.css.*?/>!', '', $html);

  $url_array = parse_url($meta['url']);

  $protocol = $url_array['scheme'] . '://';
  $host = $url_array['host'];
  $path = dirname($url_array['path']) . '/';

  $dompdf->set_base_path($path);
  $dompdf->set_host($host);
  $dompdf->set_paper(drupal_strtolower($paper_size), $page_orientation);
  $dompdf->set_protocol($protocol);

  // It seems dompdf can't handle footers cleanly, so disable the following.
  /*  $html = theme('print_pdf_dompdf_footer', array('html' => $html)); */

  // If dompdf Unicode support is disabled, try to convert to ISO-8859-1 and
  // then to HTML entities.
  if (!$unicode) {
    // Convert the euro sign to an HTML entity.
    $html = str_replace('€', '&#0128;', $html);

    // Convert from UTF-8 to ISO 8859-1 and then to HTML entities.
    if (function_exists('utf8_decode')) {
      $html = utf8_decode($html);
    }
    elseif (function_exists('mb_convert_encoding')) {
      $html = mb_convert_encoding($html, 'ISO-8859-1', 'UTF-8');
    }
    $html = htmlspecialchars_decode(htmlentities($html, ENT_NOQUOTES, 'ISO-8859-1'), ENT_NOQUOTES);
  }
  else {
    // Otherwise, ensure the content is properly formatted Unicode.
    $html = mb_convert_encoding($html, 'HTML-ENTITIES', 'UTF-8');
  }

  // Must get rid of tbody (dompdf goes into recursion).
  $html = preg_replace('!<tbody[^>]*?>|</tbody>!i', '', $html);

  $dompdf->load_html($html);

  $dompdf->render();
  return $dompdf->output();
}

/**
 * Format the dompdf footer contents.
 *
 * @param array $vars
 *   An associative array containing:
 *    - $html: contents of the body of the HTML from the original node.
 *
 * @return string
 *   customized HTML text
 *
 * @ingroup themeable
 * @ingroup print_themeable
 */
function theme_print_pdf_dompdf_footer($vars) {
  preg_match('!<div class="print-footer">(.*?)</div>!si', $vars['html'], $tpl_footer);
  if (isset($tpl_footer[1])) {
    $html = str_replace($tpl_footer[0], '', $vars['html']);

    $text = '<script type="text/php">
      if (isset($pdf)) {
        $font = Font_Metrics::get_font("verdana");;
        $size = 10;
        $color = array(0,0,0);
        $text_height = Font_Metrics::get_font_height($font, $size);

        $w = $pdf->get_width();
        $h = $pdf->get_height();

        $footer = $pdf->open_object();

        // Draw a line along the bottom
        $y = $h - 25;
        $pdf->line(15, $y, $w - 15, $y, $color, 1);

        $y += $text_height / 2;
        $pdf->page_text(15, $y, \'' . addslashes(strip_tags($tpl_footer[1])) . '\', $font, $size, $color);

        $pdf->close_object();
        $pdf->add_object($footer, "all");

        // Center the text
        $width = Font_Metrics::get_text_width("Page 1 of 2", $font, $size);
        $pagenumtxt = t("Page !n of !total", array("!n" => "{PAGE_NUM}", "!total" => "{PAGE_COUNT}"));
        $pdf->page_text($w - 15 - $width, $y, $pagenumtxt, $font, $size, $color);
      }
    </script>';

    return str_replace("<body>", "<body>" . $text, $html);
  }
  else {
    return $vars['html'];
  }
}

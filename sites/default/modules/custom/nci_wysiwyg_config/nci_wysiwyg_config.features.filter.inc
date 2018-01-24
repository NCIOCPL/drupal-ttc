<?php
/**
 * @file
 * nci_wysiwyg_config.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nci_wysiwyg_config_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'wysiwyg' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'valid_elements' => '@[style],a[href|target<_blank|title|id|name],div[align<center?justify?left?right],p[align<center?justify?left?right],br,span,em,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,img[!src|alt],aside,h2,h3,h4,h5,h6,pre,figure,figcaption,s,q,sub,sup,u,table,caption,tbody,thead,tfoot,tr,td,th,hr',
          'allow_comments' => 0,
          'nofollow_policy' => 'whitelist',
          'nofollow_domains' => array(
            0 => 'techtransfer.cancer.gov',
          ),
          'style_color' => array(
            'color' => 0,
            'background' => 0,
            'background-color' => 0,
            'background-image' => 0,
            'background-repeat' => 0,
            'background-attachment' => 0,
            'background-position' => 0,
          ),
          'style_font' => array(
            'font-size' => 'font-size',
            'font-size-adjust' => 'font-size-adjust',
            'font-stretch' => 'font-stretch',
            'font-style' => 'font-style',
            'font-variant' => 'font-variant',
            'font-weight' => 'font-weight',
            'font' => 0,
            'font-family' => 0,
          ),
          'style_text' => array(
            'text-align' => 'text-align',
            'text-decoration' => 'text-decoration',
            'text-indent' => 'text-indent',
            'text-transform' => 'text-transform',
            'letter-spacing' => 'letter-spacing',
            'word-spacing' => 'word-spacing',
            'white-space' => 'white-space',
            'direction' => 'direction',
            'unicode-bidi' => 'unicode-bidi',
          ),
          'style_box' => array(
            'margin' => 'margin',
            'margin-top' => 'margin-top',
            'margin-right' => 'margin-right',
            'margin-bottom' => 'margin-bottom',
            'margin-left' => 'margin-left',
            'padding' => 'padding',
            'padding-top' => 'padding-top',
            'padding-right' => 'padding-right',
            'padding-bottom' => 'padding-bottom',
            'padding-left' => 'padding-left',
          ),
          'style_border-1' => array(
            'border' => 'border',
            'border-top' => 'border-top',
            'border-right' => 'border-right',
            'border-bottom' => 'border-bottom',
            'border-left' => 'border-left',
            'border-width' => 'border-width',
            'border-top-width' => 'border-top-width',
            'border-right-width' => 'border-right-width',
            'border-bottom-width' => 'border-bottom-width',
            'border-left-width' => 'border-left-width',
          ),
          'style_border-2' => array(
            'border-color' => 'border-color',
            'border-top-color' => 'border-top-color',
            'border-right-color' => 'border-right-color',
            'border-bottom-color' => 'border-bottom-color',
            'border-left-color' => 'border-left-color',
            'border-style' => 'border-style',
            'border-top-style' => 'border-top-style',
            'border-right-style' => 'border-right-style',
            'border-bottom-style' => 'border-bottom-style',
            'border-left-style' => 'border-left-style',
          ),
          'style_dimension' => array(
            'height' => 'height',
            'line-height' => 'line-height',
            'max-height' => 'max-height',
            'max-width' => 'max-width',
            'min-height' => 'min-height',
            'min-width' => 'min-width',
            'width' => 'width',
          ),
          'style_positioning' => array(
            'bottom' => 0,
            'clip' => 0,
            'left' => 0,
            'overflow' => 0,
            'right' => 0,
            'top' => 0,
            'vertical-align' => 0,
            'z-index' => 0,
          ),
          'style_layout' => array(
            'clear' => 'clear',
            'display' => 'display',
            'float' => 'float',
            'position' => 0,
            'visibility' => 0,
          ),
          'style_list' => array(
            'list-style' => 'list-style',
            'list-style-image' => 'list-style-image',
            'list-style-position' => 'list-style-position',
            'list-style-type' => 'list-style-type',
          ),
          'style_table' => array(
            'border-collapse' => 'border-collapse',
            'border-spacing' => 'border-spacing',
            'caption-side' => 'caption-side',
            'empty-cells' => 'empty-cells',
            'table-layout' => 'table-layout',
          ),
          'style_user' => array(
            'cursor' => 0,
            'outline' => 0,
            'outline-width' => 0,
            'outline-style' => 0,
            'outline-color' => 0,
            'zoom' => 0,
          ),
          'rule_valid_classes' => array(),
          'rule_valid_ids' => array(),
          'rule_style_urls' => array(
            0 => '/*',
          ),
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => 10,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}

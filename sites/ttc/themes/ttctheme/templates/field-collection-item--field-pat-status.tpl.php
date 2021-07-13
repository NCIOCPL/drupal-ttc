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

    $hasLink = isset($content['field_url']);
    $hasLabel = isset($content['field_patent_status'][0]['#title']);

    $fieldLabel = $hasLabel ? $content['field_patent_status'][0]['#title'] : '';
    $fieldLink = $hasLink ? $content['field_url'][0]['#href'] : null;
    $application_number = isset($content['field_application_number'][0]) ? $content['field_application_number']['#items'][0]['value']: '';
    $patent_number = isset($content['field_patent_number'][0]) ? $content['field_patent_number']['#items'][0]['value']: '';
    $country =  isset($content['field_patent_authority'][0]) ?$content['field_patent_authority']['#items'][0]['value']: '';
    $filing_date =  isset($content['field_patent_filing_date'][0]) ?$content['field_patent_filing_date']['#items'][0]['value']: '';
    $issue_date =  isset($content['field_patent_issue_date'][0]) ?$content['field_patent_issue_date']['#items'][0]['value']: '';

    $filing_date = $filing_date ? ", Filed " . date('d M Y',strtotime($filing_date)) :  "";
    $issue_date = $issue_date ? ", Issued ".date('d M Y',strtotime($issue_date)): "";


    $search_string = array('[application_no]','[patent_no]','[filed_date]','[country]' , '[issued_date]');
    $replace_string = array($application_number,$patent_number,$filing_date,$country , $issue_date);

    $term = $content['field_patent_status']['#items'][0]['taxonomy_term'];
    $fieldDesc = str_replace($search_string, $replace_string, $term->field_display_text[LANGUAGE_NONE][0]['value'] );
    $hasDesc = true;

?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="field-collection__item"<?php print $content_attributes; ?>>

      <span class="field-collection__item-label">
          <?php print $fieldLabel; ?>:
      </span>
      <span class="field-collection__item-content">
        <?php if ($hasLink): ?>
         <?php print $fieldLabel; ?>: <a href="<?php print $fieldLink; ?>">
        <?php endif; ?>

        <?php print $fieldDesc; ?>

        <?php if ($hasLink): ?>
          </a>
        <?php endif; ?>
      </span>
  </div>
</div>

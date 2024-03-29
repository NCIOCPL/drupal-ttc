<?php

/**
 * @file
 * Default theme implementation to display a term.
 *
 * Available variables:
 * - $name: (deprecated) The unsanitized name of the term. Use $term_name
 *   instead.
 * - $content: An array of items for the content of the term (fields and
 *   description). Use render($content) to print them all, or print a subset
 *   such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $term_url: Direct URL of the current term.
 * - $term_name: Name of the current term.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - taxonomy-term: The current template type, i.e., "theming hook".
 *   - vocabulary-[vocabulary-name]: The vocabulary to which the term belongs to.
 *     For example, if the term is a "Tag" it would result in "vocabulary-tag".
 *
 * Other variables:
 * - $term: Full term object. Contains data that may not be safe.
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $page: Flag for the full page state.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the term. Increments each time it's output.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">

  <?php if (!$page): ?>
    <div class='contact-name'><?php print $term_name; ?></div>
  <?php endif; ?>

  <div class="content">
    <?php print render($content['field_organization_name']);?>
    <?php print render($content['field_contact_phone']);?>
    <?php
    $contact_email = $content['field_contact_email']['#items']['0']['email'] ?? '';
      ?>

    <?php $contact_email_cc = $content['field_contact_email_cc']['#items']['0']['email'] ?? '';
    ?>

    <?php $contact_email_bcc = $content['field_contact_email_bcc']['#items']['0']['email'] ?? '';
    ?>

    <?php
    $email_list = $contact_email . '?subject=NCI TTC Website Inquiry';
    if (!empty($contact_email_cc)) {
      $email_list = $email_list . '&cc=' . $contact_email_cc;
      }
    if (!empty($contact_email_bcc)) {
      $email_list = $email_list . '&bcc=' . $contact_email_bcc;
    }
    ?>

    <div class="field field-name-field-contact-email field-type-email field-label-hidden field-wrapper">
      <div class="field-items">
        <div class="field-item even">
          <a href="mailto:<?php print $email_list;?>" data-extlink=""><?php print $contact_email;?>
            <span class="mailto"><span class="element-invisible">(link sends e-mail)</span></span>
          </a>
        </div>
      </div>
    </div>
  </div>

</div>

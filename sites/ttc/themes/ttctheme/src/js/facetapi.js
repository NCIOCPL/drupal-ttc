(function () {
  'use strict';
  // USed for expanding facets when option selected
  // var facets_expanded = [];
  jQuery(document).ready(function () {
    // Create a link to remove the keyword filter.
    (function () {
      var path = location.pathname.split('/');

      if (path[path.length - 1] === 'all') {
        return;
      }

    // Get the path without the keyword (but with 'all') and add any facets.
      var baseWithFacets = path.slice(0, -1).join('/') + '/all' + location.search;

      jQuery('.facet-selection > li').not(':has(a)')
      .wrapInner('<a href="' + baseWithFacets + '">');
    }());

    // Wrap sorting filters in a span.
    (function () {
      var sortClass = 'abstract-sort';

      function addClassList() {
        var className = this.className;
        var tooltip = this.textContent.trim();
        var $this = jQuery(this);
        var newClasses = [];

        var regexSortName = new RegExp('edit-' + sortClass + '-(.*)-(?:asc|desc)', 'i');
        var regexSelected = /\bselected\b/i;
        var regexAscending = /\basc\b/i;
        var regexDescending = /\bdesc\b/i;

        newClasses.push('-' + className.match(regexSortName)[1]);
        if (regexSelected.test(className)) {
          newClasses.push('is-selected');
        }
        if (regexAscending.test(className)) {
          newClasses.push('-ascending');
        }
        else if (regexDescending.test(className)) {
          newClasses.push('-descending');
        }

        $this.addClass(newClasses.join(' '));

        $this.children('a').attr({
          'data-tooltip': '',
          'aria-haspopup': true,
          'title': tooltip
        });
      }

      jQuery('.form-item-' + sortClass + ' .form-type-bef-link')
        .each(addClassList)
        .children('a')
        .addClass('edit-sort__link')
        .wrapInner('<span class="faceted-sort-button-text">');

      // Re-run Foundation initialization, since we've added tooltips
      jQuery(document).foundation();
    }());
  });


  if (typeof Drupal.facetapi != 'undefined') {
    Drupal.facetapi.makeCheckbox = function () {
      var $link = jQuery(this);
      var isActive = $link.hasClass('facetapi-active');
      if (isActive) {
        $link.closest('.pane-content').prev().addClass('open');
        $link.closest('.pane-content').show();
      }


      var isInactive = $link.hasClass('facetapi-inactive');

      if (!isActive && !isInactive) {
        // Not a facet link.
        return;
      }

      // Derive an ID and label for the checkbox based on the associated link.
      // The label is required for accessibility, but it duplicates information
      // in the link itself, so it should only be shown to screen reader users.
      var id = this.id + '--checkbox';
      var isDisabled = $link.hasClass('facetapi-zero-results');

      // Get just the link label, without text inside an invisible element.
      var description = $link.contents().filter(function () {
        return this.nodeType === 3;
      })[0].nodeValue;

      // Create the elements for insertion.
      var $container = jQuery('<div class="checkbox">');
      var $label = jQuery('<label for="' + id + '">' + description + '</label>');
      var $checkbox = jQuery('<input type="checkbox" class="facetapi-checkbox" id="' + id + '">');

      var href = $link.attr('href');
      var redirect = new Drupal.facetapi.Redirect(href);
      var filterAction;

      $checkbox.click(function (e) {
        Drupal.facetapi.disableFacet($link.parents('ul.facetapi-facetapi-checkbox-links'));
        redirect.gotoHref();
      });

      if (isActive) {
        $checkbox.prop('checked', true);
        filterAction = Drupal.t('Remove filter for: ');
      }
      else {
        filterAction = Drupal.t('Apply filter for: ');
      }

      if (isDisabled) {
        $checkbox.prop('disabled', true);
      }

      // Add accessible text to the label
      $label.prepend('<span class="element-invisible">' + filterAction + '</span>');

      // Set up the container
      // Example markup:
      // <div class="checkbox">
      //   <input id="ID" type="checkbox">
      //   <label for="ID">LABEL</label>
      // </div>
      $container.append($checkbox).append($label);
      // Add the checkbox and label, remove the link
      $link.after($container)
        .remove();
    };
  }
}());

(function ($) {
  'use strict';
  $(document).ready(function () {
    // font awesome 508 fix
    //
    $('#views-exposed-form-ttc-abstract-faceted-results-ctools-context-1').find('.faceted-sort-button-text').addClass('hidden-selected');
    $('#edit-abstract-sort-search-api-aggregation-1-asc a').prepend('<i class="fas fa-sort-alpha-down shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-sort-alpha-up hidden-selected" aria-hidden="true"></i><span class="faceted-sort-button-text shown-selected">Title (descending)</span>');
    $('#edit-abstract-sort-search-api-aggregation-1-desc a').prepend('<i class="fas fa-sort-alpha-up shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-sort-alpha-down hidden-selected" aria-hidden="true"></i><span class="faceted-sort-button-text shown-selected">Title (ascending)</span>');
    $('#edit-abstract-sort-search-api-aggregation-2-asc a').prepend('<i class="fas fa-sort-numeric-down shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-sort-numeric-up hidden-selected" aria-hidden="true"></i><span class="faceted-sort-button-text shown-selected">Reference # (descending)</span>');
    $('#edit-abstract-sort-search-api-aggregation-2-desc a').prepend('<i class="fas fa-sort-numeric-up shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-sort-numeric-down hidden-selected" aria-hidden="true"></i><span class="faceted-sort-button-text shown-selected">Reference # (ascending)</span>');

    $('#edit-abstract-sort-field-posted-date-asc a').prepend('<i class="fas fa-long-arrow-alt-down shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-long-arrow-alt-up hidden-selected" aria-hidden="true"></i>' +
      '<span class="calendar-number-icon" aria-hidden="true"></span><span class="faceted-sort-button-text shown-selected">Posted date (descending)</span>');
    $('#edit-abstract-sort-field-posted-date-desc a').prepend('<i class="fas fa-long-arrow-alt-up shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-long-arrow-alt-down hidden-selected" aria-hidden="true"></i>' +
      '<span class="calendar-number-icon" aria-hidden="true"></span><span class="faceted-sort-button-text shown-selected">Posted date (ascending)</span>');
    $('#edit-abstract-sort-field-updated-date-asc a').prepend('<i class="fas fa-long-arrow-alt-down shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-long-arrow-alt-up hidden-selected" aria-hidden="true"></i>' +
      '<span class="calendar-edit-icon" aria-hidden="true"></span><span class="faceted-sort-button-text shown-selected">Updated Date (descending)</span>');
    $('#edit-abstract-sort-field-updated-date-desc a').prepend('<i class="fas fa-long-arrow-alt-up shown-selected" aria-hidden="true"></i>' +
      '<i class="fas fa-long-arrow-alt-down hidden-selected" aria-hidden="true"></i>' +
      '<span class="calendar-edit-icon" aria-hidden="true"></span><span class="faceted-sort-button-text shown-selected">Updated Date (ascending)</span>');

    // facet selector keyboard support
    $('.pane-facetapi .pane-title').wrapInner("<a href='#' class='facet-type'></a>");
    $('.pane-facetapi .pane-title a').focus(function () {
      $(this).parents('.pane-facetapi').children('.pane-content').toggle();
      $(this).parent('.pane-title').toggleClass('open');
    });
    $('.pane-facetapi .facetapi-checkbox').focus(function () {
      $(this).parent('.checkbox').css({'border-color': '#7777ff', 'border-width': '1px', 'border-style': 'solid'});
    }).focusout(function () {
      $(this).parent('.checkbox').css('border', 'none');
    });
  });
}(jQuery));

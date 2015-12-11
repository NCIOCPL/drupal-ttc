(function () {
  'use strict';

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
          .wrapInner('<span class="element-invisible">');

      // Re-run Foundation initialization, since we've added tooltips
      jQuery(document).foundation();
    }());
  });

  Drupal.facetapi.makeCheckbox = function () {
    var $link = jQuery(this);
    var isActive = $link.hasClass('facetapi-active');
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
}());

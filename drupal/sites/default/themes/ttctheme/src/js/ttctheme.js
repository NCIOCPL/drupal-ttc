(function ($) {
  'use strict';
  $(document).ready(function () {
    // Create a link to remove the keyword filter.
    // match column heights
    $('.listwrapper img').each(function () {
      var highestBox = $('.listwrapper img').height();
      $(this).height(highestBox);
    });
    $('.pane-menu-menu-information ul li.expanded').wrapInner('<div class="li-wrapper"></div>');
    $('body.page-availabletechnologies #search-block-form').clone().addClass('at-search').insertBefore('h2.pane-title');
    $('<h2 class="text-left">Search</h2>').insertBefore('.at-search');
    $('<h2 class="text-left">Browse</h2>').insertAfter('body.page-availabletechnologies .pane-available-technologies .pane-title');
  });
}(jQuery));

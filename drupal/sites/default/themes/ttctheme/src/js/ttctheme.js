(function ($) {
  'use strict';
  $(document).ready(function () {
    // Create a link to remove the keyword filter.
    $('.success-stories__list li').wrapInner("<div class='listwrapper' />");
    // match column heights
    $('.listwrapper img').each(function () {
      var highestBox = $('.listwrapper img').height();
      $(this).height(highestBox);
    });
    $('body.page-availabletechnologies #search-block-form').clone().addClass('at-search').insertBefore('h2.pane-title');
    $('<h2 class="text-left">Search</h2>').insertBefore('.at-search');
    $('<h2 class="text-left">Browse</h2>').insertAfter('body.page-availabletechnologies .pane-available-technologies .pane-title');
  });
}(jQuery));

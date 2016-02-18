(function ($) {
  'use strict';
  $(document).ready(function () {

    var cookies = document.cookie;
    if (cookies.indexOf('has_js') >= 0) {
      // ensure has_js is set to secure
      document.cookie = 'has_js=1;secure;';
    }

    // Create a link to remove the keyword filter.
    // match column heights
    $('.listwrapper img').each(function () {
      var highestBox = $('.listwrapper img').height();
      $(this).height(highestBox);
    });
    $('.pane-menu-menu-information ul li.expanded').wrapInner('<div class="li-wrapper"></div>');

    //  prevent first level menu in information panel from being link
    $('.pane-menu-menu-information a.active').on('click', function (e) {
      e.preventDefault();
    });

    // social links target blank new window
    $('.follow-us__list-item a').attr('target', '_blank');

    // success stories images into background image of parent
    $('.success-stories__image img').each(function () {
      var thisurl = $(this).attr('src');
      $(this).parent('.success-stories__image').css('background-image', 'url(' + thisurl + ')');
    });

    // highlight the subscribe form if there is a submittal error
    $('.listserv-subscribe-block').each(function () {
      if ($(this).html().indexOf('Please enter a valid email') > -1) {
        $('.row').addClass('highlighted-error');
      }
    });

    // stay on listserv form after submitting
    if (location.search.indexOf('op=Subscribe') > -1) {
      var scrollheight = document.body.scrollHeight;
      var offset = 1100;
      window.scrollTo(0, (scrollheight - offset));
    }

    // facet search drop down functionality
    $('.panels-flexible-region-new-facets-inside .pane-title, .sidebarnav_wrapper .pane-title').on('click', function () {
      $(this).next('.pane-content').toggle();
      $(this).toggleClass('open');
    });

    // color coding for taxonomy terms copy the text and make it the lowercase class
    $('.taxonomy-terms li').each(function () {
      var taxclass = '-' + $(this).text().toLowerCase().replace(' ', '-');
      $(this).addClass(taxclass);
    });

    // font size adjuster
    $('.decfont').click(function () {
      var curSize = parseInt($('#mainid article *').css('font-size')) + 1;
      if (curSize <= 22) {
        $('#mainid p, #mainid li, #mainid article *, #mainid article p').css('font-size', curSize);
      }
    });
    $('.incfont').click(function () {
      var curSize = parseInt($('#mainid article *').css('font-size')) - 1;
      if (curSize >= 16) {
        $('#mainid p, #mainid li, #mainid article *, #mainid article p').css('font-size', curSize);

      }
    });


    // show all abstract search images if any concrete img elements exist
    var $images = jQuery('article.node-abstract.node-teaser .image');
    if ($images.find('img').size() > 0) {
      $images.show();
    }
    $('nav.left-off-canvas-menu li.expanded a.active').next('ul.menu').addClass('show');
    $('nav.left-off-canvas-menu li.expanded a.active').parents('li.expanded').find('a.active').addClass('open');
    $('.block-search-form').clone().insertAfter('.mobile-menu').removeClass('header').addClass('mobile-search hidden-for-large-up');
    $('.search-toggle').click(function () {
      $('.mobile-search').toggleClass('show');
    });
    $('<span class="mplus"/>').insertAfter('ul.menu li.expanded > a');
    $('.mplus').on('click', function () {
      $(this).toggleClass('open').next('ul.menu').slideToggle();
    });
  });
}(jQuery));

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

    var adjust_font_size = function (inc) {
      var curSize = parseInt($('#mainid article *').css('font-size')) + inc;
      if (curSize <= 22) {
        $('#mainid p, #mainid li, #mainid article *, #mainid article p').css('font-size', curSize);
      }
    };

    // font size adjuster
    $('.incfont').click(function () {
      event.preventDefault();
      adjust_font_size(1);
    });
    $('.decfont').click(function () {
      event.preventDefault();
      adjust_font_size(-1);
    });
    $(window).keydown(function (event) {
      var keycode = (event.keyCode ? event.keyCode : event.which);
      switch (keycode) {
        case 187:
          adjust_font_size(1);
          break;
        case 189:
          adjust_font_size(-1);
          break;
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
    // Add home link to mobile menu
    //$('<li class="home"><a href="/">Home</a></li>').prependTo('.left-off-canvas-menu > ul.menu');
    $('<span class="mplus"/>').insertAfter('ul.menu li.expanded > a');
    $('.mplus').on('click', function () {
      $(this).toggleClass('open').next('ul.menu').slideToggle();
      $(this).parents('li').addClass('ulopen');
    });
    // active mobile menu for pages
    $('li .expanded .active').next('.mplus').addClass('open').next('ul.menu').addClass('show');
    $('.mplus.open').parent().addClass('active');
    $('li.active').parent().addClass('show');
    $('ul.menu.show').parent().addClass('active');
    // leaf items menu trail
    $('li.leaf a.active.open').parent().addClass('active');
    $('li.leaf.active, li.expanded.active').parent().addClass('show');
    $('ul.show').parent().addClass('active');
    $('li.active').parent().addClass('show');

    // wrap sidebar with span and html to match comps for mobile
    $('<span class="sidebar-mobile-link hide-for-large-up">Find Other Available Technologies</span>').prependTo('body.section-availabletechnologies .sidebarnav_wrapper');
    $('.sidebar-mobile-link').on('click', function () {
      $('* .sidebarnav_wrapper .block-panels-mini, .sidebarnav_wrapper .inside').slideToggle();
      $(this).toggleClass('open');
    });
    // 508 fix on duplicated labels
    var value = $('.mobile-search .form-item-search-block-form label').attr('for');
    $('.mobile-search .form-item-search-block-form label').attr('for', value + 'm');
    value = $('.mobile-search .form-item-search-block-form input').attr('id');
    $('.mobile-search .form-item-search-block-form input').attr('id', value + 'm');
    // 508 fix for tabindex
    $('.left-off-canvas-menu a, .right-off-canvas-menu a, .mobile-menu a').attr('tabindex', '-1');

    // External Link Change.
    var path = "https://www.cancer.gov/policies/linking";
    var altText = "Exit Disclaimer";
    $("a").filter(function () {
      return /^https?\:\/\/([a-zA-Z0-9\-]+\.)+/.test(this.href)
          && !/^https?\:\/\/([a-zA-Z0-9\-]+\.)+hhs\.gov/.test(this.href)
          && !/^https?\:\/\/([a-zA-Z0-9\-]+\.)+nih\.gov/.test(this.href)
          && !/^https?\:\/\/([a-zA-Z0-9\-]+\.)+usa\.gov/.test(this.href)
          && !/^https?\:\/\/([a-zA-Z0-9\-]+\.)+cancer\.gov/.test(this.href)
          && this.href != "" && this.href.indexOf(location.protocol +"//" +location.hostname) != 0
          && $(this).parents('.follow-us').length == 0  }).
      after(' <a class="exitNotification" href=' + path + '><img title='+ '"' + altText +'"' +'  alt='+ '"' + altText +'"' + ' src="/sites/all/modules/contrib/extlink/extlink.png" /></a>');
    if($('.with-image').length == 0){
        $('.list-spacer-image').addClass('image-collapsed');
        $('.list-item-with-image').addClass('text-collapsed');
    }


    // Expand collapse mobile only
    $('.pane-available-institutes .pane-title').click(function (event) {
        event.preventDefault();
        var windowWidth = $(window).width();
        if(windowWidth <= 1024) {
            $('.pane-available-institutes .pane-content').toggleClass("visible");
            $('.pane-available-institutes .pane-title').toggleClass("expanded");
        }

    });


  });
}(jQuery));

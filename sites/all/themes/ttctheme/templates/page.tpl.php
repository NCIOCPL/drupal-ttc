
<!--.page -->
<div role="document" class="page">

  <!--.l-header -->
  <header role="banner" class="l-header">

    <?php if ($top_bar): ?>
      <!--.top-bar -->
      <?php if ($top_bar_classes): ?>
        <div class="<?php print $top_bar_classes; ?>">
      <?php endif; ?>
      <nav class="top-bar" data-topbar <?php print $top_bar_options; ?>>
        <ul class="title-area">
          <li class="name"><h1><?php print $linked_site_name; ?></h1></li>
          <li class="toggle-topbar menu-icon">
            <a href="#"><span><?php print $top_bar_menu_text; ?></span></a></li>
        </ul>
        <section class="top-bar-section">
          <?php if ($top_bar_main_menu) : ?>
            <?php print $top_bar_main_menu; ?>
          <?php endif; ?>
          <?php if ($top_bar_secondary_menu) : ?>
            <?php print $top_bar_secondary_menu; ?>
          <?php endif; ?>
        </section>
      </nav>
      <?php if ($top_bar_classes): ?>
        </div>
      <?php endif; ?>
      <!--/.top-bar -->
    <?php endif; ?>

    <?php if ($alt_header && $show_alt_header): ?>
      <!-- Title, slogan and menu -->
      <section class="row <?php print $alt_header_classes; ?>">

        <?php if ($linked_logo): print $linked_logo; endif; ?>

        <?php if ($site_name): ?>
          <?php if ($title): ?>
            <div id="site-name" class="element-invisible">
              <strong>
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </strong>
            </div>
          <?php else: /* Use h1 when the content title is empty */ ?>
            <h1 id="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
            </h1>
          <?php endif; ?>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <h2 title="<?php print $site_slogan; ?>" class="site-slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>

        <?php if ($alt_main_menu): ?>
          <nav id="main-menu" class="navigation" role="navigation">
            <?php print ($alt_main_menu); ?>
          </nav> <!-- /#main-menu -->
        <?php endif; ?>

        <?php if ($alt_secondary_menu): ?>
          <nav id="secondary-menu" class="navigation" role="navigation">
            <?php print $alt_secondary_menu; ?>
          </nav> <!-- /#secondary-menu -->
        <?php endif; ?>

      </section>
      <!-- End title, slogan and menu -->
    <?php endif; ?>

    <?php if (!empty($page['header'])): ?>
      <!--.l-header-region -->
      <section class="l-header-region row">
        <div class="columns">
          <?php print render($page['header']); ?>
        </div>
      </section>
      <!--/.l-header-region -->
    <?php endif; ?>

  </header>
  <!--/.l-header -->
  <!--.l-main -->
  <main role="main" class="main row">
    <nav class="mobile-menu hidden-for-large-up">
        <a role="button" href="#idOfLeftMenu" class="left-off-canvas-toggle small-3">Menu <i class="fa fa-bars" aria-hidden="true"></i></a>
        <a role="button" href="#search" class="search-toggle small-3">Search <i class="fa fa-search" aria-hidden="true"></i></a>
        <a role="button" href="#follow" class="right-off-canvas-toggle small-3">Follow <i class="fa fa-mouse-pointer" aria-hidden="true"></i>
</a>
    </nav>
  <div class="main-wrapper">
    <!-- .l-main region -->
    <div class="main__inner row">

      <?php if ($messages && !$zurb_foundation_messages_modal): ?>
        <!--.l-messages -->
        <aside role="complementary" class="messages columns">
          <?php if ($messages): print $messages; endif; ?>
        </aside>
        <!--/.l-messages -->
      <?php endif; ?>

      <?php if (!empty($page['help'])): ?>
        <!--.l-help -->
        <aside role="complementary" class="help columns">
          <?php print render($page['help']); ?>
        </aside>
        <!--/.l-help -->
      <?php endif; ?>

      <?php if (!empty($page['featured'])): ?>
        <!--.l-featured -->
        <section class="featured columns">
          <?php print render($page['featured']); ?>
        </section>
        <!--/.l-featured -->
      <?php endif; ?>
      
       <?php if ($breadcrumb): ?>
          <?php print $breadcrumb; ?>
        
		  <!-- Display share buttons -->
		  <div class='addthis'>
          <span class="label">Share: </span>
			<a class="addthis_button_linkedin" title="LinkedIn" href="#"></a>
			<a class="addthis_button_twitter" title="Twitter" href="#"></a>
			<a class="addthis_button_email" title="Email" href="#"></a>
			<a class="addthis_button_print" title="Print" href="#"></a>
			<!-- Go to www.addthis.com/dashboard to customize your tools -->
			<!-- TODO: set up addthis account if necessary -->
			<!-- TODO: add styling to the buttons instead of using addthis defaults -->
			<script type="text/javascript" src="//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-5688053d43fd3757" async="async"></script>
		  </div>
		<?php endif; ?>      

      <?php if (!empty($page['sidebar_first'])): ?>
        <aside role="complementary" class="sidebar-first columns sidebar show-for-large-up large-3">
          <div class="sidebarnav_wrapper"><?php print render($page['sidebar_first']); ?></div>
        </aside>
      <?php endif; ?>

          <div id="mainid" class="large-12 columns main__content">

    
        <?php if (!empty($page['highlighted'])): ?>
          <div class="highlight panel callout">
            <?php print render($page['highlighted']); ?>
          </div>
        <?php endif; ?>

        <a id="main-content"></a>
	
        <?php if ($title): ?>
          <?php print render($title_prefix); ?>
          <h1 id="page-title" class="title"><?php print $title; ?></h1>
          <?php print render($title_suffix); ?>
        <?php endif; ?>

        <?php if (!empty($tabs)): ?>
          <?php print render($tabs); ?>
          <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
        <?php endif; ?>

        <?php if ($action_links): ?>
          <ul class="action-links">
            <?php print render($action_links); ?>
          </ul>
        <?php endif; ?>

        <?php print render($page['content']); ?>
      </div>
      <!--/.l-main region -->


      <?php if (!empty($page['sidebar_second'])): ?>
        <aside role="complementary" class="<?php print $sidebar_sec_grid; ?> sidebar-second columns sidebar">
          <?php print render($page['sidebar_second']); ?>
        </aside>
      <?php endif; ?>
    </div>
   </div>
  </main>
  <!--/.l-main -->

  <?php if (!empty($page['triptych_first']) || !empty($page['triptych_middle']) || !empty($page['triptych_last'])): ?>
    <!--.triptych-->
    <section class="l-triptych row">
      <div class="triptych-first medium-4 columns">
        <?php print render($page['triptych_first']); ?>
      </div>
      <div class="triptych-middle medium-4 columns">
        <?php print render($page['triptych_middle']); ?>
      </div>
      <div class="triptych-last medium-4 columns">
        <?php print render($page['triptych_last']); ?>
      </div>
    </section>
    <!--/.triptych -->
  <?php endif; ?>

  <?php if (!empty($page['footer_firstcolumn']) || !empty($page['footer_secondcolumn']) || !empty($page['footer_thirdcolumn']) || !empty($page['footer_fourthcolumn'])): ?>
    <!--.footer-columns -->
    <section class="row l-footer-columns">
      <?php if (!empty($page['footer_firstcolumn'])): ?>
        <div class="footer-first medium-3 columns">
          <?php print render($page['footer_firstcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_secondcolumn'])): ?>
        <div class="footer-second medium-3 columns">
          <?php print render($page['footer_secondcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_thirdcolumn'])): ?>
        <div class="footer-third medium-3 columns">
          <?php print render($page['footer_thirdcolumn']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['footer_fourthcolumn'])): ?>
        <div class="footer-fourth medium-3 columns">
          <?php print render($page['footer_fourthcolumn']); ?>
        </div>
      <?php endif; ?>
    </section>
    <!--/.footer-columns-->
  <?php endif; ?>

  <!--.l-footer -->
  <footer class="l-footer panel row" role="contentinfo">
    <?php if (!empty($page['footer'])): ?>
      <div class="footer columns">
        <?php print render($page['footer']); ?>
      </div>
    <?php endif; ?>
    
    <?php if ($site_hhs_disclaimer) : ?>
      <div class="disclaimer columns">
        <?php print $site_hhs_disclaimer; ?>
      </div>
    <?php endif; ?>

    <?php if ($site_name) : ?>
      <div class="copyright columns">
        &copy; <?php print date('Y') . ' ' . $site_name . ' ' . t('All rights reserved.'); ?>
      </div>
    <?php endif; ?>
  </footer>
  <!--/.l-footer -->

  <?php if ($messages && $zurb_foundation_messages_modal): print $messages; endif; ?>
</div>
<!--/.page -->
          <nav class="left-off-canvas-menu">
            <?php print render($menu_site_structure_expanded); ?> 
          </nav> <!-- /#mobile-menu --> 
          
          <nav class="right-off-canvas-menu" id="follow">
            <?php
            $block = module_invoke('block', 'block_view', '2');
            print render($block['content']);
            ?>
          </nav> <!-- /#mobile-follow-menu -->     

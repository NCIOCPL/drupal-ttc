/* eslint-env node */

module.exports = function (grunt) {
  'use strict';

  require('load-grunt-tasks')(grunt);

  var theme_name = 'ttctheme';
  var base_theme_path = 'bower_components/foundation';

  var global_vars = {
    theme: {
      base: base_theme_path,
      name: theme_name,
      src: {
        scss: 'src/scss',
        js: 'src/js'
      },
      dist: {
        css: 'public/css',
        js: 'public/js'
      }
    }
  };

  // array of javascript libraries to include.
  var jsLibs = [
    '<%= global_vars.theme.base %>/js/vendor/placeholder.js',
    '<%= global_vars.theme.base %>/js/vendor/fastclick.js'
  ];

  // array of foundation javascript components to include.
  var jsFoundation = [
    '<%= global_vars.theme.base %>/js/foundation/foundation.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.abide.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.accordion.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.alert.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.clearing.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.dropdown.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.equalizer.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.interchange.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.joyride.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.magellan.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.offcanvas.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.orbit.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.reveal.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.slider.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.tab.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.tooltip.js',
    '<%= global_vars.theme.base %>/js/foundation/foundation.topbar.js'
  ];

  // array of custom javascript files to include.
  var jsApp = [
    '<%= global_vars.theme.src.js %>/**/ttctheme.js',
    '<%= global_vars.theme.src.js %>/**/facetapi.js'

  ];

  grunt.initConfig({
    global_vars: global_vars,
    pkg: grunt.file.readJSON('package.json'),

    drush: {
      cc: {
        args: ['cache-clear', 'all']
      }
    },

    sass: {
      options: {
        includePaths: require('node-bourbon').with('<%= global_vars.theme.src.scss %>', '<%= global_vars.theme.base %>/scss/')
      },
      dev: {
        options: {
          outputStyle: 'expanded',
          sourceMap: true
        },
        files: {
          '<%= global_vars.theme.dist.css %>/<%= global_vars.theme.name %>.css': '<%= global_vars.theme.src.scss %>/<%= global_vars.theme.name %>.scss',
          '<%= global_vars.theme.dist.css %>/<%= global_vars.theme.name %>_pdf.css': '<%= global_vars.theme.src.scss %>/<%= global_vars.theme.name %>_pdf.scss'
        }
      },
      prod: {
        options: {
          outputStyle: 'compressed'
        },
        files: {
          '<%= global_vars.theme.dist.css %>/<%= global_vars.theme.name %>.css': '<%= global_vars.theme.src.scss %>/<%= global_vars.theme.name %>.scss',
          '<%= global_vars.theme.dist.css %>/<%= global_vars.theme.name %>_pdf.css': '<%= global_vars.theme.src.scss %>/<%= global_vars.theme.name %>_pdf.scss'
        }
      }
    },

    eslint: {
      options: {
        configFile: '.eslintrc'
      },
      all: [
        'Gruntfile.js',
        jsApp
      ]
    },

    uglify: {
      options: {
        sourceMap: false
      },
      dist: {
        files: {
          '<%= global_vars.theme.dist.js %>/libs.min.js': [jsLibs],
          '<%= global_vars.theme.dist.js %>/foundation.min.js': [jsFoundation],
          '<%= global_vars.theme.dist.js %>/app.min.js': [jsApp]
        }
      },
      dev: {
        options: {
          mangle: false,
          compress: false,
          beautify: true
        },
        files: {
          '<%= global_vars.theme.dist.js %>/libs.min.js': [jsLibs],
          '<%= global_vars.theme.dist.js %>/foundation.min.js': [jsFoundation],
          '<%= global_vars.theme.dist.js %>/app.min.js': [jsApp]
        }
      }
    },

    watch: {
      options: {
        livereload: true
      },

      grunt: {
        files: ['Gruntfile.js']
      },

      sass: {
        files: '<%= global_vars.theme.src.scss %>/**/*.scss',
        tasks: ['sass:dev']
      },

      js: {
        files: [
          jsLibs,
          jsFoundation,
          '<%= eslint.all %>'
        ],
        tasks: ['eslint', 'uglify:dist']
      }
    }
  });

  grunt.registerTask('build-dev', ['eslint', 'uglify:dev', 'sass:dev']);
  grunt.registerTask('build', ['eslint', 'uglify:dist', 'sass:dev']);
  grunt.registerTask('deploy', ['eslint', 'uglify:dist', 'sass:prod']);
  grunt.registerTask('default', ['build', 'watch']);
};

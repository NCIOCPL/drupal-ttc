/* global CKEDITOR */

/*
 * Custom configuration for CKEditor.
 */

CKEDITOR.editorConfig = function (config) {
  'use strict';
};

CKEDITOR.on('dialogDefinition', function (event) {
  'use strict';
  // Take the dialog name and its definition from the event data.
  var dialogName = event.data.name;
  var dialogDefinition = event.data.definition;

  // Check if the definition is from the Table dialog window.
  if (dialogName === 'table') {
    // Get a reference to the "Table Info" tab.
    var infoTab = dialogDefinition.getContents('info');

    // Reset defaults to empty
    var resets = ['txtBorder', 'txtWidth', 'txtCellSpace', 'txtCellPad'];
    for (var i = resets.length - 1; i >= 0; i--) {
      infoTab.get(resets[i])['default'] = '';
    }

    // Default headers to columns
    infoTab.get('selHeaders')['default'] = 'row';
  }
});

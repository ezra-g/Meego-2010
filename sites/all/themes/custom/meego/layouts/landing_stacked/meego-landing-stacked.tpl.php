<?php
// $Id: meego-landing-stacked.tpl.php,v 1.1 2010/02/10 15:31:55 mshaver Exp $

/**
 * @file
 * Template for a 3 row, 2 column in top and mid rows, and 1 column in the bottom row.
 *
 * This template provides a 3 row panel display layout, with
 * 2 columns in the top and mid rows, and  1 column in the bottom row.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top_left']: Content in the top left column (fixed at 460px).
 *   - $content['top_right']: Content in the top right column (fixed at 300px). 
 *   - $content['mid_left']: Content in the mid left column (fixed at 460px).
 *   - $content['mid_right']: Content in the mid right column (fixed at 300px).  
 *   - $content['bottom']: Content in the bottom row.
 */
?>

<div class="panel-display meego-landing-stacked clearfix"<?php if (!empty($css_id)) { print ' id="' . $css_id . '"'; } ?>>

  <div class="center-wrapper top clearfix">
    <div class="panel-panel panel-col-first">
      <div class="inside"><?php print $content['top_left']; ?></div>
    </div>

    <div class="panel-panel panel-col-last">
      <div class="inside"><?php print $content['top_right']; ?></div>
    </div>
  </div>
  
  <div class="center-wrapper mid clearfix">
    <div class="panel-panel panel-col-first">
      <div class="inside"><?php print $content['mid_left']; ?></div>
    </div>

    <div class="panel-panel panel-col-last">
      <div class="inside"><?php print $content['mid_right']; ?></div>
    </div>
  </div>  

  <div class="panel-panel panel-col-bottom clearfix">
    <div class="inside"><?php print $content['bottom']; ?></div>
  </div>

</div> <!-- /.meego-landing-stacked -->

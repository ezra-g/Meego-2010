<?php
// $Id: book-navigation.tpl.php,v 1.1 2007/11/04 14:29:09 goba Exp $

/**
 * @file book-navigation.tpl.php
 * Default theme implementation to navigate books. Presented under nodes that
 * are a part of book outlines.
 *
 * Available variables:
 * - $tree: The immediate children of the current node rendered as an
 *   unordered list.
 * - $current_depth: Depth of the current node within the book outline.
 *   Provided for context.
 * - $prev_url: URL to the previous node.
 * - $prev_title: Title of the previous node.
 * - $parent_url: URL to the parent node.
 * - $parent_title: Title of the parent node. Not printed by default. Provided
 *   as an option.
 * - $next_url: URL to the next node.
 * - $next_title: Title of the next node.
 * - $has_links: Flags TRUE whenever the previous, parent or next data has a
 *   value.
 * - $book_id: The book ID of the current outline being viewed. Same as the
 *   node ID containing the entire outline. Provided for context.
 * - $book_url: The book/node URL of the current outline being viewed.
 *   Provided as an option. Not used by default.
 * - $book_title: The book/node title of the current outline being viewed.
 *   Provided as an option. Not used by default.
 *
 * @see template_preprocess_book_navigation()
 */
?>
<?php if ($tree || $has_links): ?>
  <div id="book-navigation-<?php print $book_id; ?>" class="book-navigation clearfix">

    <?php if ($has_links && $current_depth != 1): ?>
    <ul class="links inline">
      <?php if ($prev_url) : ?>
        <li><a href="<?php print $prev_url; ?>" title="<?php print t('Previous page'); ?>"><?php print t('‹ ') . t('Previous page'); ?></a></li>
      <?php endif; ?>
      <?php if ($parent_url) : ?>
        <li><a href="<?php print $parent_url; ?>" title="<?php print t('Parent page'); ?>"><?php print t('up'); ?></a></li>
      <?php endif; ?>
      <?php if ($next_url) : ?>
        <li><a href="<?php print $next_url; ?>" title="<?php print t('Next page'); ?>"><?php print t('Next page') . t(' ›'); ?></a></li>
      <?php endif; ?>
    </ul>
    <?php endif; ?>

  </div>
<?php endif; ?>

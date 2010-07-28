<?php
// $Id: views-bonus-export-csv.tpl.php,v 1.6 2010/07/20 12:09:17 neclimdul Exp $
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $rows: An array of row items. Each row is an array of content
 *   keyed by field ID.
 * - $header: an array of haeaders(labels) for fields.
 * - $themed_rows: a array of rows with themed fields.
 * - $items:
 * - $separator: The separator used to separate fields. generally comma's but
 *   sometimes people use other values in CSVs.
 * @ingroup views_templates
 */

// Print out header row, if option was selected.
if ($options['header']) {
  print implode($separator, $header) . "\r\n";
}

// Print out exported items.
foreach ($themed_rows as $count => $item_row):
  print implode($separator, $item_row) . "\r\n";
endforeach;

<?php
// $Id: views-view-table.tpl.php,v 1.8 2009/01/28 00:43:43 merlinofchaos Exp $
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * @ingroup views_templates
 */
?>
<?php 

 // Assemble all result rows into an array keyed by days
  foreach ($rows as $row) {
    $day = $row['field_day_value'];
    $slot = $row['field_slot_value'];
    $room = $row['field_room_value'];
    $nid = $row['nid'];
    $schedule[$slot][$room] = $row;
    $room_list[$room] = $room;
   //$schedule[timeslot][room][session_index][session_data]
  unset($row);
} 
  $room_list['blank'] = '  ';
  sort($room_list);
 // Theme the rows.
 // 
  dpm($schedule, 'schedule');

  //
  $header = array_values($room_list);
  // for each slot, find all session node titles and list in order of rooms.
  foreach($schedule as $slot => $rooms) {
    // Use $room_list for a consistent order of rooms.
    // Prepare each session that goes in this slot.
    foreach($room_list as $key => $val) {
      $this_slot[] = $rooms[$val]['title'];
    }
    $slot = array($slot);
    // Add a row starting with slot name, then each session.
    $table_rows[] = array_merge($slot, $this_slot);
  }
  $output = theme('table', $header, $table_rows);
  dpm($header, 'header');
  dpm($table_rows, 'rows');
  print $output;  

<?php foreach ($days as $day_key => $day_title): ?>
  <h2><?php print $day_title; ?></h2>
  <table class="session-calendar">
    <tr>
      <th><?php print t('Time'); ?></th>
    <?php foreach ($rooms as $room_key => $room_title): ?>
      <th><span class="room-label"><?php print $room_title; ?></th>
    <?php endforeach ?>
    </tr>
    <?php foreach ($arranged_slots[$day_key] as $slot): ?>
      <tr class="<?php print $zebra = $zebra == 'even' ? 'odd':'even'; ?>">
        <td class="time-label">
          <?php print $slot['start']; ?>&nbsp;-<br /><?php print $slot['end']; ?>
        </td>
        <?php foreach (array_keys($rooms) as $room_key): ?>
          <?php if (!empty($session_grid[$slot['nid']][$room_key]['session'])): ?>
          <td class="session occupied" <?php if (!empty($session_grid[$slot['nid']][$room_key]['colspan'])): ?>colspan="<?php print $session_grid[$slot['nid']][$room_key]['colspan']; ?>"<?php endif ?>>
            <div class="views-item type-<?php print check_plain($session_grid[$slot['nid']][$room_key]['session']->type); ?>">
            <?php print $results[$session_grid[$slot['nid']][$room_key]['session']->nid]; ?>
            </div>
          </td>
          <?php elseif (empty($session_grid[$slot['nid']][$room_key]['spanned'])): ?>
          <td class="session empty">&nbsp;</td>
          <?php endif ?>
        <?php endforeach ?>
      </tr>
    <?php endforeach ?>
  </table>
<?php endforeach ?>
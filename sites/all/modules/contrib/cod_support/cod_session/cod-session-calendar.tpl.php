<?php foreach ($days as $day_key => $day_title): ?>
  <h2><?php print $day_title; ?></h2>
  <table>
    <tr>
      <th><?php print t('Time'); ?>\<?php print t('Room'); ?></th>
    <?php foreach ($rooms as $room_key => $room_title): ?>
      <th><?php print $room_title; ?></th>
    <?php endforeach ?>
    </tr>
    <?php foreach ($arranged_slots[$day_key] as $slot): ?>
      <tr class="<?php print $zebra = $zebra == 'even' ? 'odd':'even'; ?>">
        <td>
          <?php print $slot['start']; ?> -<br /><?php print $slot['end']; ?>
        </td>
        <?php foreach (array_keys($rooms) as $room_key): ?>
          <td>
            <?php if (!empty($session_grid[$slot['nid']][$room_key])): ?>
              <?php foreach ($session_grid[$slot['nid']][$room_key] as $session): ?>
                <div class="views-item">
                <?php print $results[$session->nid]; ?>
                </div>
              <?php endforeach ?>
            <?php endif ?>
          </td>
        <?php endforeach ?>
      </tr>
    <?php endforeach ?>
  </table>
<?php endforeach ?>
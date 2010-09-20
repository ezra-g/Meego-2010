<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function conference_t_shirt_design_contest_user_default_permissions() {
  $permissions = array();

  // Exported permission: create tshirt_design content
  $permissions['create tshirt_design content'] = array(
    'name' => 'create tshirt_design content',
    'roles' => array(
      '0' => 'site administrator',
    ),
  );

  // Exported permission: delete any tshirt_design content
  $permissions['delete any tshirt_design content'] = array(
    'name' => 'delete any tshirt_design content',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: delete own tshirt_design content
  $permissions['delete own tshirt_design content'] = array(
    'name' => 'delete own tshirt_design content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit any tshirt_design content
  $permissions['edit any tshirt_design content'] = array(
    'name' => 'edit any tshirt_design content',
    'roles' => array(
      '0' => 'content administrator',
      '1' => 'session organizer',
      '2' => 'site administrator',
    ),
  );

  // Exported permission: edit field_tshirt_description
  $permissions['edit field_tshirt_description'] = array(
    'name' => 'edit field_tshirt_description',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit field_tshirt_image
  $permissions['edit field_tshirt_image'] = array(
    'name' => 'edit field_tshirt_image',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site administrator',
    ),
  );

  // Exported permission: edit own tshirt_design content
  $permissions['edit own tshirt_design content'] = array(
    'name' => 'edit own tshirt_design content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: view field_tshirt_description
  $permissions['view field_tshirt_description'] = array(
    'name' => 'view field_tshirt_description',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view field_tshirt_image
  $permissions['view field_tshirt_image'] = array(
    'name' => 'view field_tshirt_image',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache tshirt_grid_view
  $permissions['view imagecache tshirt_grid_view'] = array(
    'name' => 'view imagecache tshirt_grid_view',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view imagecache tshirt_node_view
  $permissions['view imagecache tshirt_node_view'] = array(
    'name' => 'view imagecache tshirt_node_view',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}

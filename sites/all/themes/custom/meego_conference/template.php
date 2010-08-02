<?php
// $Id: template.php,v 1.14 2008/06/19 21:20:06 johnalbin Exp $

/**
 * Implementation of HOOK_theme().
 */
function meego_conference_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  // Add your theme hooks like this:
  /*
  $hooks['hook_name_here'] = array( // Details go here );
  */
  // @TODO: Needs detailed comments. Patches welcome!
  return $hooks;
}

/**
 * Override or insert PHPTemplate variables into all templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function meego_conference_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert PHPTemplate variables into the page templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called ("page" in this case.)
 */
function meego_conference_preprocess_page(&$vars, $hook) {

	// Linux Foundation logo in footer
	$vars['linux_foundation'] = '<a href="http://linuxfoundation.org" title="Linux Foundation">'.theme('image', path_to_theme() .'/images/linux_foundation_color.png', t('Linux Foundation')).'</a><br />';

}

/**
 * Override or insert PHPTemplate variables into the node templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called ("node" in this case.)
 */

function meego_conference_preprocess_node(&$vars, $hook) {
	$node = $vars['node'];
	$taxonomy = _meego_conference_sort_node_taxonomy($node); // our own utility function
	
	// Comment count for each node
	if (isset($node->comment_count) && $node->comment_count >= 1) {
		$comments = format_plural($node->comment_count, '1 comment', '@count comments');
    $vars['comment_link'] = ' - '.l($comments, "node/$node->nid", array('attributes' => array('title' => t('Jump to comments')), 'fragment' => 'comments-title'));
  }
	elseif ($node->comment != 0) {
		$vars['comment_link'] = ' - '.t('0 comments');
	}
	
	// New comments for a node and user
	if (comment_num_new($node->nid)) {
		$comments_new = comment_num_new($node->nid);
		$vars['comments_new'] = l($comments_new.t(' new'), "node/$node->nid", array('attributes' => array('title' => t('Jump to first new comment')), 'fragment' => 'new'));
	}
	
	// Device -- linked to landing page
	$device = $taxonomy[1];
	if ($device) {
		foreach ($device as $key => $term) {
			// special link for device types; maybe others
		  $href = 'devices/'. strtolower(str_replace(' ', '-', $term->name));
			$items1[] = array('title' => $term->name, 'href' => $href);
		}
		$vars['device'] = '<label>'.t('Device').':</label> '. theme('links', $items1, array('class' => 'links inline'));
	}
	
	// Tags -- only show on full page
	$tags = $taxonomy[2];
	if ($tags && $vars['page']) {
		foreach ($tags as $key => $term) {
			$items1[] = array('title' => $term->name, 'href' => taxonomy_term_path($term));
		}
		$vars['tags'] = '<label>'.t('Tags').':</label> '. theme('links', $items1, array('class' => 'links inline'));
	}
	
	// Stick with node.tpl.php, not node-og-group-post
	$key = array_search('node-og-group-post', $vars['template_files']);
	if ($key !== FALSE) {
	  $vars['template_files'][$key] = NULL;
	}
	
	// Unpublished warning message to permissioned users
	if ($node->status == 0) {
		$vars['unpublished'] = t('Content unpublished for non-permissioned users. To publish, select the "edit" link, open the "Publishing Options" section, and select the "Publish" check box.');
	}
	
	// OG Private Posts Warning
	if (module_exists('og_access')) {
		if (og_is_group_post_type($node->type) && $node->og_public == FALSE) {
			$vars['private'] = t('Content is Private; only visible to members or admins of this group. To make public, select the "edit" link, open the "Groups" section, and select the "Public" check box.');
		}
	}
	
	// New, updated mark
	if ($node->changed) {
		$vars['mark'] = '<em>'.theme('mark', node_mark($node->nid, $node->changed)).'</em>';
	}
	
	// Splash Images
	if ($node->type == 'device' || $node->type == 'landing' || $node->type == 'sdk_group') {
		$vars['splash'] = '<div class="splash"></div>';
	}
	
}
// */

function meego_conference_preprocess_comment_wrapper(&$vars, $hook) {
	$node = $vars['node'];
	
	// New comments for a node and user
	if (comment_num_new($node->nid)) {
		$comments_new = comment_num_new($node->nid);
		$vars['comments_new'] = l($comments_new.t(' new'), "node/$node->nid", array('attributes' => array('title' => t('Jump to first new comment')), 'fragment' => 'new'));
	}
}

/**
 * Utility function to return an array of terms sorted by vocabulary
 */
function _meego_conference_sort_node_taxonomy($node) {
  $taxonomy = array();
  if (!empty($node->taxonomy)) {
    foreach($node->taxonomy as $key => $term) {
      if (!empty($term->vid)) {
        $taxonomy[$term->vid][] = $term;
      }
      // handle tags
      elseif (!empty($term)) {
        $taxonomy[$key][] = $term;
      }
    }
  }
  return $taxonomy;
}

/**
 * Override or insert PHPTemplate variables into the comment templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called ("comment" in this case.)
 */

function meego_conference_preprocess_comment(&$vars, $hook) {
  $vars['new'] = ' <span class="marker">'.theme('image', path_to_theme() .'/icons/new.png', t('new')).'</span>';
}


/**
 * Override or insert PHPTemplate variables into the block templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called ("block" in this case.)
 */
function meego_conference_preprocess_block(&$vars, $hook) {
	$block = $vars['block'];
	
  // Special classes for blocks.
  $vars['classes_array'][] = drupal_html_class('block-' . $block->subject);
}



/**
 * The rel="nofollow" attribute is missing from anonymous users' URL in Drupal 6.0-6.2.
 */
function meego_conference_username($object) {

  if ($object->uid && $object->name) {
		// If the user has a full name defined, use that
		$account = user_load(array(uid => $object->uid));
		$profilename = $object->name;
		if (!empty($account->profile_displayname)) {
			$profilename = $account->profile_displayname;
		}
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($profilename, 0, 15) . '...';
    }
    else {
      $name = $profilename;
    }

    if (user_access('access user profiles')) {
      $output = l($name, 'user/' . $object->uid, array('attributes' => array('title' => t('View user profile.'))));
    }
    else {
      $output = check_plain($name);
    }
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if (!empty($object->homepage)) {
      $output = l($object->name, $object->homepage, array('attributes' => array('rel' => 'nofollow')));
    }
    else {
      $output = check_plain($object->name);
    }

    $output .= ' (' . t('not verified') . ')';
  }
  else {
    $output = variable_get('anonymous', t('Anonymous'));
  }

  return $output;
}
// */

 
/** 
 * Custom Marker
 */
function meego_conference_mark($type = MARK_NEW) {
  global $user;
  if ($user->uid) {
    if ($type == MARK_NEW) {
      return ' <span class="marker">'.theme('image', path_to_theme() .'/icons/new.png', t('new')).'</span>';
    }
    else if ($type == MARK_UPDATED) {
      return ' <span class="marker">'.theme('image', path_to_theme() .'/icons/updated.png', t('updated')).'</span>';
    }
  }
}

/**
 * Custom RSS Icon
 */
function meego_conference_feed_icon($url, $title) {
  if ($image = theme('image', path_to_theme() .'/icons/feed_gray.png', t('Syndicate content'), $title)) {
    return '<a href="'. check_url($url) .'" class="feed-icon">'. $image .'</a>';
  }
}


/**
* Update user pic to use imagecache preset 'user_pic'
*/
function meego_conference_user_picture($account, $size = 'user_pics') {
  if (variable_get('user_pictures', 0)) {
    // Display the user's photo if available
    if ($account->picture && file_exists($account->picture)) {
      $picture = theme('imagecache', $size, $account->picture);
    }
		else {
			$picture = theme('image', path_to_theme() .'/images/user_picture_blank.png', '', '', NULL, TRUE);
		}
    return '<span class="picture">'.$picture.'</span>';
  }
}

/**
 * Theme form buttons to impliment sliding doors bg images
 */
function meego_conference_button($element) {
  // Make sure not to overwrite classes.
  if (isset($element['#attributes']['class'])) {
    $element['#attributes']['class'] = 'form-'. $element['#button_type'] .' '. $element['#attributes']['class'];
  }
  else {
    $element['#attributes']['class'] = 'form-'. $element['#button_type'];
  }

  return '<input type="submit" '. (empty($element['#name']) ? '' : 'name="'. $element['#name'] .'" ') .'id="'. $element['#id'] .'" value="'. check_plain($element['#value']) .'" '. drupal_attributes($element['#attributes']) ." />\n";
}

/**
 * Theme node form
 */
function meego_conference_node_form($form) {
  $output = "\n<div class=\"node-form\">\n";

  // Admin form fields and submit buttons must be rendered first, because
  // they need to go to the bottom of the form, and so should not be part of
  // the catch-all call to drupal_render().
  $admin = '';
  if (isset($form['author'])) {
    $admin .= "    <div class=\"authored\">\n";
    $admin .= drupal_render($form['author']);
    $admin .= "    </div>\n";
  }
  if (isset($form['options'])) {
    $admin .= "    <div class=\"options\">\n";
    $admin .= drupal_render($form['options']);
    $admin .= "    </div>\n";
  }
  $buttons = drupal_render($form['buttons']);

  // Everything else gets rendered here, and is displayed before the admin form
  // field and the submit buttons.
  $output .= "  <div class=\"standard\">\n";
  $output .= drupal_render($form);
  $output .= "  </div>\n";

  if (!empty($admin)) {
    $output .= "  <div class=\"admin\">\n";
    $output .= $admin;
    $output .= "  </div>\n";
  }
  $output .= $buttons;
  $output .= "</div>\n";

  return $output;
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function meego_conference_breadcrumb($breadcrumb) {
  // Determine if we are to display the breadcrumb.
  $show_breadcrumb = theme_get_setting('zen_breadcrumb');
  if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {

    // Optionally get rid of the homepage link.
    $show_breadcrumb_home = theme_get_setting('zen_breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }

    // Return the breadcrumb with separators.
    if (!empty($breadcrumb)) {
      $breadcrumb_separator = '<span class="separator">' . theme('image', path_to_theme() .'/icons/bullet_pink.png', '', '', NULL, TRUE) . '</span>';
      $trailing_separator = $title = '';
      if (theme_get_setting('zen_breadcrumb_title')) {
        if ($title = drupal_get_title()) {
          $trailing_separator = $breadcrumb_separator;
        }
      }
      elseif (theme_get_setting('zen_breadcrumb_trailing')) {
        $trailing_separator = $breadcrumb_separator;
      }
      return '<div class="breadcrumb">' . implode($breadcrumb_separator, $breadcrumb) . "$trailing_separator$title</div>";
    }
  }
  // Otherwise, return an empty string.
  return '';
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clear-block to tabs.
 */
function meego_conference_menu_local_tasks() {
  $output = '';

  if ($primary = menu_primary_local_tasks()) {
    $output .= '<ul class="tabs primary clearfix">' . $primary . '</ul>';
  }
  if ($secondary = menu_secondary_local_tasks()) {
    $output .= '<ul class="links secondary clearfix">' . $secondary . '</ul>';
  }

  return $output;
}

/**
* Generate the HTML representing a given menu item ID.
*
* An implementation of theme_menu_item_link()
*
*/
function meego_conference_menu_item_link($link) {
	if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }
	
	// If an item is a LOCAL TASK, render it as a tab
  if ($link['type'] & MENU_IS_LOCAL_TASK) {
    $link['title'] = '<span class="tab">' . check_plain($link['title']) . '</span>';
    $link['localized_options']['html'] = TRUE;
  }
	
	// Add destination link to login/register link
	if ($link['href'] == 'user/login') {
    $destination = drupal_get_destination();
		$link['localized_options']['query'] = $destination;
  }
	
  return l($link['title'], $link['href'], $link['localized_options']);
	
}

/**
 * Preprocessor for theme('views_view_fields').
 */
function meego_conference_preprocess_views_view_fields(&$vars) {
  foreach ($vars['fields'] as $field) {
    if ($class = _meego_conference_get_views_field_class($field->handler)) {
      $field->class = $class;
    }
  }

  // Write this as a row plugin to allow modules/features to define this stuff.
  if (get_class($vars['view']->style_plugin) == 'views_plugin_style_list') {
    $enable_grouping = TRUE;

    // Override arrays for grouping
    $view_id = "{$vars['view']->name}:{$vars['view']->current_display}";
    $overrides = array(
      "nodequeue_1:block" => array(
				'image' => array('field_hl_image_fid'),
	  ),
	  "nodequeue_2:block" => array(
				'meta' => array('tid', 'field_download_link_url'),
	  ),
      "nodequeue_3:attachment_1" => array(
				'meta' => array(''),
	  ),	
      "Releases:page_1" => array(
				'meta' => array('tid', 'field_download_link_url'),
	  ),
	  "Releases:page_2" => array(
				'meta' => array('tid', 'field_download_link_url'),
	  ),
	  "Releases:page_3" => array(
				'meta' => array('tid', ''),
	  ),	
      "projects:page_1" => array(
        'meta' => array('date', 'user-picture', 'username', 'author', 'title', 'tid'),
      ),
	  "Devices:block_3" => array(
        'meta' => array('tid'),
      ),
	  "planet_feeds:block_1" => array(
        'meta' => array(''),
      ),			
    );
    if (isset($overrides[$view_id])) {
      $groups = $overrides[$view_id];
    }
    else {
      $groups = array(
        'meta' => array('date', 'user-picture', 'username', 'related-title', 'author'),
        'admin' => array('edit', 'delete'),
      );
    }

    foreach ($vars['fields'] as $id => $field) {
      $found = FALSE;
      foreach ($groups as $group => $valid_fields) {
        if (in_array($field->class, $valid_fields)) {
          $grouped[$group][$id] = $field;
          $found = TRUE;
          break;
        }
      }
      if (!$found) {
        $grouped['content'][$id] = $field;
      }
    }

    // If the listing doesn't have any fields that will be grouped
    // fallback to default (non-grouped) formatting.
    $enable_grouping = count($grouped) <= 1 ? FALSE : TRUE;
    foreach (array_keys($grouped) as $group) {
      $vars['classes'] .= " grouping-{$group}";
    }
  }
  else {
    $enable_grouping = FALSE;
    $grouped = array('content' => $vars['fields']);
  }
  $vars['enable_grouping'] = $enable_grouping;
  $vars['grouped'] = $grouped;
}

/**
 * Preprocessor for theme('views_view_table').
 */
function meego_conference_preprocess_views_view_table(&$vars) {
  $view = $vars['view'];
  foreach ($view->field as $field => $handler) {
    if (isset($vars['fields'][$field]) && $class = _meego_conference_get_views_field_class($handler)) {
      $vars['fields'][$field] = $class;
    }
  }
}

/**
 * Helper function to get the appropriate class name for Views field.
 */
function _meego_conference_get_views_field_class($handler) {
  $handler_class = get_class($handler);
  $search = array(
    'project' => 'project',
    'priority' => 'priority',
    'status' => 'status',

    'date' => 'date',
    'timestamp' => 'date',

    'user_picture' => 'user-picture',
    'username' => 'username',
    'name' => 'username',

    'markup' => 'markup',
    'xss' => 'markup',

    'spaces_feature' => 'feature',
    'group_nids' => 'group',

    'numeric' => 'number',
    'count' => 'count',

    'edit' => 'edit',
    'delete' => 'delete',
  );
  foreach ($search as $needle => $class) {
    if (strpos($handler_class, $needle) !== FALSE) {
      return $class;
    }
  }
  // Fallback
  if (!empty($handler->relationship)) {
    return "related-{$handler->field}";
  }
  return $handler->field;
}
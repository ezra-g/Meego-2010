<?php

/**
* Return an array of the modules to be enabled when this profile is installed.
*
* @return
*  An array of modules to be enabled.
*/
function cod_profile_modules() {
  $modules = array();
  return array(
    // Enable required core modules first.
    'block', 'filter', 'node', 'system', 'user', 'dblog',
   
    // Enable optional core modules next.
    'comment', 'help', 'menu', 'taxonomy', 'profile',

    // Then, enable any contributed modules here.
    'content', 'content_permissions', 'fieldgroup', 'number', 'optionwidgets', 'text', 'date_api', 'date', 'views', 'views_ui', 'signup', 'uc_store', 'uc_product', 'uc_signup', 'flag', 'features', 'diff', 'cod_session', 'cod_events', 'cod_attendees', 'cod_front_page', 'cod_news', 'cod_sponsors', 'admin',
  );
}

/**
* Return a description of the profile for the initial installation screen.
*
* @return
*   An array with keys 'name' and 'description' describing this profile.
*/
function cod_profile_details() {
  return array(
    'name' => 'Conference Organizing Distribution',
    'description' => 'This software will help you organize a conference-style event.',
  );
}


/**
* Perform any final installation tasks for this profile.
*
* @return
*   An optional HTML string to display to the user on the final installation
*   screen.
*/
function cod_profile_final() {
}
$Id: README.txt,v 1.2.2.1 2010/07/11 02:41:41 itafroma Exp $

CONTENTS OF THIS FILE
---------------------

* Introduction
* Requirements
* Installation
* Acknowledgements
* Contact
* More Information

INTRODUCTION
------------

The Context: Menu Block module allows the Menu Block module to be aware of
contexts provided by the Context module. 

Specifically, it informs menu blocks of active menu context reactions.

For a full description of the module, visit the project page:
  http://drupal.org/project/context_menu_block

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/context_menu_block.

REQUIREMENTS
------------

- Drupal 6.x
- Menu Block (http://drupal.org/project/menu_block); tested with the 6.x-2.x 
  branch.
- Context (http://drupal.org/project/context). Tested with both the 6.x-2.x and
  the 6.x-3.x branches.

NOTE: Previously, there were two branches corresponding to each version of
Context. As of Context: Menu Block 6.x-3.0-beta2, these branches have been
merged and the Context: Menu Block 6.x-2.x branch has been discontinued. Please
use the Context: Menu Block 6.x-3.x branch for either version of Context.

For additional releases that may support other versions, visit the project page:
  http://drupal.org/project/context_menu_block

INSTALLATION
------------

Install as usual, see http://drupal.org/node/70151 for further information.

If your context reaction uses a second or higher level menu item, the menu block
for the menu must have "Expand all children of this tree" selected in its block 
configuration.

CONTACT
-------

Current maintainer:
- Mark Trapp (amorfati) - http://drupal.org/user/212019

ACKNOWLEDGEMENTS
----------------

This module is borne from Menu Block issue #751700, "Setting active with Context 
Module" (http://drupal.org/node/751700). It contains bug fixes and additional
customizations to provide Context 3 support.

Original authors:
- Luke Berg (nauthiz693) - http://drupal.org/user/728256
- Nik LePage (NikLP) - http://drupal.org/user/71221

MORE INFORMATION
----------------

- For additional documentation, see the online Drupal handbook at
  http://drupal.org/handbook.

- For a list of security announcements, see the "Security announcements" page
  at http://drupal.org/security (available as an RSS feed). This page also
  describes how to subscribe to these announcements via e-mail.

- For information about the Drupal security process, or to find out how to report
  a potential security issue to the Drupal security team, see the "Security team"
  page at http://drupal.org/security-team.

- For information about the wide range of available support options, see the
  "Support" page at http://drupal.org/support.
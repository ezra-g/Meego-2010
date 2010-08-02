/* $Id: compact_forms.js,v 1.1 2007/07/29 17:20:58 tomsun Exp $

    Compact Forms jQuery plugin
    Copyright 2007 Tom Sundstršm

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public
    License along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
$(document).ready(function() {
	$("#user-login-form").compactForm(1, 0);
	$("#search-theme-form").compactForm(1, 0);
	$('li.toggle_area').find('div.toggle_content').hide().end().find('div.toggle_label').click(function() {
      $(this).next().slideToggle();
    });
});

(function($){
  $.fn.compactForm = function(stars, colons) {
    var stars = stars || 0;
    var colons = colons || 0;
    this.each(function(index) {
      $(this).find("label").each(function() {
        var label = $(this);
        var field = $("#" + label.attr("for"));
        if (field.attr("type") != "text" && field.attr("type") != "password") {
          return;
        }

        if($(field).val() != "") {
            $(label).fadeOut(1);
        }

        $(label).parent().addClass("compact-form-wrapper");
        label.addClass("compact-form-label");
        field.addClass("compact-form-field");

        if (stars === 0) {
          $(label).find(".form-required").hide();
        } else if (stars === 2) {
          $(label).find(".form-required").insertAfter(field).prepend("&nbsp;");
        }

        if (colons === 0) {
          var lbl = $(label).html();
          lbl = lbl.replace(/:/," ");
          $(label).html(lbl);
        }

        $(field).focus(function() {
          if($(this).val() === "") {
            $(label).fadeOut("fast");
          }
        });

        $(field).blur(function() {
          if($(this).val() === "") {
            $(label).fadeIn("slow");
          }
        });
      });
    });
  }
})(jQuery);

Drupal.behaviors.meego = function (context) {
  $('div.fieldset:not(.tao-processed)').each(function() {
    $(this).addClass('tao-processed');
    if ($(this).is('.collapsible')) {
      if ($('input.error, textarea.error, select.error', this).size() > 0) {
        $(this).removeClass('collapsed');
      }
      // Note that .children() only returns the immediate ancestors rather than
      // recursing down all children.
      $(this).children('.fieldset-title').click(function() {
        if ($(this).parent().is('.collapsed')) {
          $(this).siblings('.fieldset-content').show();
          $(this).parent().removeClass('collapsed');
        }
        else {
          $(this).siblings('.fieldset-content').hide();
          $(this).parent().addClass('collapsed');
        }
        return false;
      });
    }
  });
}

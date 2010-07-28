/* $Id: maxlength.js,v 1.1.6.6 2008/09/29 00:14:48 acm Exp $ */

Drupal.maxLength_limit = function (field) {
  var limit = field.attr("limit");

  // calculate the remaining count of chars
  var remainingCnt = limit - field.val().length;

  // if there is not remaining char, we clear additional content
  if (remainingCnt < 0) {
    field.val(field.val().substr(0, limit));
    remainingCnt = 0;
  }

  // update the remaing chars text
  $('#maxlength-'+field.attr('id').substr(5) + ' span.maxlength-counter-remaining').html(remainingCnt.toString());
}

Drupal.maxLength_change = function () {
  var element = $(this);
  Drupal.maxLength_limit($(this), $(this).attr("limit"));
}

if (Drupal.jsEnabled) {
  $(document).ready(function(){
    // get all the settings, and save the limits in the fields
    for (var id in Drupal.settings.maxlength) {
      var limit = Drupal.settings.maxlength[id];
      var element = $("#"+ id);
      element.attr("limit", limit);
      // update the count at the page load
      Drupal.maxLength_limit(element);

      element.load(Drupal.maxLength_change);
      element.keyup(Drupal.maxLength_change);
      element.change(Drupal.maxLength_change);
    }
  });
}

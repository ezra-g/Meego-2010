// $Id: clock.js,v 1.9.2.8 2010/11/22 16:24:57 tstoeckler Exp $

/**
 * Gets the date format and time zone related parameters from PHP and formats the date according
 * to the php date formatters. Visit http://php.net/date for more information. Using jQuery Timers (http://plugins.jquery.com/project/timers) the
 * date is recalculated every second to make the clock dynamic.
 */
Drupal.behaviors.clockDisplay = function (context) {
  // Initialize the clock variable for later use.
  var clock = '';

  // Gets the correct variables from PHP.
  // Whether or not to update the clock continuously
  var update = Drupal.settings['update'];
  // Whether or not to use the client's local time.
  var local = Drupal.settings['local'];
  // Creates a JavaScript date object, from a specially formatted date string.
  var date = new Date(Drupal.settings['time']);
  // The time zone offset in seconds.
  var offsetSeconds = Drupal.settings['offset_seconds'];
  // The name of the timezone, e.g. 'Europe/London'.
  var timezoneName = Drupal.settings['timezone_name'];
  // If time zone is set to 'Local' overwrite the date.
  // Note that due to JavaScript's inferior time zone handling, time zone
  // related date formatters will return the time zone of the Drupal site, not
  // the visiting user.
  if (local) {
    date = new Date();
  }

  // Daylight Savings Time information. '1' for yes, '0' for no.
  var daylightSavingsTime = Drupal.settings['daylight_savings_time'];
  // The name of the offset, e.g. 'GMT'.
  var offsetName = Drupal.settings['offset_name'];
  // A PHP date format string.
  var dateFormat = Drupal.settings['date_format'];

  // Create an array containing month names.
  var monthNames = new Array();
  monthNames[1] = new Object();
  monthNames[1]['long'] = Drupal.t('January');
  monthNames[1]['short'] = Drupal.t('Jan');
  monthNames[2] = new Object();
  monthNames[2]['long'] = Drupal.t('February');
  monthNames[2]['short'] = Drupal.t('Feb');
  monthNames[3] = new Object();
  monthNames[3]['long'] = Drupal.t('March');
  monthNames[3]['short'] = Drupal.t('Mar');
  monthNames[4] = new Object();
  monthNames[4]['long'] = Drupal.t('April');
  monthNames[4]['short'] = Drupal.t('Apr');
  monthNames[5] = new Object();
  monthNames[5]['long'] = Drupal.t('May');
  monthNames[5]['short'] = Drupal.t('May');
  monthNames[6] = new Object();
  monthNames[6]['long'] = Drupal.t('June');
  monthNames[6]['short'] = Drupal.t('Jun');
  monthNames[7] = new Object();
  monthNames[7]['long'] = Drupal.t('July');
  monthNames[7]['short'] = Drupal.t('Jul');
  monthNames[8] = new Object();
  monthNames[8]['long'] = Drupal.t('August');
  monthNames[8]['short'] = Drupal.t('Aug');
  monthNames[9] = new Object();
  monthNames[9]['long'] = Drupal.t('September');
  monthNames[9]['short'] = Drupal.t('Sep');
  monthNames[10] = new Object();
  monthNames[10]['long'] = Drupal.t('October');
  monthNames[10]['short'] = Drupal.t('Oct');
  monthNames[11] = new Object();
  monthNames[11]['long'] = Drupal.t('November');
  monthNames[11]['short'] = Drupal.t('Nov');
  monthNames[12] = new Object();
  monthNames[12]['long'] = Drupal.t('December');
  monthNames[12]['short'] = Drupal.t('Dec');

  // Create an array containing weekday names.
  var weekdayNames = new Array();
  weekdayNames[0] = new Object();
  weekdayNames[0]['long'] = Drupal.t('Sunday');
  weekdayNames[0]['short'] = Drupal.t('Sun');
  weekdayNames[1] = new Object();
  weekdayNames[1]['long'] = Drupal.t('Monday');
  weekdayNames[1]['short'] = Drupal.t('Mon');
  weekdayNames[2] = new Object();
  weekdayNames[2]['long'] = Drupal.t('Tuesday');
  weekdayNames[2]['short'] = Drupal.t('Tue');
  weekdayNames[3] = new Object();
  weekdayNames[3]['long'] = Drupal.t('Wednesday');
  weekdayNames[3]['short'] = Drupal.t('Wed');
  weekdayNames[4] = new Object();
  weekdayNames[4]['long'] = Drupal.t('Thursday');
  weekdayNames[4]['short'] = Drupal.t('Thu');
  weekdayNames[5] = new Object();
  weekdayNames[5]['long'] = Drupal.t('Friday');
  weekdayNames[5]['short'] = Drupal.t('Fri');
  weekdayNames[6] = new Object();
  weekdayNames[6]['long'] = Drupal.t('Saturday');
  weekdayNames[6]['short'] = Drupal.t('Sat');

  // Prepare the timezone array.
  var timezone = new Array();
  timezone['name'] = timezoneName;
  timezone['offsetSeconds'] = offsetSeconds;
  timezone['daylightSavingsTime'] = daylightSavingsTime;
  timezone['offsetName'] = offsetName;

  // Format the clock.
  clock = formatDate(date, dateFormat, timezone, monthNames, weekdayNames);
  $('div.clock').html(clock);

  if (update == '1') {

    // Recalculate the date every second. '.everyTime' is provided by jQuery Timers.
    window.setInterval(function() {

      // Add 1 second to the time.
      var clockTimestamp = date.getTime();
      clockTimestamp = clockTimestamp + 1000;
      date = new Date(clockTimestamp);

      // Format the clock.
      clock = formatDate(date, dateFormat, timezone, monthNames, weekdayNames);
      $('div.clock').html(clock);
    }, 1000);

  }
}

/**
 * Hide the select boxes on the clock block configure screen if the specific options are disabled.
 */
Drupal.behaviors.clockConfigure = function (context) {
  // Show the custom time zone select list only when 'Custom time zone' is checked.
  $('div.edit-custom-timezone').addClass('js-hide');
  function customTimezoneSelect() {
    var value = $('div.edit-timezone input:checked').val();
    if (value == '4') {
      $('div.edit-custom-timezone').show();
    }
    else {
      $('div.edit-custom-timezone').hide();
    }
  }
  $('div.edit-timezone').bind('click', customTimezoneSelect);
  customTimezoneSelect();

  // Show the custom date format select list only when 'Custom date format' is checked.
  $('div.edit-custom-date-format').addClass('js-hide');
  function customDateFormatSelect() {
    var value = $('div.edit-date-format input:checked').val();
    if (value == 'custom') {
      $('div.edit-custom-date-format').show();
    }
    else {
      $('div.edit-custom-date-format').hide();
    }
  }
  $('div.edit-date-format').bind('click', customDateFormatSelect);
  customDateFormatSelect();
}

/**
 * Format a date into a PHP date string.
 *
 * @param date
 *   A date object.
 * @param dateFormat
 *   A string. See http://php.net/date for possible values.
 * @param timezone
 *   An associative array containing timezone information. It should consist of
 *   following keys:
 *   - timezoneName: The name of the timezone, e.g. 'Europe/London'.
 *   - offsetSeconds: The timezone offset in seconds.
 *   - offsetName: The name of the offset, e.g. 'UTC'.
 *   - daylightSavingsTime: Whether or not the time is in daylight savings time.
 *     '1' if yes, '0' if not.
 * @param monthNames
 *   An array of month names keyed by the numbers 1-12. Each value should in turn
 *   be an array keyed 'long' and 'short' for the long respective the short
 *   month names.
 * @param weekdayNames
 *   An array of weekday names keyed by the numbers 0 (for Sunday) - 6 (for
 *   Saturday). Each value should in turn be an array keyed by 'long' and
 *   'short' for the long respective the short weekday names.
 *
 * @return
 *   A formatted date string.
 */
function formatDate(date, dateFormat, timezone, monthNames, weekdayNames) {
  var timezoneName = timezone['name'];
  var offsetSeconds = timezone['offsetSeconds'];
  var offsetName = timezone['offsetName'];
  var daylightSavingsTime = timezone['daylightSavingsTime'];

  // Initialize the 'formattedDate' variable for later use.
  var formattedDate = '';

  // Prepare variables for the format conversion.

  // Year-related.
  var year = date.getFullYear();
  var yearShort = year % 100;
  // Calculate whether it is a leap year or not. Years that are multiples of 4
  // are leap years, while multiples of 100 are not, but multiples of 400 are.
  var year = date.getFullYear();
  if (((year % 4) == 0) && ((year % 100) != 0) || ((year % 400) == 0)) {
    var leapYear = '1';
  }
  else {
    var leapYear = '0';
  }

  // Month-related.
  var month = date.getMonth();
  // JavaScript starts counting the months with 0 instead of 1.
  month++;
  var monthLeadingZero = ((month < 10) ? '0' + month : month);
  var monthLongName = monthNames[month]['long'];
  var monthShortName = monthNames[month]['short'];
  var day = date.getDate();
  var dayLeadingZero = ((day < 10) ? '0' + day : day);
  switch (day) {
    case 1:
    case 21:
    case 31:
      var dayOfMonthAppend = Drupal.t('st');
      break;
    case 2:
    case 22:
      var dayOfMonthAppend = Drupal.t('nd');
      break;
    case 3:
    case 23:
      var dayOfMonthAppend = Drupal.t('rd');
      break;
    default:
      var dayOfMonthAppend = Drupal.t('th');
      break;
  }
  // Create an array containing month names and lengths.
  var months = new Array();
  months[1] = 31;
  months[2] = ((leapYear == 1) ? 29 : 28);
  months[3] = 31;
  months[4] = 30;
  months[5] = 31;
  months[6] = 30;
  months[7] = 31;
  months[8] = 31;
  months[9] = 30;
  months[10] = 31;
  months[11] = 30;
  months[12] = 31;
  // To calculate the days of the year, iterate through all passed months and then add the current days of the month.
  var daysOfYear = 0;
  for (var m = 1; m < month; m++) {
    daysOfYear += months[m];
  }
  daysOfYear += day;

  // Week-related.
  var weekday = date.getDay();
  if (weekday == 0) {
    var weekNumber = Math.floor((daysOfYear - 7) / 7) + 1;
  }
  else {
    var weekNumber = Math.floor((daysOfYear - weekday) / 7) + 1;
  }
  var weekNumberLeadingZero = ((weekNumber < 10) ? '0' + weekNumber : weekNumber);
  var weekdayLongName = weekdayNames[weekday]['long'];
  var weekdayShortName = weekdayNames[weekday]['short'];

  // Offset-related.
  if (offsetSeconds < 0) {
    var offsetPrefix = '-';
    var offsetHours = Math.floor(parseInt(offsetSeconds.substr(1)) / 3600);
    var offsetHoursLeadingZero = ((offsetHours < 10) ? '0' + offsetHours : offsetHours);
    var offsetMinutes = (parseInt(offsetSeconds.substr(1)) / 60) % 60;
    var offsetMinutesLeadingZero = ((offsetMinutes < 10) ? '0' + offsetMinutes : offsetMinutes);
  }
  else {
    var offsetPrefix = '+';
    var offsetHours = Math.floor(offsetSeconds) / 3600;
    var offsetHoursLeadingZero = ((offsetHours < 10) ? '0' + offsetHours : offsetHours);
    var offsetMinutes = (offsetSeconds / 60) % 60;
    var offsetMinutesLeadingZero = ((offsetMinutes < 10) ? '0' + offsetMinutes : offsetMinutes);
  }

  // Hour-related.
  var hours = date.getHours();
  var hoursLeadingZero = ((hours < 10) ? '0' + hours : hours);
  if (hours == 0) {
    var hoursTwelve = (hours + 12);
  }
  else if (hours > 12) {
    var hoursTwelve = (hours - 12);
  }
  else {
    var hoursTwelve = hours;
  }
  var hoursTwelveLeadingZero = ((hoursTwelve < 10) ? '0' + hoursTwelve : hoursTwelve);

  // Minute-related.
  var minutes = date.getMinutes();
  var minutesLeadingZero = ((minutes < 10) ? '0' + minutes : minutes);

  // Second-related.
  var seconds = date.getSeconds();
  var secondsLeadingZero = ((seconds < 10) ? '0' + seconds : seconds);
  var beats = Math.floor(((hours * 3600) + (minutes * 60) + seconds - parseInt(offsetSeconds) + 3600) / 86400 * 1000);
  if (beats < 10) {
    var beatsLeadingZero = ((beats < 10) ? '00' + beats : beats);
  }
  else if (beats < 100) {
    var beatsLeadingZero = ((beats < 100) ? '0' + beats : beats);
  }
  else {
    var beatsLeadingZero = beats;
  }
  var timestamp = date.getTime();

  // Turn the date format string into an array so each character has its own key.
  var dateFormat = dateFormat.split('');

  // Perform the date format conversion for a character.
  for (i=0; i < dateFormat.length; i++) {
    switch (dateFormat[i]) {
      // If the escape character '\' is used, simply return the following character.
      case '\\':
        formattedDate += dateFormat[++i];
        break;
      // 'am' or 'pm' depending on the time of day.
      case 'a':
        formattedDate += ((hours >= 12) ? Drupal.t('pm') : Drupal.t('am'));
        break;
      // 'AM' or 'PM' depending on the time of day.
      case 'A':
        formattedDate += ((hours >= 12) ? Drupal.t('PM') : Drupal.t('AM'));
        break;
      // Swatch-Internet-Time.
      case 'B':
        formattedDate += beatsLeadingZero;
        break;
      // ISO-8601 date.
      case 'c':
        formattedDate += year + '-' + monthLeadingZero + '-' + dayLeadingZero + 'T' + hoursLeadingZero + ':' + minutesLeadingZero + ':' + secondsLeadingZero + offsetPrefix + offsetHoursLeadingZero + ':' + offsetMinutesLeadingZero;
        break;
      // Day of month with leading zero, '01' - '31'.
      case 'd':
        formattedDate += dayLeadingZero;
        break;
      // Short name of weekday, e.g. 'Sun'.
      case 'D':
        formattedDate += weekdayShortName;
        break;
      // Time zone name, e.g. 'Europe/London';
      case 'e':
        formattedDate += timezoneName;
        break;
      // Name of month, e.g. 'January'.
      case 'F':
        formattedDate += monthLongName;
        break;
      // Hours in 12-hour format, '1' - '12'.
      case 'g':
        formattedDate += hoursTwelve;
        break;
      // Hours in 24-hour format, '0' - '23'.
      case 'G':
        formattedDate += hours;
        break;
      // Hours in 12-hour format with leading zero, '01' - '12'.
      case 'h':
        formattedDate += hoursTwelveLeadingZero;
        break;
      // Hours in 24-hour format with leading zero, '00' - '23'.
      case 'H':
        formattedDate += hoursLeadingZero;
        break;
      // Minutes with leading zero, '00' - '59'.
      case 'i':
        formattedDate += minutesLeadingZero;
        break;
      // Daylight Savings Time, '1' or '0'
      case 'I':
        formattedDate += daylightSavingsTime;
        break;
      // Day of month, '1' - '31'
      case 'j':
        formattedDate += day;
        break;
      // Name of weekday, e.g. 'Sunday'.
      case 'l':
        formattedDate += weekdayLongName;
        break;
      // Leap year, '1' or '0'.
      case 'L':
        formattedDate += leapYear;
        break;
      // Number of month with leading zero, '01' - '12'
      case 'm':
        formattedDate += monthLeadingZero;
        break;
      // Short name of month, e.g. 'Jan'.
      case 'M':
        formattedDate += monthShortName;
        break;
      // Number of month, '1' - '12'.
      case 'n':
        formattedDate += month;
        break;
      // ISO-8601 weekday number, '1' - '7'.
      case 'N':
        formattedDate += weekday + 1;
        break;
      // ISO-8601 year number.
      // This has a different value from 'Y' in certain constellations at the
      // beginning or end of a year, but this is not implemented here.
      case 'o':
        formattedDate += year;
        break;
      // Time zone offset, e.g. '+1030'
      case 'O':
        formattedDate += offsetPrefix + offsetHoursLeadingZero + offsetMinutesLeadingZero;
        break;
      // Time zone offset, e.g. '+10:30'.
      case 'P':
        formattedDate += offsetPrefix + offsetHoursLeadingZero + ':' + offsetMinutesLeadingZero;
        break;
      // RFC-2822 date.
      case 'r':
        formattedDate += weekdayShortName + ', ' + dayLeadingZero + ' ' + monthShortName + ' ' + year + ' ' + hoursLeadingZero + ':' + minutesLeadingZero + ':' + secondsLeadingZero + ' ' + offsetPrefix + offsetHoursLeadingZero + offsetMinutesLeadingZero;
        break;
      // Seconds with leading zero.
      case 's':
        formattedDate += secondsLeadingZero;
        break;
      // Appendage for the day of month, e.g. 'st' if the day is '1'.
      case 'S':
        formattedDate += dayOfMonthAppend;
        break;
      // Total days of month, '28' - '31'.
      case 't':
        formattedDate += months[month];
        break;
      // Name of offset, e.g. 'GMT'.
      case 'T':
        formattedDate += offsetName;
        break;
      // Milliseconds since the begin of the UNIX-era.
      case 'u':
        formattedDate += timestamp;
        break;
      // Seconds since the begin of the UNIX-era.
      case 'U':
        formattedDate += timestamp / 1000;
        break;
      // Number of weekday, '0' for Sunday, ..., '6' for Saturday.
      case 'w':
        formattedDate += weekday;
        break;
      // ISO-8601 week number, '01' - '52'.
      case 'W':
        formattedDate += weekNumberLeadingZero;
        break;
      // Year, e.g. '2001'.
      case 'Y':
        formattedDate += year;
        break;
      // Short year, e.g. '01'.
      case 'y':
        formattedDate += yearShort;
        break;
      // Days of the year, '0' - '365'.
      // Since PHP starts counting the days of the year at '0', we need subtract one.
      case 'z':
        formattedDate += daysOfYear - 1;
        break;
      // Time zone offset in seconds.
      case 'Z':
        formattedDate += offsetSeconds;
        break;
      // If the character is not a date formatter, just add it to the output.
      default:
        formattedDate += dateFormat[i];
        break;
    }
  }
  return formattedDate;
}


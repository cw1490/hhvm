<?php
ini_set("intl.error_level", E_WARNING);
ini_set("intl.default_locale", "nl");

date_default_timezone_set('Europe/Amsterdam');

$intlcal = new IntlGregorianCalendar();

var_dump($intlcal->getGregorianChange());

var_dump($intlcal->setGregorianChange(0));
var_dump(intlgregcal_get_gregorian_change($intlcal));

var_dump(intlgregcal_set_gregorian_change($intlcal, 1));
var_dump($intlcal->getGregorianChange());

?>
==DONE==

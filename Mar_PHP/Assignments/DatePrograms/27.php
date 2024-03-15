<?php

$currentMonth = date('m');
$currentYear = date('Y');


$numberOfDays = cal_days_in_month(CAL_GREGORIAN, $currentMonth, $currentYear);

echo "Number of days in the current month: $numberOfDays";
?>

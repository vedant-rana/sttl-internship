<?php
function daysBetweenDates($date1, $date2) {
    $datetime1 = new DateTime($date1);
    $datetime2 = new DateTime($date2);
    $interval = $datetime1->diff($datetime2);
    return $interval->days;
}


$date1 = "2023-01-01";
$date2 = "2023-12-31";
echo "Number of days between $date1 and $date2 is: " . daysBetweenDates($date1, $date2) . " days";
?>

<?php
function weeksBetweenDates($start_date, $end_date) {
    $start = new DateTime($start_date);
    $end = new DateTime($end_date);
    $interval = $end->diff($start);
    $weeks = floor($interval->days / 7);
    return $weeks;
}


$start_date = '08-01-2024';
$end_date = '11-03-2024';


$weeks = weeksBetweenDates($start_date, $end_date);


echo "Weeks between $start_date and $end_date is $weeks";
?>

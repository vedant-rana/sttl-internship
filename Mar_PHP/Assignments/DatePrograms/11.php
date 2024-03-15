<?php
function getTimeDifference($start_date, $end_date) {
    $start_datetime = new DateTime($start_date);
    $end_datetime = new DateTime($end_date);
    
    $interval = $start_datetime->diff($end_datetime);
    
    $days = $interval->days;
    $years = $interval->y;
    $months = $interval->m;
    $hours = $interval->h;
    $minutes = $interval->i;
    $seconds = $interval->s;
    
    return array(
        'days' => $days,
        'years' => $years,
        'months' => $months,
        'hours' => $hours,
        'minutes' => $minutes,
        'seconds' => $seconds
    );
}


$start_date = "1981-11-04 10:30:00";
$end_date = "2013-09-04 15:45:00";
$time_difference = getTimeDifference($start_date, $end_date);

echo "Time difference between $start_date and $end_date =><br>";
echo "Years: " . $time_difference['years'] . "<br>";
echo "Months: " . $time_difference['months'] . "<br>";
echo "Days: " . $time_difference['days'] . "<br>";
echo "Hours: " . $time_difference['hours'] . "<br>";
echo "Minutes: " . $time_difference['minutes'] . "<br>";
echo "Seconds: " . $time_difference['seconds'] . "<br>";
?>

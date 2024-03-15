<?php
function getWeekDates($week, $year) {
    $dto = new DateTime();
    $dto->setISODate($year, $week);
    $startDate = $dto->format('Y-m-d');
    $dto->modify('+6 days');
    $endDate = $dto->format('Y-m-d');
    return array('Starting date of the week' => $startDate, 'End date the week' => $endDate);
}


$week = 10;
$year = 2024;


$weekDates = getWeekDates($week, $year);


echo "Starting date of the week: {$weekDates['Starting date of the week']}<br>";
echo "End date the week: {$weekDates['End date the week']}";
?>
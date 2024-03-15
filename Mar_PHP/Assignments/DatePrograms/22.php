<?php

$currentMonth = date('m');
$currentYear = date('Y');


$lastSixMonths = array();


for ($i = 6; $i > 0; $i--) {
    
    $month = date('m', strtotime("-$i months"));
    $year = date('Y', strtotime("-$i months"));
    
    
    $lastSixMonths[] = array('month' => $month, 'year' => $year);
}


echo "Last 6 months from the current month:<br>";
foreach ($lastSixMonths as $month) {
    echo date('F Y', mktime(0, 0, 0, $month['month'], 1, $month['year'])) . "<br>";
}
?>

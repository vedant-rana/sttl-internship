<?php

$currentMonth = date('m');
$currentYear = date('Y');


$previousThreeMonths = array();


for ($i = 0; $i < 4; $i++) {
    
    $month = date('m', strtotime("-$i months"));
    $year = date('Y', strtotime("-$i months"));
    
    
    $previousThreeMonths[] = array('month' => $month, 'year' => $year);
}


echo "Current Month and Previous Three Months:<br>";
foreach ($previousThreeMonths as $month) {
    echo date('F Y', mktime(0, 0, 0, $month['month'], 1, $month['year'])) . "<br>";
}
?>

<?php
function modifyDate($date, $days) {
    
    $dateTime = new DateTime($date);
    
    
    $dateTime->modify("$days days");
    
    
    return $dateTime->format('Y-m-d');
}


$originalDate = "2024-03-07";
$daysToAdd = 40;


$dateBefore = modifyDate($originalDate, "-$daysToAdd");
$dateAfter = modifyDate($originalDate, "+$daysToAdd");


echo "Original date: $originalDate<br>";
echo "Before $daysToAdd days: $dateBefore<br>";
echo "After $daysToAdd days: $dateAfter";
?>

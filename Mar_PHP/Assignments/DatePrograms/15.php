<?php
function isWeekend($date) {
    
    $dateTime = new DateTime($date);
    
    
    $dayOfWeek = $dateTime->format('w');
    
    
    return $dayOfWeek == 0 || $dayOfWeek == 6;
}


$date = "2024-03-06"; 
if (isWeekend($date)) {
    echo "$date is a weekend.";
} else {
    echo "$date is not a weekend.";
}
?>

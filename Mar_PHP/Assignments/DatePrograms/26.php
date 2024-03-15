<?php

function monthNumberToName($monthNumber) {
    
    $date = mktime(0, 0, 0, $monthNumber, 1);

    
    $monthName = date("F", $date);

    return $monthName;
}


$monthNumber = 4; 
$monthName = monthNumberToName($monthNumber);
echo "Month number $monthNumber corresponds to $monthName.";
?>

<?php
function getOrdinalSuffix($num) {
    if (!in_array(($num % 100), array(11,12,13))){
        switch ($num % 10) {
            
            case 1: return 'st';
            case 2: return 'nd';
            case 3: return 'rd';
        }
    }
    return 'th';
}

$date = "2024-03-11"; 
$dayOfWeek = date("l", strtotime($date)); 
$dayOfMonth = date("j", strtotime($date)); 
$ordinalSuffix = getOrdinalSuffix($dayOfMonth);

echo "$dayOfWeek the {$dayOfMonth}{$ordinalSuffix}.\n";
?>

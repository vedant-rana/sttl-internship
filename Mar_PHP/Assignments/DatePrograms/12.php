<?php
function getMonthName($month_number) {
    $month_name = date("F", strtotime("2024-$month_number-01"));
    return $month_name;
}


$month_number = 5; 
echo "Month number $month_number corresponds to: " . getMonthName($month_number); 
?>

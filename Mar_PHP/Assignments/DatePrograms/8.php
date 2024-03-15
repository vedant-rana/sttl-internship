<?php

$date = "2024-02-15"; 


$firstDayOfMonth = date("Y-m-01", strtotime($date));


$lastDayOfMonth = date("Y-m-t", strtotime($date));

echo "First day of the month: " . $firstDayOfMonth . "<br>";
echo "Last day of the month: " . $lastDayOfMonth . "<br>";
?>

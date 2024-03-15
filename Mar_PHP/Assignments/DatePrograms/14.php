<?php

$current_time = new DateTime('now', new DateTimeZone('Australia/Melbourne'));


$current_time_formatted = $current_time->format('Y-m-d H:i:s');


echo "Current date/time in Australia/Melbourne: " . $current_time_formatted;
?>

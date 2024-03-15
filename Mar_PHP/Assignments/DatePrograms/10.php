<?php
function isValidDate($date) {
    $dateParts = explode('-', $date);
    if (count($dateParts) != 3) {
        return false; 
    }
    $year = (int)$dateParts[0];
    $month = (int)$dateParts[1];
    $day = (int)$dateParts[2];
    
    return checkdate($month, $day, $year);
}


$dates = array("2023-02-28", "2023-04-31", "2023-06-31", "2023-09-30", "2023-11-31", "2023-02-31");

foreach ($dates as $date) {
    if (isValidDate($date)) {
        echo "$date is a valid date.<br>";
    } else {
        echo "$date is not a valid date.<br>";
    }
}
?>

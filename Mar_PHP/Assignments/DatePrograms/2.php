<?php

$birthday = "03-25"; 


$currentYear = date("Y");
$nextYear = $currentYear + 1;


$thisYearsBirthday = $currentYear . "-" . $birthday;
$nextYearsBirthday = $nextYear . "-" . $birthday;


$today = date("Y-m-d");


if ($today > $thisYearsBirthday) {
    
    $nextBirthday = date_create($nextYearsBirthday);
} else {
    
    $nextBirthday = date_create($thisYearsBirthday);
}


$now = date_create(date("Y-m-d"));


$diff = date_diff($now, $nextBirthday);


echo "Days until next birthday: " . $diff->format("%a days");
?>

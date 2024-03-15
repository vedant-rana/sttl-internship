<?php

$date1 = new DateTime("1981-11-04");
$date2 = new DateTime("2013-09-04");


$difference = $date1->diff($date2);


echo "Difference : " . $difference->y . " years, " . $difference->m . " months, " . $difference->d . " days";
?>

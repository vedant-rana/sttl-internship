<?php

$originalDate = "2012-09-12";


$date = DateTime::createFromFormat('Y-m-d', $originalDate);


$formattedDate = $date->format('d-m-Y');


echo $formattedDate;
?>

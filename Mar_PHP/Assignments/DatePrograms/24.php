<?php

$sampleDate = "2012-12-21";


$newDate = date('Y-m-d', strtotime($sampleDate . ' +1 month'));


echo "Original Date: $sampleDate<br>";
echo "Expected Output: $newDate";
?>

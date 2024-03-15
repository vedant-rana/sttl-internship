<?php
    $inputDateString = '12-08-2004';

    $dateTimeObject = DateTime::createFromFormat('d-m-Y', $inputDateString);

    $outputDateString = $dateTimeObject->format('Y-d-m');

    echo "Input Date: " . $inputDateString . "<br>";
    echo "Output Date: " . $outputDateString;
?>
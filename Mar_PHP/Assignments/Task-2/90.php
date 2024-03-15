<?php

function rotateArrayLeft($arr) {
    
    if (count($arr) !== 4) {
        return "Array must contain exactly 4 integers.";
    }

    
    $firstElement = array_shift($arr);

    
    $arr[] = $firstElement;

    return $arr;
}


$inputArray = [10, 20, -30, -40];


$rotatedArray = rotateArrayLeft($inputArray);


echo "Rotated array: " . implode(",", $rotatedArray) ;
?>

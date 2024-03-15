<?php

function reverseArray($arr)
{

    if (count($arr) !== 5) {
        return "Array must contain exactly 5 integers.";
    }


    $reversedArray = array_reverse($arr);

    return $reversedArray;
}


$inputArray = [10, 20, -30, -40, 50];


$reversedArray = reverseArray($inputArray);


echo "Reverse array: " . implode(",", $reversedArray);

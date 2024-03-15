<?php

function getMiddleElements($arr)
{

    if (count($arr) % 2 !== 0) {
        return "The array must have an even number of elements.";
    }


    $middleIndex = count($arr) / 2;


    $middleElements = array_slice($arr, $middleIndex - 1, 2);

    return $middleElements;
}


$inputArray = [1, 5, 7, 9, 11, 13];


$newArray = getMiddleElements($inputArray);


echo "New array: " . implode(" ", $newArray) . PHP_EOL;

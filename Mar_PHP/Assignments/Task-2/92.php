<?php

function replaceWithMaxOfFirstOrLast($arr)
{

    if (count($arr) !== 4) {
        return "Array must contain exactly 4 integers.";
    }

    $maxElement = max($arr[0], $arr[3]);

    $newArray = array_fill(0, 4, $maxElement);

    return $newArray;
}


$inputArray = [10, 20, -30, -40];


$newArrayWithMaxValues = replaceWithMaxOfFirstOrLast($inputArray);


echo "New array with maximum values: " . implode(",", $newArrayWithMaxValues) ;
?>
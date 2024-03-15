<?php

function findArrayWithMaxSum($arr1, $arr2)
{
    $sumArr1 = array_sum($arr1);
    $sumArr2 = array_sum($arr2);

    return $sumArr1 > $sumArr2 ? $arr1 : $arr2;
}

$array1 = [10, 20, -30];
$array2 = [10, 20, 30];


$newArrayWithMaxSum = findArrayWithMaxSum($array1, $array2);


echo "ans: " . implode(",", $newArrayWithMaxSum);

<?php

function newArray($arrs)
{
    $arr = [];
    $arr[0] = $arrs[0][count($arrs[0])/2];
    $arr[1] = $arrs[1][count($arrs[1])/2];

    return $arr;
}


$inputArray = [
    [10, 20, -30, -40, 30 ],
    [10, 20, 30, 40, 30 ]
];


echo "ans : " . implode(",", newArray($inputArray)) ;
?>
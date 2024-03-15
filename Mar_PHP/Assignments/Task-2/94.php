<?php

function newArray($arrs)
{
    $arr = [];
    $arr[0] = $arrs[0];
    $arr[1] = $arrs[count($arrs)-1];
    return $arr;
}


$inputArray = [10, 20, -30, -40, 30 ];


echo "ans : " . implode(",", newArray($inputArray)) ;
?>
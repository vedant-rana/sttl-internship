<?php

function replace5FollowedBy7($arr)
{

    if (count($arr) !== 3) {
        return "Array must contain exactly 3 integers.";
    }


    for ($i = 0; $i < 2; $i++) {
        if ($arr[$i] == 5 && $arr[$i + 1] == 7) {
            $arr[$i + 1] = 1;
            break;
        }
    }

    return $arr;
}


$inputArray = [1, 5, 7];


$newArray = replace5FollowedBy7($inputArray);


echo "ans :  " . implode(",", $newArray);

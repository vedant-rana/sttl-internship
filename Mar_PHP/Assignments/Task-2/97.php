<?php

function containsDouble10or20($arr)
{

    $length = count($arr);
   
    if ($length == 2 && (($arr[0] == 10 && $arr[1] == 10) || ($arr[0] == 20 && $arr[1] == 20))) {
        return true;
    }

    return false;
}


$inputs = [
    [12, 20],
    [20, 20],
    [10, 10],
    [10]
];



foreach ($inputs as $input) {
    var_dump(containsDouble10or20($input));
    echo "<br/>";
}
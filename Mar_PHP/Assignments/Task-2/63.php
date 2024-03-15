<?php

function createNewString($input)
{

    if (strlen($input) < 2) {
        return $input;
    }


    $half = substr($input, 0, strlen($input)/2);

    return $half;
}


$inputs = [
    "Hello",
    "Hi"
];


foreach ($inputs as $input) {
    echo createNewString($input) ."<br>";
}

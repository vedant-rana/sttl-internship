<?php

function createNewString($input)
{

    if (strlen($input) < 2) {
        return "Input string must be of length at least two.";
    }


    $lastTwo = substr($input, -2);


    $newString = $lastTwo . $lastTwo . $lastTwo."<br>";

    return $newString;
}


$inputs = [
    "Hello",
    "Hi"
];


foreach ($inputs as $input) {
    echo createNewString($input);
}

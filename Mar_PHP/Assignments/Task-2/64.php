<?php

function createNewString($input)
{

    if (strlen($input) <= 2) {
        return "";
    }


    $newString = substr($input, 1, strlen($input) - 2);

    return $newString;
}


$inputs = [
    "Hello",
    "Hi",
    "Python"

];


foreach ($inputs as $input) {
    echo createNewString($input) . "<br>";
}

<?php

function createNewString($input)
{

    if (strlen($input) < 2) {
        return $input;
    }


    $firstTwo = substr($input, 0, 2);

    return $firstTwo;
}


$inputs = [
    "Hello",
    "Hi",
    "H",
    " "
];


foreach ($inputs as $input) {
    echo createNewString($input) ."<br>";
}

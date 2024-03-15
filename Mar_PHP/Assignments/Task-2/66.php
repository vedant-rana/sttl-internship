<?php

function createNewString($input)
{
    return substr($input[0], 1).substr($input[1], 1);
}


$inputs = [
   ["Hello", "Hi"],
   ["JS", "Python"]
];


foreach ($inputs as $input) {
    echo createNewString($input) . "<br>";
}

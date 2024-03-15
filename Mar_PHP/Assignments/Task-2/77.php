<?php

function stringOfN($input)
{
    if(substr($input[0], -1) == substr($input[1], 0, 1)){
        return $input[0].substr($input[1], 1);
    }
    return $input[0].$input[1];
}


$inputs = [
    ["abc", "cat"],
    ["pyhton", "php"],
    ["php", "php"]

];


foreach ($inputs as $input) {

    echo stringOfN($input) . "<br/>";
}

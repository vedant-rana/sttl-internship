<?php

function stringOfN($input)
{

    return substr($input[0], 0, $input[1]).substr($input[0], -$input[1]);
}


$inputs = [
    ["Hello", 1],
    ["Python", 2],
    ["on",1],
    ["o",1]
];


foreach ($inputs as $input) {
    
    echo stringOfN($input)."<br/>";
}

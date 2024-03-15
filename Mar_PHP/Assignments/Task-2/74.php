<?php

function stringOfN($input)
{
    $len  = strlen($input)/2;
    if(strlen($input) % 2 == 0){
        return substr($input, $len -2, 3);
    }
    return substr($input, $len -1, 3);
}


$inputs = [
    "Hello",
    "Python",
    "abc"
];


foreach ($inputs as $input) {
    
    echo stringOfN($input)."<br/>";
}

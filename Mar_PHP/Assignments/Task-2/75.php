<?php

function stringOfN($input)
{
    
    if(strlen($input) < 2){
        return $input."#";
    }
    return substr($input, 0,2);
}


$inputs = [
    "Hello",
    "Python",
    "a",
    ""
];


foreach ($inputs as $input) {
    
    echo stringOfN($input)."<br/>";
}

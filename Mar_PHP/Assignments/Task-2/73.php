<?php

function stringOfN($input)
{
    if(strlen($input[0])<=2){
        return $input[0];
    }
    return substr($input[0],$input[1], 2);
}


$inputs = [
    ["Hello", 1],
    ["Python", 2],
    ["on",1]
];


foreach ($inputs as $input) {
    
    echo stringOfN($input)."<br/>";
}

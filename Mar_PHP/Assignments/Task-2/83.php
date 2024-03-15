<?php

function newStr($input)
{
    
    if(substr($input, 0,2) == substr($input, -2)){
        return substr($input, 2);
    }else{
        return $input;
    }
}


$inputs = [
    "abcab",
    "Python"
];


foreach ($inputs as $input) {

    echo "output :   ".newStr($input) . "<br/>";
}

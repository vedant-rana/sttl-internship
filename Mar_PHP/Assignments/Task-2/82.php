<?php

function newStr($input)
{

    $len = strlen($input);
    
    if($len < 2){
        return $input.$input.$input;
    }else{
        $temp = substr($input,0,2);
        return $temp.$temp.$temp;
    }
}


$inputs = [
    "abc",
    "Python",
    "J"

];


foreach ($inputs as $input) {

    echo "output :   ".newStr($input) . "<br/>";
}

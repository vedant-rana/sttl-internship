<?php

function swapLast2($input)
{
    
    $len = strlen($input);

    if($len<2){
        return $input;
    }
    $temp = $input[$len - 1];
    $input[$len - 1] = $input[$len - 2];
    $input[$len - 2] = $temp;

    return $input;
}


$inputs = [
    "Hello",
    "Python",
    "PHP",
    "JS",
    "C"

];


foreach ($inputs as $input) {

    echo swapLast2($input) . "<br/>";
}

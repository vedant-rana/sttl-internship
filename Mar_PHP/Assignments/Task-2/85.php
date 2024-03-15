<?php

function newStr($input)
{
    if($input[0] == 'a'){
        if($input[1] == 'a'){
            return substr($input, 2);
        }else{
            return substr($input, 1);
        }
    }
    return  $input;
}


$inputs = [
    "abcab",
    "Python",
    "aacda",
    "jython"
];


foreach ($inputs as $input) {

    echo "output :   " . newStr($input) . "<br/>";
}

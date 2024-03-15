<?php

function createNewString($input)
{
    if(strlen($input)<2){
        return "";
    }
    return substr($input, 1, strlen($input)-2);
}


$inputs = [
   "Hello",
   "JS",
   ""
];


foreach ($inputs as $input) {
    echo "output :  ".createNewString($input) . "<br>";
}

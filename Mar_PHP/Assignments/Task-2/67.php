<?php

function createNewString($input)
{
    if(strlen($input)<3){
        return $input;
    }
    return substr($input, 2).substr($input, 0,2);
}


$inputs = [
   "Hello",
   "JS"
];


foreach ($inputs as $input) {
    echo createNewString($input) . "<br>";
}

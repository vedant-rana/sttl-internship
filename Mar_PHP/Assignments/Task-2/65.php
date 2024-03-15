<?php

function createNewString($input)
{

    if(strlen($input[0]) > strlen($input[1])){
        return $input[0].$input[1].$input[0];
    }else{
        return $input[1].$input[0].$input[1];
    }

}


$inputs = [
   ["Hello", "Hi"],
   ["JS", "Python"]
];


foreach ($inputs as $input) {
    echo createNewString($input) . "<br>";
}

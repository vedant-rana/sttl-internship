<?php

function createNewString($input)
{
    $len = strlen(trim($input))/2;
    if(strlen($input)<3){
        return $input;
    }
    return substr($input, $len- 1, 2 );
}


$inputs = [
   "Hell",
   "JS",
   "abcdefgh"
];


foreach ($inputs as $input) {
    echo "output :  ".createNewString($input) . "<br>";
}

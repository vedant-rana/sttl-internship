<?php

function insertMiddle($string, $insertion)
{

    if (strlen($string) !== 4) {
        return "String must be of length 4.";
    }


    $middleIndex = strlen($string) / 2;

    $result = substr($string, 0, $middleIndex) . $insertion . substr($string, $middleIndex)."<br/>";

    return $result;
}


$input_pairs = [
    ["[[]]", "Hello"],
    ["(())", "Hi"]
];


foreach ($input_pairs as $pair) {
    $string = $pair[0];
    $insertion = $pair[1];
    
    echo insertMiddle($string, $insertion);
}

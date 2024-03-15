<?php

function newStr($input)
{
    $len = strlen($input);
    if ($input[0] == 'a' && $input[$len - 1] == 'a') {
        return substr($input, 1, $len - 2);
    } elseif ($input[0] == 'a') {
        return substr($input, 1);
    } elseif ($input[$len - 1] == 'a') {
        return substr($input, 0, $len - 2);
    } else {
        return $input;
    }
}


$inputs = [
    "abcab",
    "Python",
    "abcda",
    "jython"
];


foreach ($inputs as $input) {

    echo "output :   " . newStr($input) . "<br/>";
}

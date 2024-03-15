<?php

function swapLast2($input)
{

    $len = strlen($input);
    if ($len < 3) {
        return "";
    } else if (substr($input, 0, 3) == "abc") {
        return "abc";
    } else if (substr($input, 0, 3) == "xyz") {
        return "xyz";
    } else {
        return "";
    }
}


$inputs = [
    "abc",
    "abcdef",
    "C",
    "xyz",
    "xyzsder"

];


foreach ($inputs as $input) {

    echo "output :   ".swapLast2($input) . "<br/>";
}

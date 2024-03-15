<?php

function stringOfN($input)
{
    $len1 = strlen($input[0]);
    $len2 = strlen($input[1]);
    if($len1 > $len2){
        return substr($input[0], -$len2).$input[1];
    }else if($len1 < $len2){
        return $input[0].substr($input[1], -$len1);
    }else {
        return $input[0].$input[1];
    }
}


$inputs = [
    ["abc", "abcd"],
    ["pyhton", "pyhton"],
    ["JS", "pyhton"]
];


foreach ($inputs as $input) {

    echo stringOfN($input) . "<br/>";
}

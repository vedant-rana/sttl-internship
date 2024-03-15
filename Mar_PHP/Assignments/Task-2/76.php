<?php

function checkFirstStrLen($str){
    if(strlen($str) == 0){
        return "#";
    }
    return substr($str, 0, 1);
}

function checkSecondStrLen($str){
    if(strlen($str) == 0){
        return "#";
    }
    return substr($str, -1);
}

function stringOfN($input)
{
    return checkFirstStrLen($input[0]).checkSecondStrLen($input[1]);
}


$inputs = [
    ["Hello", "Hi"],
    ["Python", "PHP"],
    ["JS", "JS"],
    ["Csharp", ""]

];


foreach ($inputs as $input) {

    echo stringOfN($input) . "<br/>";
}

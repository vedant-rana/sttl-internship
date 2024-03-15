<?php

function test($x, $y)
{
    if($x / 10 == $y / 10 || $x % 10 == $y % 10 || $x % 10 == $y / 10 || $x / 10 == $y % 10){
        return true;
    }
    return false;
}


var_dump(test(11, 21));
echo "<br/>";
var_dump(test(11, 20));
echo "<br/>";
var_dump(test(10, 10));
echo "<br/>";

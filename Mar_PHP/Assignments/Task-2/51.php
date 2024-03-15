<?php

function test($x, $y)
{

    if ($x == $y) {

        return 0;
    } else if (($x % 7 == $y % 7 && $x < $y) || $x > $y) {

        return $x;
    } else {

        return $y;
    }
}


echo test(11, 21) . "\n";
echo test(11, 20) . "\n";
echo test(10, 10) . "\n";

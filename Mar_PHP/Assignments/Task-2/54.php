<?php

function computeSum($num1, $num2, $num3)
{

    if ($num1 == $num2 || $num1 == $num3) {
        return $num3;
    } elseif ($num2 == $num3) {
        return $num1;
    }

    return $num1 + $num2 + $num3;
}


$input_sets = [
    [4, 5, 7],
    [7, 4, 12],
    [10, 10, 12],
    [12, 12, 18]
];


foreach ($input_sets as $set) {
    $num1 = $set[0];
    $num2 = $set[1];
    $num3 = $set[2];
    echo "The sum is: " . computeSum($num1, $num2, $num3) . "<br/>";
}

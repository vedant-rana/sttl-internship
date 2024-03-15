<?php

function checkDifference($small, $medium, $large)
{

    $diff1 = abs($medium - $small);
    $diff2 = abs($large - $medium);

    return $diff1 === $diff2;
}


$input_sets = [
    [4, 5, 6],
    [7, 12, 13],
    [-1, 0, 1]
];


foreach ($input_sets as $set) {
    $small = $set[0];
    $medium = $set[1];
    $large = $set[2];
    var_dump(checkDifference($small, $medium, $large));
    echo "<br/>";
}

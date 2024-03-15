<?php

function nearestTo13($num1, $num2) {
    
    if ($num1 > 13 && $num2 > 13) {
        return 0;
    }
    
    
    if ($num1 <= 13 && $num2 <= 13) {
        return max($num1, $num2);
    } elseif ($num1 <= 13) {
        return $num1;
    } else {
        return $num2;
    }
}


$input_pairs = [
    [4, 5],
    [7, 12],
    [10, 13],
    [17, 33]
];


foreach ($input_pairs as $pair) {
    $num1 = $pair[0];
    $num2 = $pair[1];
    echo nearestTo13($num1, $num2) . "<br/>";
}
?>

<?php

function compute_sum($num1, $num2) {
    $sum = $num1 + $num2;
    if ($sum >= 10 && $sum <= 20) {
        return 30;
    }
    return $sum;
}

$num1 = 5;
$num2 = 7;

$result = compute_sum($num1, $num2);
echo "Result: $result";
?>

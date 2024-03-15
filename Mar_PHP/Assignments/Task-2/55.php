<?php

function computeSum($numbers) {
    
    $sum = 0;
    
    for ($i = 0; $i < 3; $i++) {
        if ($numbers[$i] == 13) {
            $i++; 
            break;
        }
        $sum += $numbers[$i];
    }
    return $sum;
}


$input_sets = [
    [4, 5, 7],
    [7, 4, 12],
    [10, 13, 12],
    [13, 12, 18]
];


foreach ($input_sets as $set) {
    $num1 = $set[0];
    $num2 = $set[1];
    $num3 = $set[2];
    echo "The sum is: " . computeSum($set) . "<br/>";
}
?>

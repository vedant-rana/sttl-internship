<?php

function computeSum( $numbers) {
    
    $isInRange = function ($num) {
        return ($num >= 10 && $num <= 20 && $num != 13 && $num != 17);
    };

    
    $sum = 0;
   
    foreach ($numbers as $num) {
        if (!$isInRange($num)) {
            $sum += $num;
        }
    }
    return $sum;
}


$input_sets = [
    [4, 5, 7],
    [7, 4, 12],
    [10, 13, 12],
    [17, 12, 18]
];


foreach ($input_sets as $set) {
    
   computeSum($set);
   echo "The sum is: " . computeSum($set) . "<br/>";
}
?>

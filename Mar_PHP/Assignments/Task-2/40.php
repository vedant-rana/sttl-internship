<?php

function check_five($num1, $num2) {
    
    if ($num1 == 5 || $num2 == 5) {
        return true;
    }

    
    if (abs($num1 + $num2) == 5 || abs($num1 - $num2) == 5) {
        return true;
    }

    return false;
}


$num1 = 2;
$num2 = 7;


$result = check_five($num1, $num2);
if ($result) {
    echo "True";
} else {
    echo "False";
}
?>

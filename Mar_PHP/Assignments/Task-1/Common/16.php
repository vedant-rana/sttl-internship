<?php
function sumOfDigits($number) {
    $sum = 0;
    $number_str = (string)$number;
    for ($i = 0; $i < strlen($number_str); $i++) {
        $sum += (int)$number_str[$i];
    }
    return $sum;
}

$number = 12345;
$sum = sumOfDigits($number);
echo "The sum of the digits of $number is: $sum";
?>

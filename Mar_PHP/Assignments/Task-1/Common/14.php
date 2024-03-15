<?php
function isPrime($num) {
    if ($num <= 1) {
        return false;
    }
    for ($i = 2; $i * $i <= $num; $i++) {
        if ($num % $i == 0) {
            return false;
        }
    }
    return true;
}

$sum = 0;
for ($i = 2; $i < 200; $i++) {
    if (isPrime($i)) {
        $sum += $i;
    }
}
echo "The sum of prime numbers less than 200 is: $sum";
?>

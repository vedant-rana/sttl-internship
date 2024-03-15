<?php

$sum=0;
for ($i = 1; $i <= 10; $i++) {
    if ($i % 2 != 0) {
        $sum+=$i;
    }
}

echo '<h1>Sum of Odd numbers between 1 to 10 : '.$sum.' </h1>';

?>

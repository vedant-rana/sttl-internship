<?php

$string_with_zeroes = "00012345";


$string_without_zeroes = ltrim($string_with_zeroes, '0');

// Display the result
echo "String without leading zeroes: ".$string_without_zeroes;
?>

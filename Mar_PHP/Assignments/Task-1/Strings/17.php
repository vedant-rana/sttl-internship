<?php
$string = "Hello World.";
$words = explode(' ', $string);

$first_six_words = array_slice($words, 0, 6);

$result = implode(' ', $first_six_words);

echo $result;
?>

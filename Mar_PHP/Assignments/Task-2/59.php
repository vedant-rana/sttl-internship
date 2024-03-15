<?php 

function printString($s1, $s2) {
    echo $s1.$s2.$s1.$s2."<br/>";
}

$input_pairs = [
    ["Hi", "Hello"],
    ["whats", "app"]
];

foreach ($input_pairs as $pair) {
    $s1 = $pair[0];
    $s2 = $pair[1];
   
    printString($s1, $s2);
}

?>
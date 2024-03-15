<?php
function linearSearch($arr, $x) {
    $n = count($arr);
    for ($i = 0; $i < $n; $i++) {
        if ($arr[$i] == $x) {
            return $i; 
        }
    }
    return -1; 
}


$arr = [4, 2, 7, 1, 9, 5];
$searchElement = 7;
$index = linearSearch($arr, $searchElement);
if ($index != -1) {
    echo "Element $searchElement found at index: $index";
} else {
    echo "Element $searchElement not found in the array";
}
?>

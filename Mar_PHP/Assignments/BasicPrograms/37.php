<?php
function binarySearch($arr, $x) {
    $low = 0;
    $high = count($arr) - 1;
    
    while ($low <= $high) {
        $mid = floor(($low + $high) / 2);
        
        
        if ($arr[$mid] == $x) {
            return $mid;
        }
        
        
        if ($arr[$mid] < $x) {
            $low = $mid + 1;
        }
        
        
        else {
            $high = $mid - 1;
        }
    }
    
    
    return -1;
}


$arr = [2, 3, 4, 10, 40];
$searchElement = 10;
$index = binarySearch($arr, $searchElement);
if ($index != -1) {
    echo "Element $searchElement found at index: $index";
} else {
    echo "Element $searchElement not found in the array";
}
?>

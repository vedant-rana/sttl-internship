<?php
function mergeSort(&$arr) {
    $n = count($arr);
    if ($n > 1) {
        $mid = floor($n / 2);
        
        
        $leftHalf = array_slice($arr, 0, $mid);
        $rightHalf = array_slice($arr, $mid);
        
        
        mergeSort($leftHalf);
        mergeSort($rightHalf);
        
        
        merge($leftHalf, $rightHalf, $arr);
    }
}

function merge($leftHalf, $rightHalf, &$arr) {
    $i = $j = $k = 0;
    
    
    while ($i < count($leftHalf) && $j < count($rightHalf)) {
        if ($leftHalf[$i] < $rightHalf[$j]) {
            $arr[$k++] = $leftHalf[$i++];
        } else {
            $arr[$k++] = $rightHalf[$j++];
        }
    }
    
    
    while ($i < count($leftHalf)) {
        $arr[$k++] = $leftHalf[$i++];
    }
    
    
    while ($j < count($rightHalf)) {
        $arr[$k++] = $rightHalf[$j++];
    }
}


$arr = [12, 11, 13, 5, 6, 7];
echo "Original array: " . implode(", ", $arr) . "<br>";
mergeSort($arr);
echo "Sorted array: " . implode(", ", $arr);
?>

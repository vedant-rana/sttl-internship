<?php
function selectionSort($arr) {
    $n = count($arr);
    for ($i = 0; $i < $n - 1; $i++) {
        
        $min_index = $i;
        for ($j = $i + 1; $j < $n; $j++) {
            if ($arr[$j] < $arr[$min_index]) {
                $min_index = $j;
            }
        }
        
        
        $temp = $arr[$i];
        $arr[$i] = $arr[$min_index];
        $arr[$min_index] = $temp;
    }
    return $arr;
}


$arr = [64, 25, 12, 22, 11];
echo "Original array: " . implode(", ", $arr) . "<br>";
$result = selectionSort($arr);
echo "Sorted array: " . implode(", ", $result);
?>

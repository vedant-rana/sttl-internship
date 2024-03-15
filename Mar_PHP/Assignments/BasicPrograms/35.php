<?php
function insertionSort($arr) {
    $n = count($arr);
    for ($i = 1; $i < $n; $i++) {
        $key = $arr[$i];
        $j = $i - 1;
        
        
        while ($j >= 0 && $arr[$j] > $key) {
            $arr[$j + 1] = $arr[$j];
            $j = $j - 1;
        }
        $arr[$j + 1] = $key;
    }
    return $arr;
}


$arr = [12, 11, 13, 5, 6];
echo "Original array: " . implode(", ", $arr) . "<br>";
$result = insertionSort($arr);
echo "Sorted array: " . implode(", ", $result);
?>

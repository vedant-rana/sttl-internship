<?php
function quickSort(&$arr, $low, $high) {
    if ($low < $high) {
        
        $pivotIndex = partition($arr, $low, $high);

        
        quickSort($arr, $low, $pivotIndex - 1);
        quickSort($arr, $pivotIndex + 1, $high);
    }
}

function partition(&$arr, $low, $high) {
    
    $pivot = $arr[$high];

    
    $i = $low - 1;

    for ($j = $low; $j < $high; $j++) {
        
        if ($arr[$j] < $pivot) {
            $i++;

            
            $temp = $arr[$i];
            $arr[$i] = $arr[$j];
            $arr[$j] = $temp;
        }
    }

    
    $temp = $arr[$i + 1];
    $arr[$i + 1] = $arr[$high];
    $arr[$high] = $temp;

    return $i + 1;
}


$arr = [10, 7, 8, 9, 1, 5];
$n = count($arr);
echo "Original array: " . implode(", ", $arr) . "<br>";
quickSort($arr, 0, $n - 1);
echo "Sorted array: " . implode(", ", $arr);
?>

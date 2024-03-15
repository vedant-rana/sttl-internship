<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function findLargerAverage($arr) {
        $length = (int)(count($arr) / 2);
        $leftArr = array_slice($arr,0, $length);
        $rightArr = array_slice($arr, $length);
        $leftAvg = array_sum($leftArr) / count($leftArr);
        $rightAvg = array_sum($rightArr) / count($rightArr);
        return $leftAvg > $rightArr ? $leftAvg : $rightAvg;
    }
    
    $arr1 = array(1, 2, 3, 4, 6, 8);
    $arr2 = array(15, 2, 3, 4, 15, 11);

    $arr_of_arr = array($arr1, $arr2);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo findLargerAverage($arr) . "<br><br>";
    }

    ?>
</body>

</html>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function checkArr($arr, $noOfShifts) {
        $noOfShifts = $noOfShifts % count($arr);
        $leftArr = array_slice($arr, 0, $noOfShifts);
        $rightArr = array_slice($arr, $noOfShifts);
        return array_merge($rightArr, $leftArr);
    }

    $arr1 = array(10, 20, -30, -40, 50);

    echo "Input array: " . implode(",", $arr1) . "<br>";
    $result_arr = checkArr($arr1, 1);
    echo implode(",", $result_arr) . "<br><br>";
    ?>
</body>

</html>

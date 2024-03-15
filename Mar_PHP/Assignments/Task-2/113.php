<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php
    function checkArr($arr) {
        $resultArr = array_count_values($arr);
        if (array_key_exists(3, $resultArr) && array_key_exists(5, $resultArr) && $resultArr[3] > $resultArr[5]) {
            return "bool(true)";
        }
        return "bool(false)";
    }

    $arr1 = array(1, 5, 6, 9, 3, 3);
    $arr2 = array(1, 5, 5, 5, 10, 17);
    $arr3 = array(1, 3, 3, 5, 5, 5);

    $arr_of_arr = array($arr1, $arr2, $arr3);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>
</html>

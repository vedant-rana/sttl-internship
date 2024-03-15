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
        for ($i = 0; $i < count($arr) - 2; $i++) {
            if($arr[$i + 1] > $arr[$i] && $arr[$i + 2] > $arr[$i + 1] && (($arr[$i + 1] - $arr[$i]) == ($arr[$i + 2] - $arr[$i + 1]))){
                return "bool(true)";
            }
        }
        return "bool(false)";
    }

    $arr1 = array(1, 2, 3, 5, 3, 7);
    $arr2 = array(3, 7, 5, 5, 3, 7);
    $arr3 = array(3, 7, 5, 5, 6, 7, 5);

    $arr_of_arr = array($arr1, $arr2, $arr3);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>

</html>

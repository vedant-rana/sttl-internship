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
        if(in_array(5, $arr) || in_array(7, $arr)){
            return "bool(true)";
        }
        return "bool(false)";
    }

    $arr1 = array(1, 5, 6, 9, 10, 17);
    $arr2 = array(1, 4, 7, 9, 10, 17);
    $arr3 = array(1, 1, 2, 9, 10, 17);

    $arr_of_arr = array($arr1, $arr2, $arr3);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>

</html>

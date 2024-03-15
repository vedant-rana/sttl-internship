<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    $arr1 = array(1);
    $arr2 = array(1, 2, 9);
    $arr3 = array(1, 2, 9, 3, 3);
    $arr4 = array(1, 2, 3, 4, 5, 6, 7);
    $arr5 = array(1, 2, 2, 3, 7, 8, 9, 10, 6, 5, 4);

    $arr_of_arr = array($arr1, $arr2, $arr3, $arr4, $arr5);

    foreach ($arr_of_arr as $arr) {
        $middle_idx = (int)(count($arr) / 2);
        $max_val = max($arr[0], $arr[$middle_idx], $arr[count($arr) - 1]);
        echo $max_val . "<br>";
    }

    ?>
</body>

</html>
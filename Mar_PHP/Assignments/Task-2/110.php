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
            $length = count($arr);
            for ($i = 0; $i < $length - 1; $i++) {
                if ($arr[$i] == 5 && $arr[$i + 1] == 5) {
                    return "bool(true)";
                }
            }
            return "bool(false)";
    }

    $arr1 = array(1, 5, 6, 9, 10, 17);
    $arr2 = array(1, 5, 5, 9, 10, 17);
    $arr3 = array(1, 5, 5, 9, 10, 17, 5, 5);

    $arr_of_arr = array($arr1, $arr2, $arr3);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>

</html>

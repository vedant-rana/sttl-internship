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

        for ($i = 0; $i < $length - 2; $i++) {
            $current = $arr[$i];
            $next1 = $arr[$i + 1];
            $next2 = $arr[$i + 2];

            if (($current % 2 == 0 && $next1 % 2 == 0 && $next2 % 2 == 0) || ($current % 2 != 0 && $next1 % 2 != 0 && $next2 % 2 != 0)) {
                return "bool(true)";
            }
        }

        return "bool(false)";
    }

    $arr1 = array(3, 5, 1, 3, 7);
    $arr2 = array(1, 2, 3, 4);
    $arr3 = array(3, 3, 5, 5, 5, 5);
    $arr4 = array(2, 4, 5, 6);

    $arr_of_arr = array($arr1, $arr2, $arr3, $arr4);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>

</html>

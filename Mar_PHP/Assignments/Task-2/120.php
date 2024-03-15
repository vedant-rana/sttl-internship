
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
        $count = 0;

        foreach ($arr as $number) {
            if ($number == 5) {
                $count++;
            }
        }

        return $count == 5 && !containsConsecutiveFives($arr) ? "bool(true)" : "bool(false)";
    }

    function containsConsecutiveFives($arr) {
        $length = count($arr);

        for ($i = 0; $i < $length - 1; $i++) {
            if ($arr[$i] == 5 && $arr[$i + 1] == 5) {
                return true;
            }
        }

        return false;
    }

    $arr1 = array(3, 5, 1, 5, 3, 5, 7, 5, 1, 5);
    $arr2 = array(3, 5, 5, 5, 5, 5, 5);
    $arr3 = array(3, 5, 2, 5, 4, 5, 7, 5, 8, 5);
    $arr4 = array(2, 4, 5, 5, 5, 5);

    $arr_of_arr = array($arr1, $arr2, $arr3, $arr4);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>

</html>

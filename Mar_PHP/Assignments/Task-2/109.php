<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function getSum($arr) {
        $sum = 0;

        foreach ($arr as $val) {
            $valStr = (string)$val;
            if (!(strpos($valStr, '56') === 0 || strpos($valStr, '5') === false)) {
                $sum += $val;
            }
        }

        return $sum;
    }

    $arr1 = array(1, 5, 7, 9, 10, 17);
    $arr2 = array(1, 5, 6, 9, 10, 17);
    $arr3 = array(5, 6, 7, 9, 10, 17, 1);
    $arr4 = array(11, 9, 10, 17, 5, 6);

    $result1 = getSum($arr1);
    $result2 = getSum($arr2);
    $result3 = getSum($arr3);
    $result4 = getSum($arr4);

    echo "Input array: " . implode(",", $arr1) . "<br>";
    echo "Sum of the numbers of the said array except those numbers starting with 5 followed by at least one 6: " . $result1 . "<br><br>";

    echo "Input array: " . implode(",", $arr2) . "<br>";
    echo "Sum of the numbers of the said array except those numbers starting with 5 followed by at least one 6: " . $result2 . "<br><br>";

    echo "Input array: " . implode(",", $arr3) . "<br>";
    echo "Sum of the numbers of the said array except those numbers starting with 5 followed by at least one 6: " . $result3 . "<br><br>";

    echo "Input array: " . implode(",", $arr4) . "<br>";
    echo "Sum of the numbers of the said array except those numbers starting with 5 followed by at least one 6: " . $result4;

    ?>
</body>

</html>

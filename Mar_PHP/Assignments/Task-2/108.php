<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function computeSum($arr) {
        $sum = 0;

        foreach ($arr as $value) {
            if ($value != 17) {
                $sum += $value;
            }
        }

        return $sum;
    }

    $arr = array(1, 5, 7, 9, 10, 17);
    $result = computeSum($arr);

    echo "Input array: " . implode(",", $arr) . "<br>";
    echo "Sum of values in the array of integers except the number 17: " . $result;

    ?>
</body>

</html>

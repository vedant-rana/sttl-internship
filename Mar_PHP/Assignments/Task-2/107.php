<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function computeDifference($arr) {
        $minValue = min($arr);
        $maxValue = max($arr);

        return $maxValue - $minValue;
    }

    $arr = array(1, 5, 7, 9, 10, 12);
    $difference = computeDifference($arr);

    echo "Input array: " . implode(",", $arr) . "<br>";
    echo "Difference between the largest and smallest values: " . $difference;

    ?>
</body>

</html>

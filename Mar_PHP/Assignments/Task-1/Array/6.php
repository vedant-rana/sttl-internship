<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arr3</title>
</head>

<body>
    <?php
    $cars = array("BMW", "TOYOTA", "AUDI", "THAR", "HARRIER");
    $asso_cars;

    foreach ($cars as $car) {
        $asso_cars[$car] = strlen($car);
    }

    asort($asso_cars);
    $arr_keys = array_keys($asso_cars);

    echo "Shortest Length = " . $arr_keys[0] . " => " . $asso_cars[$arr_keys[0]];
    echo "<br>";
    echo "Longest Length = " . $arr_keys[count($arr_keys) - 1] . " => " . $asso_cars[$arr_keys[count($arr_keys) - 1]];

    ?>
</body>

</html>
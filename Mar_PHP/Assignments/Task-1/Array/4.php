<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arr4</title>
</head>

<body>
    <?php
    $tempratures = array(23.12, 44.2, 11.3, -1.3, -4.5, 2.4, 32.34, 43.12, 22.25, 32.34, 54, 11.17, 23.00, 45.32, 7.0);
    echo "Average Temprature = " . array_sum($tempratures) / count($tempratures) . "<br>";
    sort($tempratures);

    echo "<br>Five Lowest Tempratures <br>";
    $firstFive = array_slice($tempratures, 0, 5);
    foreach ($firstFive as $temprature) {
        echo $temprature . "<br>";
    }

    echo "<br>Five Highest Tempratures <br>";
    $lastFive = array_slice($tempratures, -5, count($tempratures));
    foreach ($lastFive as $temprature) {
        echo $temprature . "<br>";
    }
    ?>
</body>

</html>
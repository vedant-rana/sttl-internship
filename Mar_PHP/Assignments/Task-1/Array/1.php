<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arr1</title>
</head>

<body>
    <?php
    $cars = array("BMW", "TOYOTA", "AUDI", "THAR", "HARRIER");
    sort($cars);
    foreach ($cars as $car) {
        echo $car . "<br>";
    }
    ?>
</body>

</html>
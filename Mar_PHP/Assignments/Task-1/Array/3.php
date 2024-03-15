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
    array_splice($cars, 1, 0, "BREZZA");
    foreach ($cars as $car) {
        echo $car . "<br>";
    }
    ?>
</body>

</html>
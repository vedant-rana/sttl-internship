<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arr4</title>
</head>

<body>
    <?php
    $arr = array(12, 0, 14, 53, 34, 0, 23, 3, 2, 0, 0, 6, -4);
    rsort($arr);
    foreach ($arr as $val) {
        echo $val . "<br>";
    }
    ?>
</body>

</html>
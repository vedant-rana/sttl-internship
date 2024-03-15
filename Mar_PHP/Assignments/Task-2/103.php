<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php
    $arr = array(1, 5, 7, 9, 11, 13);
    $length = count($arr);
    $middle_ele = ($length % 2 == 0) ? ($length / 2) - 1 : floor($length / 2);

    $new_arr = array_slice($arr, $middle_ele, 3);

    foreach ($new_arr as $val) {
        echo $val . ", ";
    }
    ?>
</body>

</html>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php
    $arr1 = array(10, 20, 30);
    $arr2 = array(40, 50, 60);
    $merged_arr = array_merge($arr1, $arr2);
    foreach ($merged_arr as $val) {
        echo $val . ", ";
    }
    ?>
</body>

</html>
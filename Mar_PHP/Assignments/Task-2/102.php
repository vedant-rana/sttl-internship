<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php
    $arr = array(1, 3, 5, 7, 9, 11, 13);
    
    if(is_array($arr) && count($arr) > 0) {
        $temp = $arr[0];
        $arr[0] = $arr[count($arr) - 1];
        $arr[count($arr) - 1] = $temp;
    }

    foreach ($arr as $val) {
        echo $val . ", ";
    }
    ?>
</body>

</html>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php
    function checkArr($arr) {
        if(!(in_array(3, $arr) && in_array(5, $arr))) {
            return "bool(true)";
        }
        return "bool(false)";
    }

    $arr1 = array( 5, 5, 5, 5, 5);
    $arr2 = array(3, 3, 3, 3);
    $arr3 = array(3, 3, 3, 5, 5, 5);
    $arr4 = array(1, 6, 8, 10);

    $arr_of_arr = array($arr1, $arr2, $arr3, $arr4);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>
</html>

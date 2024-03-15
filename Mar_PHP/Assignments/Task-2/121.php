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
        $flag = false;
        $length = count($arr);
        for ($i = 1; $i < $length; $i++) {
            if($arr[$i] == 5){
                $flag = false;
            }
            if ($arr[$i] == 5 && $arr[$i - 1] == 5) {
                $flag = true;
            }
        }

        if($flag){
            return "bool(true)";
        }else{
            return "bool(false)";
        }
    }

    $arr1 = array(3, 5, 5, 3, 7);
    $arr2 = array(3, 5, 5, 4, 1, 5, 7);
    $arr3 = array(3, 5, 5, 5, 5, 5);
    $arr4 = array(2, 4, 5, 5, 6, 7, 5);

    $arr_of_arr = array($arr1, $arr2, $arr3, $arr4);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>

</html>

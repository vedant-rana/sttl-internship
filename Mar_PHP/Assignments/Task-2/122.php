<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program 122</title>
</head>

<body>
    <?php

    function checkArr($arr, $num) {
        $sliced_one = array_slice($arr, 0, $num);
        $sliced_two = array_slice($arr, count($arr) - $num, $num);

        if($sliced_one == $sliced_two){
            return "bool(true)";
        }else{
            return "bool(false)";
        }
    }

    $arr1 = array(3, 7, 5, 5, 3, 7);
    $arr2 = array(3, 7, 5, 5, 3, 7);
    $arr3 = array(3, 7, 5, 5, 3, 7, 5);

    echo "Input array: " . implode(",", $arr1) . "<br>";
    echo checkArr($arr1, 2) . "<br><br>";
    
    echo "Input array: " . implode(",", $arr2) . "<br>";
    echo checkArr($arr2, 3) . "<br><br>";
    
    echo "Input array: " . implode(",", $arr3) . "<br>";
    echo checkArr($arr3, 3) . "<br><br>";
    ?>
</body>

</html>

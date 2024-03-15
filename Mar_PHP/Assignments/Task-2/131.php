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
            $length = count($arr);
            if($length > 2){
                for ($i = 0; $i < $length - 1; $i++) {
                    if (($arr[$i] == 15 && $arr[$i + 1] == 15)) {
                        return "bool(true)";
                    }
                }
                return "bool(false)";
            }else{
                return "Array must have atleast 2 element";
            }
    }
    
    $arr1 = array( 5, 5, 1, 15, 15);
    $arr2 = array(15, 2, 3, 4, 15);
    $arr3 = array(3, 3, 15, 15, 5, 5);
    $arr4 = array(1, 5, 15, 7, 8, 15);

    $arr_of_arr = array($arr1, $arr2, $arr3, $arr4);

    foreach ($arr_of_arr as $arr) {
        echo "Input array: " . implode(",", $arr) . "<br>";
        echo checkArr($arr) . "<br><br>";
    }

    ?>
</body>

</html>

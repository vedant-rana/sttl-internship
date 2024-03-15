<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function checkOddValues($arr, $total) {
        $newArr = [];
        foreach($arr as $val) {
            if($val > 0 && ($val % 2 != 0)){
                array_push( $newArr, $val);
                $total--;
            }
            if( $total == 0){
                return $newArr;
            }
        }
        return $newArr;
    }

    $arr = array(1, 2, 3, 5, 7, 9, 10);

    echo "Input array: " . implode(",", $arr) . "<br>";
    $result_arr = checkOddValues($arr, 3);
    echo "New array: " . implode(",", $result_arr) . "<br><br>";
    ?>
</body>

</html>

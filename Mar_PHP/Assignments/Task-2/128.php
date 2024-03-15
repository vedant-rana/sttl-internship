<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function createNewArray($arr) {
        $zeroArr = [];
        $numArr = [];
        foreach($arr as $val){
            if($val == 0 || $val == 5){
                array_push($zeroArr, 0);
            }else{
                array_push($numArr, $val);
            }
        }

        return array_merge($numArr, $zeroArr);
    }

    $arr1 = array(1, 2, 0, 3, 5, 7, 0, 9, 11);

    echo "Input array: " . implode(",", $arr1) . "<br>";
    $result_arr = createNewArray($arr1);
    echo "New array: " . implode(",", $result_arr) . "<br><br>";
    ?>
</body>

</html>

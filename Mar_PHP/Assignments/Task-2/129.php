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
        $oddArr = [];
        $evenArr = [];
        foreach($arr as $val){
            if($val % 2 == 0){
                array_push($evenArr, $val);
            }else{
                array_push($oddArr, $val);
            }
        }

        return array_merge($evenArr, $oddArr);
    }

    $arr1 = array(1, 2, 5, 3, 5, 4, 6, 9, 11 );

    echo "Input array: " . implode(",", $arr1) . "<br>";
    $result_arr = createNewArray($arr1);
    echo "New array: " . implode(",", $result_arr) . "<br><br>";
    ?>
</body>

</html>
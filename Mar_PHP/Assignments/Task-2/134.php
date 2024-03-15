<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function countSameLengthString($arr, $total) {
        $newArr = [];
        for ($i = 0; $i < $total; $i++){
            array_push($newArr, $arr[$i]);
        }
        return $newArr;
    }
    
    $arr = array("a", "b", "bb", "c", "ccc");
    echo "Input array: " . implode(",", $arr) . "<br>";
    $resultArr = countSameLengthString($arr, 3);
    echo "Output array: " . implode(",", $resultArr) . "<br><br>";
    ?>
</body>

</html>

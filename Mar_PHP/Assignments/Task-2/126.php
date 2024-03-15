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
        $find_idx = array_search(5, $arr);

        if($find_idx > 0){
            $newArr = array_slice($arr, $find_idx + 1);
        }
        return $newArr;
    }

    $arr1 = array(1, 2, 3, 5, 7, 9, 11);

    echo "Input array: " . implode(",", $arr1) . "<br>";
    $result_arr = createNewArray($arr1);
    echo "New array: " . implode(",", $result_arr) . "<br><br>";
    ?>
</body>

</html>

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
        if (count($arr) < 2) {
            return $arr;
        } else {
            $newArray = array_slice($arr, 0, 2);
            return $newArray;
        }
    }

    $arr = array(1, 5, 7, 9, 11, 13);
    $newArray = createNewArray($arr);

    echo "Input array: " . implode(",", $arr) . "<br>";
    echo "Output array:  " . implode(",", $newArray);

    ?>
</body>

</html>

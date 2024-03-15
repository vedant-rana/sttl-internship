<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function countSameLengthString($arr, $len) {
        $counter = 0;
        foreach ($arr as $str) {
            if (strlen($str) == $len) {
                $counter++;
            }
        }
        return $counter;
    }
    
    $arr = array("a", "b", "bb", "c", "ccc");
    echo "Input array: " . implode(",", $arr) . "<br>";
    echo countSameLengthString($arr, 1) . "<br><br>";

    ?>
</body>

</html>

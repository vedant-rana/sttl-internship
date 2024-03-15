<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function countEvenElements($arr) {
        $count = 0;

        foreach ($arr as $element) {
            if ($element % 2 == 0) {
                $count++;
            }
        }

        return $count;
    }

    $arr = array(1, 5, 7, 9, 10, 12);
    $evenCount = countEvenElements($arr);

    echo "Input array: " . implode(",", $arr) . "<br>";
    echo "Output array: " . $evenCount;

    ?>
</body>

</html>

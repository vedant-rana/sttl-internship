<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arr4</title>
</head>

<body>
    <?php
    function getLowestInteger($arr)
    {
        sort($arr);
        foreach ($arr as $val) {
            if ($val != 0) {
                return $val;
            }
        }
    }

    $int_arr = array(12, 0, 14, 53, 34, 0, 23, 3, 2, 0, 0, 6, -4);
    echo getLowestInteger($int_arr);
    ?>
</body>

</html>
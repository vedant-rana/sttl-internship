<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Program</title>
</head>

<body>
    <?php

    function checkValue($val) {
        $str_val = (string)$val;
        if($val > 0 && str_contains($str_val, "2")){
            return "bool(true)";
        }
        return "bool(false)";
    }
    
    $arr = array(123, 13, 222);

    foreach ($arr as $val) {
        echo "Input value: " . $val . "<br>";
        echo checkValue($val) . "<br><br>";
    }

    ?>
</body>

</html>

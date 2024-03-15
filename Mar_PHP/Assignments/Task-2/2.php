<!DOCTYPE html>
<html>
<head>
    <title>Absolute Difference</title>
</head>
<body>
    <?php
    function absoluteDifference($n) {
        $difference = abs($n - 51);
        if ($n > 51) {
            return 3 * $difference;
        } else {
            return $difference;
        }
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $inputNumber = $_POST["number"];
        $result = absoluteDifference($inputNumber);
        echo $result;
    }
    ?>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter a number: <input type="number" name="number"><br>
        <input type="submit" value="Calculate">
    </form>
</body>
</html>

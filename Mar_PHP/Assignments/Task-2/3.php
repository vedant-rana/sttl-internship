<!DOCTYPE html>
<html>
<head>
    <title>Check for 30</title>
</head>
<body>
    <?php
    function checkFor($num1, $num2) {
        if ($num1 == 30 || $num2 == 30 || $num1 + $num2 == 30) {
            return true;
        } else {
            return false;
        }
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $number1 = $_POST["number1"];
        $number2 = $_POST["number2"];
        $result = checkFor($number1, $number2);
        if ($result) {
            echo "True";
        } else {
            echo "False";
        }
    }
    ?>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter first number: <input type="number" name="number1"><br>
        Enter second number: <input type="number" name="number2"><br>
        <input type="submit" value="Check">
    </form>
</body>
</html>

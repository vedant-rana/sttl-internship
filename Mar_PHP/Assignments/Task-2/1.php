<!DOCTYPE html>
<html>
<head>
    <title>Sum or Triple</title>
</head>
<body>
    <?php
    function sumOrTriple($num1, $num2) {
        if ($num1 == $num2) {
            return 3 * ($num1 + $num2);
        } else {
            return $num1 + $num2;
        }
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $num1 = $_POST["num1"];
        $num2 = $_POST["num2"];
        $result = sumOrTriple($num1, $num2);
        echo $result;
    }
    ?>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter first integer: <input type="number" name="num1"><br>
        Enter second integer: <input type="number" name="num2"><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>

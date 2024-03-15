<!DOCTYPE html>
<html>
<head>
    <title>Check </title>
</head>
<body>
    <?php
    function check($num) {
        return (abs(100 - $num) <= 10) || (abs(200 - $num) <= 10);
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $number = $_POST["number"];
        $result = check($number);
        if ($result) {
            echo "True<br/>";
        } else {
            echo "False<br/>";
        }
    }
    ?>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter a number: <input type="number" name="number"><br>
        <input type="submit" value="Check">
    </form>
</body>
</html>

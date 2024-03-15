<!DOCTYPE html>
<html>
<head>
    <title>Find the Greatest Number</title>
</head>
<body>

<form method="post">
    <label for="num1">Enter the first number:</label>
    <input type="number" id="num1" name="num1"><br><br>
    <label for="num2">Enter the second number:</label>
    <input type="number" id="num2" name="num2"><br><br>
    <label for="num3">Enter the third number:</label>
    <input type="number" id="num3" name="num3"><br><br>
    <button type="submit">Find the Greatest</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $a = $_POST['num1'];
    $b = $_POST['num2'];
    $c = $_POST['num3'];

    if ($a > $b && $a > $c) {
        echo "$a is greater than $b and $c";
    } elseif ($b > $a && $b > $c) {
        echo "$b is greater than $a and $c";
    } else {
        echo "$c is greater than $a and $b";
    }
}
?>

</body>
</html>

<!DOCTYPE html>
<html>
<head>
    <title>Swap Two Numbers</title>
</head>
<body>

<form method="post">
    <label for="num1">Enter the first number:</label>
    <input type="number" id="num1" name="num1"><br><br>
    <label for="num2">Enter the second number:</label>
    <input type="number" id="num2" name="num2"><br><br>
    <button type="submit">Swap</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $a = $_POST['num1'];
    $b = $_POST['num2'];

    echo "Before Swap a = $a and b = $b<br/>";
    $temp = $a;
    $a = $b;
    $b = $temp;
    echo "After Swap a = $a and b = $b";
}
?>

</body>
</html>

<!DOCTYPE html>
<html>
<head>
    <title>Convert Fahrenheit to Celsius</title>
</head>
<body>

<form method="post">
    <label for="fahrenheit">Enter the temperature in Fahrenheit:</label>
    <input type="number" id="fahrenheit" name="fahrenheit"><br><br>
    <button type="submit">Convert</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $fahrenheit = $_POST['fahrenheit'];
    $celsius = (5.0 / 9.0) * ($fahrenheit - 32);
    echo "Temperature in Celsius: $celsius C";
}
?>

</body>
</html>

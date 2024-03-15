<!DOCTYPE html>
<html>
<head>
    <title>Convert Celsius to Fahrenheit</title>
</head>
<body>

<form method="post">
    <label for="celsius">Enter the temperature in Celsius:</label>
    <input type="number" id="celsius" name="celsius"><br><br>
    <button type="submit">Convert</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $celsius = $_POST['celsius'];
    $fahrenheit = (9.0 / 5.0) * $celsius + 32;
    echo "Temperature in Fahrenheit: $fahrenheit F";
}
?>

</body>
</html>

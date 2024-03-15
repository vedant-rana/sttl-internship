<!DOCTYPE html>
<html>
<head>
    <title>Calculate Triangle Area</title>
</head>
<body>

<form method="post">
    <label for="base">Enter the base of the triangle:</label>
    <input type="number" id="base" name="base"><br><br>
    <label for="height">Enter the height of the triangle:</label>
    <input type="number" id="height" name="height"><br><br>
    <button type="submit">Calculate Area</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $base = $_POST['base'];
    $height = $_POST['height'];

    if ($base < 0 || $height < 0) {
        echo "Enter valid height and base for the Triangle";
    } else {
        $area = 0.5 * ($base * $height);
        echo "Triangle Area is: $area";
    }
}
?>

</body>
</html>

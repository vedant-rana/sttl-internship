<!DOCTYPE html>
<html>
<head>
    <title>Calculate Circle Area</title>
</head>
<body>

<form method="post">
    <label for="radius">Enter the radius of the circle:</label>
    <input type="number" id="radius" name="radius">
    <button type="submit">Calculate Area</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $radius = $_POST['radius'];

    if ($radius < 0) {
        echo "Enter a valid radius for the circle";
    } else {
        $pi = 3.14;
        $area = $pi * ($radius * $radius);
        echo "Circle Area is: $area";
    }
}
?>

</body>
</html>

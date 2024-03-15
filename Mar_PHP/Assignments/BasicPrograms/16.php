<!DOCTYPE html>
<html>
<head>
    <title>Calculate Rectangle Area</title>
</head>
<body>

<form method="post">
    <label for="width">Enter the width of the rectangle:</label>
    <input type="number" id="width" name="width"><br><br>
    <label for="height">Enter the height of the rectangle:</label>
    <input type="number" id="height" name="height"><br><br>
    <button type="submit">Calculate Area</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $width = $_POST['width'];
    $height = $_POST['height'];

    if ($width < 0 || $height < 0) {
        echo "Enter valid height and width for the Rectangle";
    } else {
        $area = $width * $height;
        echo "Rectangle Area is: $area";
    }
}
?>

</body>
</html>

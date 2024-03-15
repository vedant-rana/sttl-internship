


<!DOCTYPE html>
<html>
<head>
    <title>Check Number Type</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a number:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Check</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n = $_POST['number'];

    if ($n == 0) {
        echo "Number is Zero";
    } elseif ($n % 2 == 0) {
        echo "$n is Even";
    } else {
        echo "$n is Odd";
    }
}
?>

</body>
</html>

<!DOCTYPE html>
<html>
<head>
    <title>Reverse a Number</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a number to reverse:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Reverse</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n = $_POST['number'];
    $rev = 0;

    while ($n != 0) {
        $remainder = $n % 10;
        $rev = $rev * 10 + $remainder;
        $n = (int)($n / 10);
    }

    echo "Reversed number is = $rev";
}
?>

</body>
</html>

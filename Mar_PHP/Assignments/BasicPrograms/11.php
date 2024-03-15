<!DOCTYPE html>
<html>
<head>
    <title>Sum of Digits</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a number to calculate the sum of its digits:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Calculate Sum</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n = $_POST['number'];
    $sum = 0;
    $ori = $n;

    while ($n != 0) {
        $remainder = $n % 10;
        $sum += $remainder;
        $n = (int)($n / 10);
    }

    echo "The sum of digits of $ori is: $sum";
}
?>

</body>
</html>

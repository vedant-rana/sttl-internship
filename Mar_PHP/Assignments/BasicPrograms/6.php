<!DOCTYPE html>
<html>
<head>
    <title>Calculate Factorial</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a number to calculate factorial:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Calculate</button>
</form>

<?php
function calculateFactorial($n) {
    $fact = 1;

    if ($n == 0) {
        return 1;
    } else {
        for ($i = 1; $i <= $n; $i++) {
            $fact *= $i;
        }
        return $fact;
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $number = $_POST['number'];
    $factorial = calculateFactorial($number);
    echo "Factorial of $number is: $factorial";
}
?>

</body>
</html>

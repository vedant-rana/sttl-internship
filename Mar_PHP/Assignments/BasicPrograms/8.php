<!DOCTYPE html>
<html>
<head>
    <title>Check Prime Number</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a number to check if it's prime:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Check Prime</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n = $_POST['number'];
    $isPrime = true;

    if ($n == 0 || $n == 1) {
        $isPrime = false;
    } else {
        for ($i = 2; $i <= $n / 2; $i++) {
            if ($n % $i == 0) {
                $isPrime = false;
                break;
            }
        }
    }

    if ($isPrime) {
        echo "$n is a Prime Number.";
    } else {
        echo "$n is not a Prime Number.";
    }
}
?>

</body>
</html>

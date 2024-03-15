<!DOCTYPE html>
<html>
<head>
    <title>Fibonacci Series</title>
</head>
<body>

<form method="post">
    <label for="number">Enter the number of terms for Fibonacci series:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Generate Series</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n = $_POST['number'];

    $a = 0;
    $b = 1;
    $c = $a + $b;

    if ($n == 1) {
        echo "Fibonacci Series is: 0";
    } elseif ($n == 2) {
        echo "Fibonacci Series is: 0 --> 1";
    } else {
        echo "Fibonacci Series is: 0 --> 1";
        for ($i = 3; $i <= $n; $i++) {
            echo " --> $c";
            $a = $b;
            $b = $c;
            $c = $a + $b;
        }
    }
}
?>

</body>
</html>

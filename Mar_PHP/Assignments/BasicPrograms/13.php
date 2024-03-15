<!DOCTYPE html>
<html>
<head>
    <title>Binary to Decimal Conversion</title>
</head>
<body>

<form method="post">
    <label for="binary">Enter a binary number to convert to decimal:</label>
    <input type="text" id="binary" name="binary">
    <button type="submit">Convert</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $binary = $_POST['binary'];
    $n = intval($binary);
    $i = 0;
    $ans = 0;

    while ($n != 0) {
        $digit = $n % 10;
        if ($digit == 1) {
            $ans += pow(2, $i);
        }
        $n = (int)($n / 10);
        $i++;
    }

    echo "Decimal equivalent: $ans";
}
?>

</body>
</html>

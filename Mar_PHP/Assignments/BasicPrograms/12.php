<!DOCTYPE html>
<html>
<head>
    <title>Decimal to Binary Conversion</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a decimal number to convert to binary:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Convert</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n = $_POST['number'];
    $binaryNum = array();

    $i = 0;
    while ($n > 0) {
        $binaryNum[$i] = $n % 2;
        $n = (int)($n / 2);
        $i++;
    }

    echo "Binary representation: ";
    for ($j = $i - 1; $j >= 0; $j--) {
        echo $binaryNum[$j];
    }
}
?>

</body>
</html>

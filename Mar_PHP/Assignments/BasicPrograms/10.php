<!DOCTYPE html>
<html>
<head>
    <title>Palindrome Check</title>
</head>
<body>

<form method="post">
    <label for="number">Enter a number to check if it's a palindrome:</label>
    <input type="number" id="number" name="number">
    <button type="submit">Check Palindrome</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n = $_POST['number'];
    $ori = $n;
    $rev = 0;

    while ($n != 0) {
        $remainder = $n % 10;
        $rev = $rev * 10 + $remainder;
        $n = (int)($n / 10);
    }

    if ($ori == $rev) {
        echo "$ori is a palindrome number";
    } else {
        echo "$ori is not a palindrome number";
    }
}
?>

</body>
</html>

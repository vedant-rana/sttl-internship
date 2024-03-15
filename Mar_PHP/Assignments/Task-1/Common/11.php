<!DOCTYPE html>
<html>
<head>
    <title>Armstrong Number Checker</title>
</head>
<body>

<h2>Armstrong Number Checker</h2>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    <label for="number">Enter a number:</label>
    <input type="text" id="number" name="number">
    <input type="submit" value="Check">
</form>

<?php
function isArmstrong($number) {
    $num_digits = strlen((string)$number);
    $sum = 0;
    $temp = $number;

    while ($temp > 0) {
        $digit = $temp % 10;
        $sum += pow($digit, $num_digits);
        $temp = floor($temp / 10);
    }


    return $sum == $number;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $number = $_POST['number'];

    if (!is_numeric($number)) {
        echo "Please enter a valid number.";
    } else {
        if (isArmstrong($number)) {
            echo "$number is an Armstrong number.";
        } else {
            echo "$number is not an Armstrong number.";
        }
    }
}
?>

</body>
</html>

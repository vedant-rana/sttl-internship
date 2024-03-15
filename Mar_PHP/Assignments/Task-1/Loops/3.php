<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calculate Factorial</title>
</head>
<body>

<form method="post" action="">
    Enter a number: <input type="number" name="number" required>
    <input type="submit" value="Calculate Factorial">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if the input is set and not empty
    if (isset($_POST['number']) && $_POST['number'] !== '') {
        $number = intval($_POST['number']);
        $factorial = 1;

        // Calculate factorial
        for ($i = 1; $i <= $number; $i++) {
            $factorial *= $i;
        }

        echo "The factorial of $number is $factorial.";
    } else {
        echo "Please enter a valid number.";
    }
}
?>

</body>
</html>

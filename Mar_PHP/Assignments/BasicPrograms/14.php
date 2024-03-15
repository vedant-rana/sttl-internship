<!DOCTYPE html>
<html>
<head>
    <title>Calculator</title>
</head>
<body>

<form method="post">
    <label for="number1">Enter the first number:</label>
    <input type="number" id="number1" name="number1"><br><br>
    <label for="number2">Enter the second number:</label>
    <input type="number" id="number2" name="number2"><br><br>
    <label for="operator">Enter the operator (+, -, *, /):</label>
    <input type="text" id="operator" name="operator"><br><br>
    <button type="submit">Calculate</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $n1 = $_POST['number1'];
    $n2 = $_POST['number2'];
    $operator = $_POST['operator'];

    switch ($operator) {
        case '+':
            $result = $n1 + $n2;
            break;
        case '*':
            $result = $n1 * $n2;
            break;
        case '-':
            $result = $n1 - $n2;
            break;
        case '/':
            if ($n2 != 0) {
                $result = $n1 / $n2;
            } else {
                echo "Division by zero is not allowed";
                exit(); 
            }
            break;
        default:
            echo "Invalid Operator";
            exit(); 
    }

    echo "Result: $result";
}
?>

</body>
</html>

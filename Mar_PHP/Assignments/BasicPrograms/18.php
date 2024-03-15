<!DOCTYPE html>
<html>
<head>
    <title>Calculate Interest</title>
</head>
<body>

<form method="post">
    <label for="price">Enter the price:</label>
    <input type="number" id="price" name="price"><br><br>
    <label for="rate">Enter the rate:</label>
    <input type="number" id="rate" name="rate"><br><br>
    <label for="year">Enter the year:</label>
    <input type="number" id="year" name="year"><br><br>
    <button type="submit">Calculate Interest</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $price = $_POST['price'];
    $rate = $_POST['rate'];
    $year = $_POST['year'];

    if ($rate <= 0 || $price <= 0 || $year <= 0) {
        echo "Enter valid Rate, Price, and Year above Zero";
    } else {
        $interest = ($price * $rate * $year) / 100;
        echo "Interest is: $interest";
    }
}
?>

</body>
</html>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Check Perfect Number</title>
</head>
<body>
    <h2>Check Perfect Number</h2>
    <form method="post">
        Enter a number: <input type="number" name="number" required>
        <input type="submit" name="check" value="Check">
    </form>

    <?php
    if (isset($_POST['check'])) {
        $number = $_POST['number'];
        $sum = 0;

        
        for ($i = 1; $i < $number; $i++) {
            if ($number % $i == 0) {
                $sum += $i;
            }
        }

        
        if ($sum == $number) {
            echo "<p>$number is a Perfect Number.</p>";
        } else {
            echo "<p>$number is not a Perfect Number.</p>";
        }
    }
    ?>
</body>
</html>

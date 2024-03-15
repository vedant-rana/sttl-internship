<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Check Armstrong Number</title>
</head>
<body>
    <h2>Check Armstrong Number</h2>
    <form method="post">
        Enter a number: <input type="number" name="number" required>
        <input type="submit" name="check" value="Check">
    </form>

    <?php
    if (isset($_POST['check'])) {
        $number = $_POST['number'];
        $sum = 0;
        $temp = $number;

        while ($temp != 0) {
            $remainder = $temp % 10;
            $sum += pow($remainder, 3);
            $temp = (int)($temp / 10);
        }

        if ($sum == $number) {
            echo "<p>$number is an Armstrong Number.</p>";
        } else {
            echo "<p>$number is not an Armstrong Number.</p>";
        }
    }
    ?>
</body>
</html>

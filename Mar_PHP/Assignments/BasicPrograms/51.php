<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    
    <form method="post">
        <label for="year">Enter a year:</label><br>
        <input type="number" id="year" name="year" required><br><br>
        <input type="submit" value="Check Leap Year">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $year = $_POST["year"];
        if ((($year % 4 == 0) && ($year % 100 != 0)) || ($year % 400 == 0)) {
            echo "<p>$year is a leap year.</p>";
        } else {
            echo "<p>$year is not a leap year.</p>";
        }
    }
    ?>
</body>
</html>

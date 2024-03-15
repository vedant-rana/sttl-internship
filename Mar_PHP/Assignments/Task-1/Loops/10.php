<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Multiplication Table</title>
</head>
<body>
    <form method="post" action="">
        Enter a number: <input type="number" name="number" required>
        <br>
        Enter the limit: <input type="number" name="limit" required>
        <br>
        <input type="submit" value="Generate Table">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the inputs are set and not empty
        if (isset($_POST['number']) && $_POST['number'] !== '' && isset($_POST['limit']) && $_POST['limit'] !== '') {
            $number = $_POST['number'];
            $limit = $_POST['limit'];

            echo "<h2>Multiplication Table for $number up to $limit:</h2>";
            echo "<table border='1'>";
            for ($i = 1; $i <= $limit; $i++) {
                echo "<tr>";
                echo "<td>$number</td>";
                echo "<td>*</td>";
                echo "<td>$i</td>";
                echo "<td>=</td>";
                echo "<td>" . ($number * $i) . "</td>";
                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "Please enter valid numbers.";
        }
    }
    ?>
</body>
</html>

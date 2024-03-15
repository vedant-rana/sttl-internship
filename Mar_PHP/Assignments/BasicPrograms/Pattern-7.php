<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Diamond Pattern</title>
</head>

<body>

    <h2>Diamond Pattern</h2>

    <form method="post" action="">
        Enter the number of rows: <input type="number" name="rows" required><br>
        <input type="submit" value="Print Diamond">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $rows = $_POST["rows"];
        for ($i = 1; $i <= $rows; $i++) {
            for ($j = 1; $j <= $rows - $i; $j++) {
                echo "&nbsp;&nbsp;&nbsp;";
            }
            for ($j = 1; $j <= 2 * $i - 1; $j++) {
                echo "* ";
            }
            echo "<br>";
        }

        for ($i = $rows - 1; $i >= 1; $i--) {
            for ($j = 1; $j <= $rows - $i; $j++) {
                echo "&nbsp;&nbsp;&nbsp;";
            }
            for ($j = 1; $j <= 2 * $i - 1; $j++) {
                echo "* ";
            }
            echo "<br>";
        }
    }
    ?>

</body>

</html>
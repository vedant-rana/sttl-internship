<!DOCTYPE html>
<html>
<head>
    <title>Diamond Triangle</title>
</head>
<body>

<form method="post">
    <label for="rows">Enter the Number Of rows for Diamond Triangle:</label>
    <input type="number" id="rows" name="rows">
    <button type="submit">Submit</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $rows = $_POST['rows'];

    for ($row = 1; $row < (2 * $rows); $row++) {
        if ($row <= $rows) {
            for ($space = 1; $space <= $rows - $row; $space++) {
                echo "&nbsp;&nbsp;";
            }
            for ($star = 1; $star <= $row; $star++) {
                echo "*&nbsp;&nbsp;";
            }
        } else {
            for ($space = 1; $space <= $row - $rows; $space++) {
                echo "&nbsp;&nbsp;";
            }
            for ($star = 1; $star <= (2 * $rows - $row); $star++) {
                echo "*&nbsp;&nbsp;";
            }
        }
        echo "<br>";
    }
}
?>

</body>
</html>

<!DOCTYPE html>
<html>
<head>
    <title>Hollow Triangle</title>
</head>
<body>

<form method="post">
    <h2>Number Pattern</h2>
    <label for="rows">Enter the Number Of rows for Hollow Triangle:</label>
    <input type="number" id="rows" name="rows">
    <button type="submit">Submit</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $rows = $_POST['rows'];
    $n = 1;

    for ($i = 0; $i < $rows; $i++) {
        for ($space = 0; $space < $rows - $i; $space++) {
            echo "&nbsp;&nbsp;";
        }
        for ($num = 0; $num <= $i; $num++) {
            echo $n . "&nbsp;&nbsp;";
        }
        echo "<br>";
        $n++;
    }
}
?>

</body>
</html>

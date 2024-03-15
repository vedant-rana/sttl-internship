<!DOCTYPE html>
<html>
<head>
    <title>Hollow Triangle</title>
</head>
<body>

<form method="post">
    <h2>Print Floyd's Triangle
</h2>
    <label for="rows">Enter the Number Of rows for Hollow Triangle:</label>
    <input type="number" id="rows" name="rows">
    <button type="submit">Submit</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $rows = $_POST['rows'];
    $n = 1;

    for ($i = 0; $i < $rows; $i++) {
        for ($num = 0; $num <= $i; $num++) {
            if ($n > 9) {
                echo $n . "&nbsp;";
            } else {
                echo $n . "&nbsp;&nbsp;";
            }
            $n++;
        }
        echo "<br>";
    }
}
?>

</body>
</html>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Pascal's Triangle</title>
</head>
<body>
    <h2>Pascal's Triangle</h2>
    <form method="post">
        <label for="rows">Enter the Number Of rows for Pascal Triangle:</label>
        <input type="number" id="rows" name="rows" required>
        <input type="submit" value="Generate Triangle">
    </form>

    <?php
    function getnCr($n, $r) {
        if ($r > $n) {
            return 0;
        }

        if ($r == 0 || $r == $n) {
            return 1;
        }

        return getnCr($n - 1, $r - 1) + getnCr($n - 1, $r);
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $rows = $_POST['rows'];

        for ($i = 0; $i < $rows; $i++) {
            for ($space = 0; $space < $rows - $i; $space++) {
                echo " ";
            }
            for ($num = 0; $num <= $i; $num++) {
                echo getnCr($i, $num) . " ";
            }
            echo "<br>";
        }
    }
    ?>
</body>
</html>

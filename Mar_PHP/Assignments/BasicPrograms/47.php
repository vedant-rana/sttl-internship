<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Hollow Triangle</title>
</head>
<body>
    <h2>Hollow Triangle</h2>
    <form method="post">
        <label for="rows">Enter the Number Of rows for Hollow Triangle:</label>
        <input type="number" id="rows" name="rows" required>
        <input type="submit" value="Generate Triangle">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $rows = $_POST['rows'];
        $triangle = '';

        for ($i = 0; $i < $rows; $i++) {
            for ($space = 0; $space < $rows - $i; $space++) {
                $triangle.= "&nbsp;&nbsp;";
            }
        
            if ($i != $rows - 1) {
                for ($num = 0; $num <= $i; $num++) {
                    if ($num == 0 || $num == $i) {
                        $triangle.=  "*&nbsp;&nbsp;";
                    } else {
                        $triangle.=  "&nbsp;&nbsp;&nbsp;&nbsp;";
                    }
                }
            } else {
                for ($j = 0; $j < $rows; $j++) {
                    $triangle.=  "*&nbsp;&nbsp;";
                }
            }
            $triangle.=  "<br/>";
        }
        echo $triangle;
    }
    ?>
</body>
</html>

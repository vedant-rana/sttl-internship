<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Reverse a String</title>
</head>
<body>
    <h2>Reverse a String</h2>
    <form method="post">
        Enter a string: <input type="text" name="input_string" required>
        <input type="submit" name="submit" value="Reverse">
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $input_string = $_POST['input_string'];
        $reversed_string = strrev($input_string);

        echo "<p>Original string: $input_string</p>";
        echo "<p>Reversed string: $reversed_string</p>";
    }
    ?>
</body>
</html>

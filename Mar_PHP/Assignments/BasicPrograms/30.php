<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>String Length Calculation</title>
</head>
<body>
    <h2>String Length Calculation</h2>
    <form method="post">
        Enter a string: <input type="text" name="input_string" required>
        <input type="submit" name="submit" value="Calculate Length">
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $input_string = $_POST['input_string'];
        $length = strlen($input_string);

        echo "<p>The length of the string '$input_string' is $length characters.</p>";
    }
    ?>
</body>
</html>

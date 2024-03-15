<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Convert to Uppercase</title>
</head>
<body>
    <form method="post" action="">
        Enter a lowercase string: <input type="text" name="lowercase_string" required>
        <input type="submit" value="Convert to Uppercase">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['lowercase_string']) && $_POST['lowercase_string'] !== '') {
            $lowercase_string = $_POST['lowercase_string'];
            $uppercase_string = strtoupper($lowercase_string);
            echo "<p>The uppercase string is: $uppercase_string</p>";
        } else {
            echo "<p>Please enter a lowercase string.</p>";
        }
    }
    ?>
</body>
</html>

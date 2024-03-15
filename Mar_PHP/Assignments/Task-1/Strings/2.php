<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Convert to Lowercase</title>
</head>
<body>
    <form method="post" action="">
        Enter an uppercase string: <input type="text" name="uppercase_string" required>
        <input type="submit" value="Convert to Lowercase">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['uppercase_string']) && $_POST['uppercase_string'] !== '') {
            $uppercase_string = $_POST['uppercase_string'];
            $lowercase_string = strtolower($uppercase_string);
            echo "<p>The lowercase string is: $lowercase_string</p>";
        } else {
            echo "<p>Please enter an uppercase string.</p>";
        }
    }
    ?>
</body>
</html>

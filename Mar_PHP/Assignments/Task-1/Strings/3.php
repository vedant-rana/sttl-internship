<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Convert First Character to Uppercase</title>
</head>
<body>
    <form method="post" action="">
        Enter a string: <input type="text" name="input_string" required>
        <input type="submit" value="Convert First Character to Uppercase">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['input_string']) && $_POST['input_string'] !== '') {
            $input_string = $_POST['input_string'];
            $first_char_uppercase = ucfirst($input_string);
            echo "<p>The string with the first character in uppercase is: $first_char_uppercase</p>";
        } else {
            echo "<p>Please enter a string.</p>";
        }
    }
    ?>
</body>
</html>

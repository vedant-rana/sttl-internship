<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Remove Part of String from Beginning</title>
</head>
<body>
    <form method="post" action="">
        Enter a string: <input type="text" name="input_string" required>
        <br>
        Enter the number of characters to remove: <input type="number" name="chars_to_remove" required>
        <br>
        <input type="submit" value="Remove Part">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['input_string']) && isset($_POST['chars_to_remove']) &&
            $_POST['input_string'] !== '' && $_POST['chars_to_remove'] !== '') {
            $input_string = $_POST['input_string'];
            $chars_to_remove = $_POST['chars_to_remove'];
            
            // Remove part of the string
            if ($chars_to_remove >= 0 && $chars_to_remove <= strlen($input_string)) {
                $result_string = substr($input_string, $chars_to_remove);
                echo "<p>The modified string is: $result_string</p>";
            } else {
                echo "<p>Please enter a valid number of characters to remove.</p>";
            }
        } else {
            echo "<p>Please enter both the string and the number of characters to remove.</p>";
        }
    }
    ?>
</body>
</html>

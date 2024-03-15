<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Get Last Three Characters</title>
</head>
<body>
    <form method="post" action="">
        Enter a string: <input type="text" name="input_string" required>
        <input type="submit" value="Get Last Three Characters">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['input_string']) && $_POST['input_string'] !== '') {
            $input_string = $_POST['input_string'];
            
            // Get the last three characters of the string
            $last_three_characters = substr($input_string, -3);

            echo "<p>The last three characters of the string are: $last_three_characters</p>";
        } else {
            echo "<p>Please enter a string.</p>";
        }
    }
    ?>
</body>
</html>

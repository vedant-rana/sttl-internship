<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Print Next Character</title>
</head>
<body>
    <form method="post" action="">
        Enter a character: <input type="text" name="input_character" maxlength="1" required>
        <input type="submit" value="Print Next Character">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['input_character']) && $_POST['input_character'] !== '') {
            $input_character = $_POST['input_character'];
            
            // Print the next character
            if (strlen($input_character) == 1) {
                $next_character = chr(ord($input_character) + 1);
                echo "<p>The next character of '$input_character' is '$next_character'.</p>";
            } else {
                echo "<p>Please enter a single character.</p>";
            }
        } else {
            echo "<p>Please enter a character.</p>";
        }
    }
    ?>
</body>
</html>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Generate Random Password</title>
</head>
<body>
    <form method="post" action="">
        Enter a string to generate password from: <input type="text" name="input_string" required>
        <input type="submit" value="Generate Password">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['input_string']) && $_POST['input_string'] !== '') {
            $input_string = $_POST['input_string'];
            
            // Generate random password
            $password_length = 8; // Change the length of the password as needed
            $password = '';
            $string_length = strlen($input_string);

            for ($i = 0; $i < $password_length; $i++) {
                $random_character = $input_string[rand(0, $string_length - 1)];
                $password .= $random_character;
            }

            echo "<p>Generated Password: $password</p>";
        } else {
            echo "<p>Please enter a string.</p>";
        }
    }
    ?>
</body>
</html>

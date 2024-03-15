<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Replace First 'the' with 'best'</title>
</head>
<body>
    <form method="post" action="">
        Enter a string: <input type="text" name="input_string" required>
        <input type="submit" value="Replace First 'the' with 'best'">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['input_string']) && $_POST['input_string'] !== '') {
            $input_string = $_POST['input_string'];
            
            // Replace the first occurrence of 'the' with 'best'
            $result_string = preg_replace('/\bthe\b/', 'best', $input_string, 1);

            echo "<p>The modified string is: $result_string</p>";
        } else {
            echo "<p>Please enter a string.</p>";
        }
    }
    ?>
</body>
</html>

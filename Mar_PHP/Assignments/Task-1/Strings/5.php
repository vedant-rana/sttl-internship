<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Split String by Space</title>
</head>
<body>
    <form method="post" action="">
        Enter a string: <input type="text" name="input_string" required>
        <input type="submit" value="Split String">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Check if the input is set and not empty
        if (isset($_POST['input_string']) && $_POST['input_string'] !== '') {
            $input_string = $_POST['input_string'];
            $words_array = explode(' ', $input_string);
            echo "<p>The string split by space:</p>";
            echo "<ul>";
            foreach ($words_array as $word) {
                echo "<li>$word</li>";
            }
            echo "</ul>";
        } else {
            echo "<p>Please enter a string.</p>";
        }
    }
    ?>
</body>
</html>

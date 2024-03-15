<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Count 't' Characters</title>
</head>
<body>

<form method="post" action="">
    Enter text: <input type="text" name="text" required>
    <input type="submit" value="Count 't' Characters">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if the input is set and not empty
    if (isset($_POST['text']) && $_POST['text'] !== '') {
        $text = $_POST['text'];
        
        // Count 't' characters
        $countT = substr_count(strtolower($text), 't');

        echo "The letter 't' appears $countT times in the text.";
    } else {
        echo "Please enter some text.";
    }
}
?>

</body>
</html>

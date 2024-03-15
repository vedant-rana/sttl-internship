<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>ASCII Value of Character</title>
</head>
<body>
    <h2>Find ASCII Value of a Character</h2>
    <form method="post">
        Enter a character: <input type="text" name="character" maxlength="1" required>
        <input type="submit" name="submit" value="Find ASCII Value">
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $character = $_POST['character'];
        if (strlen($character) == 1) { 
            $asciiValue = ord($character); 
            echo "<p>ASCII value of '$character' is: $asciiValue</p>";
        } else {
            echo "<p>Please enter a single character.</p>";
        }
    }
    ?>
</body>
</html>

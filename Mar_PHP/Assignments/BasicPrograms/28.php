<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Count Vowels and Consonants</title>
</head>
<body>
    <h2>Count Vowels and Consonants in a String</h2>
    <form method="post">
        Enter a string: <input type="text" name="input_string" required>
        <input type="submit" name="submit" value="Count">
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $input_string = strtolower($_POST['input_string']); 
        
        $vowel_count = 0;
        $consonant_count = 0;

        
        $vowels = ['a', 'e', 'i', 'o', 'u'];

        
        for ($i = 0; $i < strlen($input_string); $i++) {
            $char = $input_string[$i];
            if (ctype_alpha($char)) { 
                if (in_array($char, $vowels)) {
                    $vowel_count++;
                } else {
                    $consonant_count++;
                }
            }
        }

        echo "<p>Number of vowels: $vowel_count</p>";
        echo "<p>Number of consonants: $consonant_count</p>";
    }
    ?>
</body>
</html>

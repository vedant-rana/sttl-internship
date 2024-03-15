<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Anagram Checker</title>
</head>
<body>
    <h2>Anagram Checker</h2>
    <form method="post">
        Enter first string: <input type="text" name="str1" required>
        <br><br>
        Enter second string: <input type="text" name="str2" required>
        <br><br>
        <input type="submit" name="submit" value="Check Anagram">
    </form>

    <?php
    function isAnagram($str1, $str2) {
        
        $str1 = strtolower(str_replace(' ', '', $str1));
        $str2 = strtolower(str_replace(' ', '', $str2));

        
        $sorted_str1 = str_split($str1);
        $sorted_str2 = str_split($str2);
        sort($sorted_str1);
        sort($sorted_str2);

        
        return $sorted_str1 == $sorted_str2;
    }

    if (isset($_POST['submit'])) {
        $str1 = $_POST['str1'];
        $str2 = $_POST['str2'];

        if (isAnagram($str1, $str2)) {
            echo "<p>'$str1' and '$str2' are anagrams.</p>";
        } else {
            echo "<p>'$str1' and '$str2' are not anagrams.</p>";
        }
    }
    ?>
</body>
</html>


<!DOCTYPE html>
<html>
<head>
    <title>Word to Digit Conversion</title>
</head>
<body>

<h2>Word to Digit Conversion</h2>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    <label for="word">Enter a word:</label>
    <input type="text" id="word" name="word">
    <input type="submit" value="Convert">
</form>

<?php

function wordToDigit($word) {
    $word_to_digit = array(
        'zero' => '0',
        'one' => '1',
        'two' => '2',
        'three' => '3',
        'four' => '4',
        'five' => '5',
        'six' => '6',
        'seven' => '7',
        'eight' => '8',
        'nine' => '9'
    );


    $word_lower = strtolower($word);
    if (array_key_exists($word_lower, $word_to_digit)) {
        return $word_to_digit[$word_lower];
    } else {
        return "Not a valid word.";
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
   
    $word = $_POST['word'];

    $result = wordToDigit($word);


    echo "The digit word for \"$word\" is: $result";
}
?>

</body>
</html>

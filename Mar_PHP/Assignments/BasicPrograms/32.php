<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Word Count in a Sentence</title>
</head>
<body>
    <h2>Word Count in a Sentence</h2>
    <form method="post">
        Enter a sentence: <input type="text" name="sentence" required>
        <input type="submit" name="submit" value="Count Words">
    </form>

    <?php
    if (isset($_POST['submit'])) {
        $sentence = $_POST['sentence'];
        $word_count = str_word_count($sentence);

        echo "<p>Number of words in the sentence: $word_count</p>";
    }
    ?>
</body>
</html>

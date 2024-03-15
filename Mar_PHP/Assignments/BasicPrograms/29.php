<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>String Concatenation</title>
</head>
<body>
    <h2>String Concatenation</h2>
    <?php
    
    $string1 = "Hello";
    $string2 = "world";
    $result1 = $string1 . " " . $string2;

    echo "<p>Result using . operator: $result1</p>";

    
    $result2 = "Hello";
    $result2 .= " ";
    $result2 .= "world";

    echo "<p>Result using .= operator: $result2</p>";
    ?>
</body>
</html>

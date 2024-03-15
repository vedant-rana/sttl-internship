<?php
function insertString($originalString, $insertString, $position) {
    $part1 = substr($originalString, 0, $position);
    $part2 = substr($originalString, $position);
    $newString = $part1 . $insertString . $part2;

    return $newString;
}

$originalString = "Hello, world!";
$insertString = "India ";
$position = 6;

$result = insertString($originalString, $insertString, $position);
echo "Original string: $originalString<br>";
echo "String to insert: $insertString<br>";
echo "Position: $position<br>";
echo "Result after insertion: $result";
?>

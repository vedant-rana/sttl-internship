<!DOCTYPE html>
<html>
<head>
    <title>Display Array and Sum of Diagonal Elements</title>
</head>
<body>

<?php
$arr = array(
    array(12, 13, 14),
    array(15, 16, 17),
    array(18, 19, 20)
);
$sum = 0;

// Display array
echo "<p>Array:</p>";
echo "<table border='1'>";
foreach ($arr as $row) {
    echo "<tr>";
    foreach ($row as $value) {
        echo "<td>$value</td>";
    }
    echo "</tr>";
}
echo "</table>";

// Calculate and display sum of diagonal elements
for ($i = 0; $i < count($arr); $i++) {
    for ($j = 0; $j < count($arr[$i]); $j++) {
        if ($i == $j) {
            $sum += $arr[$i][$j];
        }
    }
}

echo "<p>Sum of diagonal elements: $sum</p>";
?>

</body>
</html>

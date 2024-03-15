<?php
$tableSize = 5;

echo "<h2>Multiplication Table up to $tableSize x $tableSize:</h2>";
echo "<table border='1'>";
for ($i = 1; $i <= $tableSize; $i++) {
    echo "<tr>";
    for ($j = 1; $j <= $tableSize; $j++) {
        $product = $i * $j;
        echo "<td>$product</td>";
    }
    echo "</tr>";
}
echo "</table>";
?>

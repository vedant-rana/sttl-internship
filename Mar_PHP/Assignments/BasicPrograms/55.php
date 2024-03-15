<!DOCTYPE html>
<html>
<head>
    <title>Check Magic Square</title>
</head>
<body>

<?php
function isMagicSquare($matrix) {
    $n = count($matrix);
    $magicSum = 0;

    // Calculate magic sum
    foreach ($matrix[0] as $value) {
        $magicSum += $value;
    }

    // Check row sums
    for ($i = 0; $i < $n; $i++) {
        $rowSum = 0;
        for ($j = 0; $j < $n; $j++) {
            $rowSum += $matrix[$i][$j];
        }
        if ($rowSum != $magicSum) {
            return false;
        }
    }

    // Check column sums
    for ($j = 0; $j < $n; $j++) {
        $colSum = 0;
        for ($i = 0; $i < $n; $i++) {
            $colSum += $matrix[$i][$j];
        }
        if ($colSum != $magicSum) {
            return false;
        }
    }

    // Check diagonal sums
    $diagSum = 0;
    for ($i = 0; $i < $n; $i++) {
        $diagSum += $matrix[$i][$i];
    }
    if ($diagSum != $magicSum) {
        return false;
    }

    $diagSum = 0;
    for ($i = 0; $i < $n; $i++) {
        $diagSum += $matrix[$i][$n - $i - 1];
    }
    if ($diagSum != $magicSum) {
        return false;
    }

    return true;
}

$matrix = array(
    array(2, 7, 6),
    array(9, 5, 1),
    array(4, 3, 8)
);

// Display matrix
echo "<p>Matrix:</p>";
echo "<table border='1'>";
foreach ($matrix as $row) {
    echo "<tr>";
    foreach ($row as $value) {
        echo "<td>$value</td>";
    }
    echo "</tr>";
}
echo "</table>";

// Check if it's a magic square
if (isMagicSquare($matrix)) {
    echo "<p>The given matrix is a magic square.</p>";
} else {
    echo "<p>The given matrix is not a magic square.</p>";
}
?>

</body>
</html>

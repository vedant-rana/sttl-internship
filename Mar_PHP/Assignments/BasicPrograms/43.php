<?php
function transposeMatrix($matrix) {
    $rows = count($matrix);
    $cols = count($matrix[0]);

    $transposedMatrix = [];

    for ($i = 0; $i < $cols; $i++) {
        for ($j = 0; $j < $rows; $j++) {
            $transposedMatrix[$i][$j] = $matrix[$j][$i];
        }
    }

    return $transposedMatrix;
}


$matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

echo "Original Matrix:<br>";
foreach ($matrix as $row) {
    echo implode(" ", $row) . "<br>";
}

$transposedMatrix = transposeMatrix($matrix);

echo "<br>Transposed Matrix:<br>";
foreach ($transposedMatrix as $row) {
    echo implode(" ", $row) . "<br>";
}
?>

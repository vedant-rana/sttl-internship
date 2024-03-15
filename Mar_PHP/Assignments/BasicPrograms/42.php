<?php
function matrixMultiplication($matrix1, $matrix2) {
    $rows1 = count($matrix1);
    $cols1 = count($matrix1[0]);
    $rows2 = count($matrix2);
    $cols2 = count($matrix2[0]);

    if ($cols1 != $rows2) {
        
        return "Number of columns in Matrix 1 must be equal to number of rows in Matrix 2 for multiplication.";
    }

    $result = [];

    for ($i = 0; $i < $rows1; $i++) {
        for ($j = 0; $j < $cols2; $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < $cols1; $k++) {
                $result[$i][$j] += $matrix1[$i][$k] * $matrix2[$k][$j];
            }
        }
    }

    return $result;
}


$matrix1 = [[1, 2], [3, 4]];
$matrix2 = [[5, 6], [7, 8]];

echo "Matrix 1:<br>";
foreach ($matrix1 as $row) {
    echo implode(" ", $row) . "<br>";
}

echo "<br>Matrix 2:<br>";
foreach ($matrix2 as $row) {
    echo implode(" ", $row) . "<br>";
}

$result = matrixMultiplication($matrix1, $matrix2);

if (is_array($result)) {
    echo "<br>Matrix Multiplication Result:<br>";
    foreach ($result as $row) {
        echo implode(" ", $row) . "<br>";
}
} else {
    echo "<br>" . $result;
}
?>

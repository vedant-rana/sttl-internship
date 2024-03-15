<?php
function isLowerTriangular($matrix) {
    $n = count($matrix);

    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $n; $j++) {
            
            if ($i < $j && $matrix[$i][$j] != 0) {
                return false;
            }
        }
    }

    return true;
}


$matrix1 = [
    [1, 0, 0],
    [2, 3, 0],
    [4, 5, 6]
];

$matrix2 = [
    [1, 0, 1],
    [0, 3, 0],
    [0, 0, 6]
];

echo "Matrix 1:<br>";
foreach ($matrix1 as $row) {
    echo implode(" ", $row) . "<br>";
}

echo "<br>Matrix 2:<br>";
foreach ($matrix2 as $row) {
    echo implode(" ", $row) . "<br>";
}

if (isLowerTriangular($matrix1)) {
    echo "<br>Matrix 1 is a lower triangular matrix.";
} else {
    echo "<br>Matrix 1 is not a lower triangular matrix.";
}

if (isLowerTriangular($matrix2)) {
    echo "<br>Matrix 2 is a lower triangular matrix.";
} else {
    echo "<br>Matrix 2 is not a lower triangular matrix.";
}
?>

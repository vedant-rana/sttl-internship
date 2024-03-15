<?php
function isUpperTriangular($matrix) {
    $n = count($matrix);

    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $n; $j++) {
            
            if ($i > $j && $matrix[$i][$j] != 0) {
                return false;
            }
        }
    }

    return true;
}


$matrix1 = [
    [1, 2, 3],
    [0, 4, 5],
    [0, 0, 6]
];

$matrix2 = [
    [1, 2, 3],
    [0, 4, 5],
    [7, 0, 6]
];

echo "Matrix 1:<br>";
foreach ($matrix1 as $row) {
    echo implode(" ", $row) . "<br>";
}

echo "<br>Matrix 2:<br>";
foreach ($matrix2 as $row) {
    echo implode(" ", $row) . "<br>";
}

if (isUpperTriangular($matrix1)) {
    echo "<br>Matrix 1 is an upper triangular matrix.";
} else {
    echo "<br>Matrix 1 is not an upper triangular matrix.";
}

if (isUpperTriangular($matrix2)) {
    echo "<br>Matrix 2 is an upper triangular matrix.";
} else {
    echo "<br>Matrix 2 is not an upper triangular matrix.";
}
?>

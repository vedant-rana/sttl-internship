<?php
function matrixSubtraction($matrix1, $matrix2) {
    $result = [];
    $rows = count($matrix1);
    $cols = count($matrix1[0]);

    if ($rows != count($matrix2) || $cols != count($matrix2[0])) {
        
        return "Matrices must have the same dimensions for subtraction.";
    }

    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $result[$i][$j] = $matrix1[$i][$j] - $matrix2[$i][$j];
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

$result = matrixSubtraction($matrix1, $matrix2);

if (is_array($result)) {
    echo "<br>Matrix Subtraction Result:<br>";
    foreach ($result as $row) {
        echo implode(" ", $row) . "<br>";
}
} else {
    echo "<br>" . $result;
}
?>

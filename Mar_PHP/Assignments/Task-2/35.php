<?php

function count_same($string1, $string2) {
    $count = 0;
    $length1 = strlen($string1);
    $length2 = strlen($string2);
    $min_length = min($length1, $length2);

    
    for ($i = 0; $i < $min_length - 1; $i++) {
        $substring1 = substr($string1, $i, 2);
        $substring2 = substr($string2, $i, 2);
        if ($substring1 === $substring2) {
            $count++;
        }
    }
    return $count;
}


$string1 = "abcdefgh";
$string2 = "ijklmnopq";


$result = count_same($string1, $string2);
echo $result;
?>

<?php

function check($array) {
    $length = count($array);
    for ($i = 0; $i < $length - 2; $i++) {
        if ($array[$i] === 1 && $array[$i + 1] === 2 && $array[$i + 2] === 3) {
            return true;
        }
    }
    return false;
}


$arrays = array(
    array(1, 2, 3, 4, 5),
    array(4, 5, 1, 2, 3),
    array(1, 2, 4, 3, 5),
    array(7, 8, 9, 10)
);


foreach ($arrays as $key => $array) {
    $result = check($array);
    if ($result) {
        echo "True";
    } else {
        echo "False";
    }
}
?>

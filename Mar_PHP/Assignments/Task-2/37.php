<?php

function count_5($array) {
    $count = 0;
    $length = count($array);

    for ($i = 0; $i < $length - 1; $i++) {
        if (($array[$i] === 5 && $array[$i + 1] === 5) || ($array[$i] === 5 && $array[$i + 1] === 6)) {
            $count++;
        }
    }

    return $count;
}


$arrays = array(
    array(1, 5, 5, 2, 6, 5),
    array(5, 6, 6, 5, 5, 5),
    array(5, 5, 5, 5, 5),
    array(6, 6, 6, 6)
);


foreach ($arrays as $key => $array) {
    $result = count_5($array);
   echo $result;
}
?>

<?php

function has_triple($array) {
    $length = count($array);
    
    for ($i = 0; $i < $length - 2; $i++) {
        
        if ($array[$i] === $array[$i + 1] && $array[$i] === $array[$i + 2]) {
            return true; 
        }
    }
    return false; 
}


$arrays = array(
    array(1, 2, 2, 2, 3, 4),
    array(1, 2, 2, 2, 3, 3, 3),
    array(1, 2, 3, 3, 3, 4, 5),
    array(1, 1, 1, 1)
);


foreach ($arrays as $key => $array) {
    $result = has_triple($array);
    echo "Array ".($key + 1).": Triple ".($result ? "present" : "not present") . PHP_EOL;
}
?>

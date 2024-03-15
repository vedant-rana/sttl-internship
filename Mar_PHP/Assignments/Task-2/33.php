<?php

function check($array, $element) {
    
    $first_four = array_slice($array, 0, 4);
    
    return in_array($element, $first_four);
}


$inputs = array(
    array(1, 2, 9, 3),
    array(1, 2, 3, 4, 5, 6),
    array(1, 2, 2, 3)
);

$elements_to_check = array(3, 2, 9);


foreach ($inputs as $key => $input) {
    $element = $elements_to_check[$key];
    $result = check($input, $element);
    echo $result;
}
?>

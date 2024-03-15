<?php

function ArrayResult($input)
{
    $len1 = count($input[0]);
    $len2 = count($input[1]);
    if($input[0][0] == $input[1][0] || $input[0][$len1-1] == $input[1][$len2-1]){
       return true;
    }
    return  false;
}


$inputs = [
    [[10, 20, 40, 50], [10, 20, 40, 50] ],
    [[10, 20, 40, 10], [10, 20, 40, 5] ],
    [[12, 24, 35, 55], [1, 20, 40, 5] ]
];


foreach ($inputs as $input) {
    var_dump(ArrayResult($input));
    echo "<br/>";
}

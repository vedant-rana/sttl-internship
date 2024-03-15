<?php

function ArrayResult($input)
{
    if($input[0] == $input[count($input)-1]){
       return true;
    }
    return  false;
}


$inputs = [
    [10, 20, 40, 50 ],
    [10, 20, 40, 10 ],
    [12, 24, 35, 55 ]
];


foreach ($inputs as $input) {
    var_dump(ArrayResult($input));
    echo "<br/>";
}

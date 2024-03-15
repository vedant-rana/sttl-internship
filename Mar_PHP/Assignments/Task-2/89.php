<?php

function ArrayResult($input)
{
    $sum = 0;
    for($i=0; $i<count($input);$i++){
        $sum+=$input[$i];
    }
    return $sum;
}


$inputs = [
    [10, 20, 30, 40, 50 ],
    [10, 20, -30, -40, 50 ]
];


foreach ($inputs as $input) {
    
    echo ArrayResult($input)."<br/>";
}

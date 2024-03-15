<?php

function isFisrLastSame($input)
{
    if(substr($input, 0,2) == substr($input, -2)){
        return true;
    }
    return false;
}


$inputs = [
    "abab",
    "abcdef",
    "xyzsderxy"
];


foreach ($inputs as $input) {
    var_dump(isFisrLastSame($input));
    echo "<br/>";
}

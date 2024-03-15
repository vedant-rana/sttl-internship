<?php

function contains15or20($arrs)
{
    if(in_array(15, $arrs) || in_array(20, $arrs)){
        return true;
    }
    return false;
}


$inputArray = [
    [12,20],
    [14,15],
    [11,21]
];



foreach ($inputArray as $input) {
    var_dump(contains15or20($input));
    echo "<br/>";
}

?>
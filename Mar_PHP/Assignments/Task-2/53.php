<?php
function test($x, $y){
    $sum = $x+$y;
    $strx = (string)$x;
    $stry = (string)$y;
    $strsum = (string)$sum;

    if(strlen($strx) == strlen($stry) && strlen($stry) == strlen($strsum)){
        echo $sum;
    }else{
        echo $x > $y ? $x : $y ;
        }
}

test(4,5);
echo "<br/>";
test(7,4);
echo "<br/>";
test(10,10);

?>
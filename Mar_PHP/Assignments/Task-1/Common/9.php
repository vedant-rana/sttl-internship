<?php
function testNumber($number) {
    $result = ($number > 30) ? "Greater than 30" :
              (($number > 20) ? "Greater than 20" :
              (($number > 10) ? "Greater than 10" :
              "Not greater than 10"));

    return $result;
}


echo testNumber(35) . "<br>"; 
echo testNumber(25) . "<br>"; 
echo testNumber(15) . "<br>"; 
echo testNumber(5) . "<br>";  
?>
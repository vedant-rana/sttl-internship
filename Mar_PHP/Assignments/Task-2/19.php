<?php

function nearest($num1, $num2) {
    $diff1 = abs(100 - $num1);
    $diff2 = abs(100 - $num2);
    
    if ($diff1 < $diff2) {
        return $num1;
    } elseif ($diff2 < $diff1) {
        return $num2;
    } else {
        return 0; 
    }
}


if(isset($_POST['num1']) && isset($_POST['num2'])) {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $result = nearest($num1, $num2);
    if ($result == 0) {
        echo "The two numbers are equal.";
    } else {
        echo "The number nearest to 100 is: $result";
    }
}
?>


<form method="post" action="">
    First Number: <input type="number" name="num1"><br>
    Second Number: <input type="number" name="num2"><br>
    <input type="submit" value="Check">
    </form>

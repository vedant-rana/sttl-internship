<?php

function check($num1, $num2) {
    $range1 = ($num1 >= 40 && $num1 <= 50) && ($num2 >= 40 && $num2 <= 50);
    $range2 = ($num1 >= 50 && $num1 <= 60) && ($num2 >= 50 && $num2 <= 60);
    
    if ($range1 || $range2) {
        return true;
    } else {
        return false;
    }
}


if(isset($_POST['num1']) && isset($_POST['num2'])) {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $result = check($num1, $num2);
    if ($result) {
        echo "Yes.";
    } else {
        echo "No.";
    }
}
?>

<form method="post" action="">
    First Number: <input type="number" name="num1"><br>
    Second Number: <input type="number" name="num2"><br>
    <input type="submit" value="Check">
    </form>

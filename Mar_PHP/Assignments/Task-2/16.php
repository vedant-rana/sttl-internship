<?php

function check($num1, $num2) {
    if (($num1 >= 20 && $num1 <= 50) || ($num2 >= 20 && $num2 <= 50)) {
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
        echo "At least one number is in the range 20 to 50 inclusive.";
    } else {
        echo "Neither of the numbers are in the range 20 to 50 inclusive.";
    }
}
?>


<form method="post" action="">
    First Number: <input type="number" name="num1"><br>
    Second Number: <input type="number" name="num2"><br>
    <input type="submit" value="Check">
</form>

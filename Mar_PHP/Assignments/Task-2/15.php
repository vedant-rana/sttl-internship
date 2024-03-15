<?php

function check_range($num1, $num2, $num3) {
    if (($num1 >= 20 && $num1 <= 50) || ($num2 >= 20 && $num2 <= 50) || ($num3 >= 20 && $num3 <= 50)) {
        return true;
    } else {
        return false;
    }
}

if(isset($_POST['num1']) && isset($_POST['num2']) && isset($_POST['num3'])) {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $num3 = $_POST['num3'];
    $result = check_range($num1, $num2, $num3);
    if ($result) {
        echo "At least one number is in the range 20 to 50 inclusive.";
    } else {
        echo "None of the numbers are in the range 20 to 50 inclusive.";
    }
}
?>
<form method="post" action="">
    First Number: <input type="number" name="num1"><br>
    Second Number: <input type="number" name="num2"><br>
    Third Number: <input type="number" name="num3"><br>
    <input type="submit" value="Check">
</form>

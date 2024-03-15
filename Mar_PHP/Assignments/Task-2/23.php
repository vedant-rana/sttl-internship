<?php

function digit($num1, $num2) {
    $last_digit_num1 = $num1 % 10;
    $last_digit_num2 = $num2 % 10;
    return $last_digit_num1 === $last_digit_num2;
}


if(isset($_POST['num1']) && isset($_POST['num2'])) {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $result = digit($num1, $num2);
    if ($result) {
        echo "True";
    } else {
        echo "False";
    }
}
?>

<form method="post" action="">
    First Number: <input type="number" name="num1"><br>
    Second Number: <input type="number" name="num2"><br>
    <input type="submit" value="Check">
    </form>

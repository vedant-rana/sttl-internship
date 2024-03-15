<?php

function find($num1, $num2, $num3) {
    $max = $num1;
    if ($num2 > $max) {
        $max = $num2;
    }
    if ($num3 > $max) {
        $max = $num3;
    }
    return $max;
}


if(isset($_POST['num1']) && isset($_POST['num2']) && isset($_POST['num3'])) {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $num3 = $_POST['num3'];
    $result = find($num1, $num2, $num3);
    echo $result;
}
?>


<form method="post" action="">
    First Number: <input type="number" name="num1"><br>
    Second Number: <input type="number" name="num2"><br>
    Third Number: <input type="number" name="num3"><br>
    <input type="submit" value="Find Largest">
    </form>

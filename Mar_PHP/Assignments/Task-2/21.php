<?php

function find_larger_in_range($num1, $num2) {
    if (($num1 >= 20 && $num1 <= 30) && ($num2 >= 20 && $num2 <= 30)) {
        return max($num1, $num2);
    } elseif ($num1 >= 20 && $num1 <= 30) {
        return $num1;
    } elseif ($num2 >= 20 && $num2 <= 30) {
        return $num2;
    } else {
        return 0;
    }
}


if(isset($_POST['num1']) && isset($_POST['num2'])) {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $result = find_larger_in_range($num1, $num2);
  
        echo $result;
    
}
?>

<form method="post" action="">
    First Number: <input type="number" name="num1"><br>
    Second Number: <input type="number" name="num2"><br>
    <input type="submit" value="Find Larger in Range">
    </form>

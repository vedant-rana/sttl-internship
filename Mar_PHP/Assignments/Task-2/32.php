<?php

function is_number_present($array, $number) {
    return in_array($number, $array);
}


$array = array(1, 2, 3, 4, 5);


if(isset($_POST['number'])) {
    $number = $_POST['number'];
    $result = is_number_present($array, $number);
    if ($result) {
        echo "True";
    } else {
        echo "False";
    }
}
?>

<form method="post" action="">
    Number to Check: <input type="number" name="number"><br>
    <input type="submit" value="Check">
</form>

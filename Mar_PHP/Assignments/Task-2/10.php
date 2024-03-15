<?php

function check_multiple($number) {
    if ($number <= 0) {
        return "Please enter a positive number.";
    } elseif ($number % 3 == 0 || $number % 7 == 0) {
        return "$number is a multiple of 3 or 7.";
    } else {
        return "$number is not a multiple of 3 or 7.";
    }
}

if(isset($_POST['number'])) {
    $number = $_POST['number'];
    $result = check_multiple($number);
    echo $result;
}
?>
<form method="post" action="">
    Enter a positive number: <input type="number" name="number"><br>
    <input type="submit" value="Check">
</form>

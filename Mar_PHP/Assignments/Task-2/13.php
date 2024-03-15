<?php

function check_temperatures($temp1, $temp2) {
    if ($temp1 < 0 && $temp2 > 100) {
        return "The first temperature is less than 0 and the second temperature is greater than 100.";
    } elseif ($temp1 < 0) {
        return "Only the first temperature is less than 0.";
    } elseif ($temp2 > 100) {
        return "Only the second temperature is greater than 100.";
    } else {
        return "No.";
    }
}


if(isset($_POST['temp1']) && isset($_POST['temp2'])) {
    $temp1 = $_POST['temp1'];
    $temp2 = $_POST['temp2'];
    $result = check_temperatures($temp1, $temp2);
    echo $result;
}
?>

<form method="post" action="">
    First Temperature: <input type="number" name="temp1"><br>
    Second Temperature: <input type="number" name="temp2"><br>
    <input type="submit" value="Check">
</form>

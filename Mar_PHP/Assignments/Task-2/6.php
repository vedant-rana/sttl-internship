<?php

function remove_char($input_string, $position) {
    if (is_numeric($position) && $position >= 0 && $position < strlen($input_string)) {
        return substr_replace($input_string, '', $position, 1);
    } elseif (is_numeric($position) && $position < 0) {
        return "Position cannot be negative";
    } elseif (is_numeric($position) && $position >= strlen($input_string)) {
        return "Position exceeds string length";
    } else {
        return "Invalid position input";
    }
}

if(isset($_POST['input_string']) && isset($_POST['position'])) {
    $input_string = $_POST['input_string'];
    $position = $_POST['position'];
    $result = remove_char($input_string, $position);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    Position: <input type="text" name="position"><br>
    <input type="submit" value="Submit">
</form>

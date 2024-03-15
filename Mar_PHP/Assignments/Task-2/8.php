<?php

function copy_front_chars($input_string) {
    if (strlen($input_string) < 2) {
        return $input_string; 
    } else {
        $front_chars = substr($input_string, 0, 2);
        return str_repeat($front_chars, 4);
    }
}

if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = copy_front_chars($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Submit">
</form>

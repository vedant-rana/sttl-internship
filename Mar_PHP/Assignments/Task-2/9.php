<?php

function add_last_char_to_front_and_back($input_string) {
    $length = strlen($input_string);
    if ($length < 1) {
        return "String length should be at least 1";
    } else {
        $last_char = $input_string[$length - 1];
        return $last_char . $input_string . $last_char;
    }
}

if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = add_last_char_to_front_and_back($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Submit">
</form>

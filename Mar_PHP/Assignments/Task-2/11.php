<?php

function add($input_string) {
    $first_three_chars = substr($input_string, 0, 3);
    return $first_three_chars . $input_string . $first_three_chars;
}

if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = add($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Submit">
</form>

<?php

function convert($input_string) {
    $length = strlen($input_string);
    if ($length < 3) {
        return strtoupper($input_string);
    } else {
        $last_three = substr($input_string, -3);
        $rest = substr($input_string, 0, $length - 3);
        return $rest . strtoupper($last_three);
    }
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = convert($input_string);
    echo $result;
}
?>


<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Convert">
<</form>
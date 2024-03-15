<?php

function add_if_to_string($input_string) {
    if (substr($input_string, 0, 2) === "if") {
        return $input_string;
    } else {
        return "if " . $input_string;
    }
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = add_if_to_string($input_string);
    echo $result;
}
?>


<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Submit">
</form>

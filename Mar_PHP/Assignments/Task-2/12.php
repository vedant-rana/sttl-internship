<?php

function starts_with($input_string) {
    if (substr($input_string, 0, 2) === "C#") {
        return "The string starts with 'C#'.";
    } else {
        return "The string does not start with 'C#'.";
    }
}

if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = starts_with($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Check">
</form>

<?php

function remove($input_string) {
    if (substr($input_string, 1, 2) === "yt") {
        return substr_replace($input_string, '', 1, 2);
    } else {
        return $input_string;
    }
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = remove
    ($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Submit">
    </form>

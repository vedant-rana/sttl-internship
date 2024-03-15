<?php

function check($input_string) {
    $count = substr_count($input_string, 'z');
    return $count >= 2 && $count <= 4;
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = check($input_string);
    if ($result) {
        echo "True";
    } else {
        echo "False";
    }
}
?>


<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Check">
    </form>

<?php

function createnewstring($input_string) {
    $new_string = "";
    $length = strlen($input_string);
    for ($i = 0; $i < $length; $i += 2) {
        $new_string .= $input_string[$i];
    }
    return $new_string;
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = createnewstring($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Create New String">
</form>

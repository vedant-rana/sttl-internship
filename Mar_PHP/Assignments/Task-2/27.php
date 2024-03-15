<?php

function count_aa($input_string) {
    
    $input_string = str_replace("aaa", "aa", $input_string);
    
    $count = substr_count($input_string, "aa");
    return $count;
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = count_aa($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Count">
</form>

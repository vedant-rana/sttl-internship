<?php
function swap_first_and_last($input_string) {
    $length = strlen($input_string);
    if ($length < 2) {
        return $input_string; 
    } else {
        $first_char = $input_string[0];
        $last_char = $input_string[$length - 1];
        $input_string[0] = $last_char;
        $input_string[$length - 1] = $first_char;
        return $input_string;
    }
}

if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = swap_first_and_last($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Submit">
</form>

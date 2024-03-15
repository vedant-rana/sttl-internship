<?php

function create($input_string, $n) {
    return str_repeat($input_string, $n);
}


if(isset($_POST['input_string']) && isset($_POST['num_copies'])) {
    $input_string = $_POST['input_string'];
    $num_copies = $_POST['num_copies'];
    $result = create($input_string, $num_copies);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    Number of Copies: <input type="number" name="num_copies"><br>
    <input type="submit" value="Create Copies">
</form>

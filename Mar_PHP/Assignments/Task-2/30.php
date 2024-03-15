
<?php

function create($input_string) {
    $pattern_string = "";
    $length = strlen($input_string);
    for ($i = 0; $i < $length; $i++) {
        $pattern_string .= substr($input_string, 0, $i + 1);
    }
    return $pattern_string;
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = create($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string" value="abcd"><br>
    <input type="submit" value="Create Pattern String">
</form>

<?php

function create($input_string) {
    $new_string = "";
    $length = strlen($input_string);
    
    for ($i = 0; $i < $length; $i += 4) {
        
        $new_string .= $input_string[$i];
        if ($i + 1 < $length) {
            $new_string .= $input_string[$i + 1];
        }
    }
    return $new_string;
}


if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = create($input_string);
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Create New String">
</form>

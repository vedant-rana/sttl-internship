<?php

function check($input_string) {
    $first_a_index = strpos($input_string, "a");
    if ($first_a_index !== false) {
        
        if ($input_string[$first_a_index + 1] === "a") {
            return true;
        }
    }
    return false;
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

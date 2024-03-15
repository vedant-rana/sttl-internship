<?php
function count_substring_occurrences($input_string) {
    $count = 0;
    $length = strlen($input_string);
    
    if ($length < 2) {
        return $count;
    }
    
    $end_substring = substr($input_string, -2);
    
    for ($i = 0; $i < $length - 2; $i++) {
        $substring = substr($input_string, $i, 2);
        if ($substring === $end_substring) {
            $count++;
        }
    }
    
    return $count;
}

if(isset($_POST['input_string'])) {
    $input_string = $_POST['input_string'];
    $result = count_substring_occurrences($input_string); 
    echo $result;
}
?>

<form method="post" action="">
    Input String: <input type="text" name="input_string"><br>
    <input type="submit" value="Count Last Substring">
</form>

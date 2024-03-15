<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    $input_string = $_POST["input_string"];
    $num_copies = $_POST["num_copies"];

    
    function create_new_string($input_string, $num_copies) {
        $first_three_chars = substr($input_string, 0, 3);
        if (strlen($input_string) < 3) {
            return str_repeat($input_string, $num_copies);
        } else {
            return str_repeat($first_three_chars, $num_copies);
        }
    }
    
    $result = create_new_string($input_string, $num_copies);
    echo "Result: $result";
}

?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Input String: <input type="text" name="input_string"><br><br>
        Number of Copies: <input type="number" name="num_copies"><br><br>
        <input type="submit" value="Create New String">
</form>


<!DOCTYPE html>
<html>
<head>
   
</head>
<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter a string: <input type="text" name="input_string">
        <input type="submit" name="submit" value="Check">
    </form>

    <?php
    
    function checkFizzBuzz($input_string) {
        $result = $input_string;

        $starts_with_f = substr($input_string, 0, 1) === "F";
        $ends_with_b = substr($input_string, -1) === "B";

        if ($starts_with_f && $ends_with_b) {
            $result = "FizzBuzz";
        } elseif ($starts_with_f) {
            $result = "Fizz";
        } elseif ($ends_with_b) {
            $result = "Buzz";
        }

        return $result;
    }

    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        if (isset($_POST["input_string"])) {
            $input_string = $_POST["input_string"];
            echo "Input string: $input_string <br>";
            echo "Result: " . checkFizzBuzz($input_string);
        } else {
            echo "Please enter a string.";
        }
    }
    ?>
</body>
</html>

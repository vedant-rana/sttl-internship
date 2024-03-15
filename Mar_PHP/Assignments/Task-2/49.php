<!DOCTYPE html>
<html>
<head></head>
<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter integers separated by comma: <input type="text" name="numbers">
        <input type="submit" name="submit" value="Check">
    </form>

    <?php
    
    function checkRightmostDigit($numbers) {
        $nums = explode(',', $numbers);

        $rightmost_digits = array();
        foreach ($nums as $num) {
            $rightmost_digits[] = intval(substr($num, -1));
        }

        return count(array_unique($rightmost_digits)) < count($nums);
    }

    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        if (isset($_POST["numbers"])) {
            $input = $_POST["numbers"];
            $numbers = explode(',', $input);

            
            if (count($numbers) >= 2 && is_numeric($numbers[0])) {
                echo "Numbers: $input <br>";
                echo "Result: " . (checkRightmostDigit($input) ? "Yes" : "No");
            } else {
                echo "Please enter at least two valid integers separated by comma.";
            }
        } else {
            echo "Please enter two or more integers.";
        }
    }
    ?>
</body>
</html>

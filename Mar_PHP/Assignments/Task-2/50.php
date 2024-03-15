<!DOCTYPE html>
<html>
<head>
   
<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter three integers separated by comma: <input type="text" name="numbers">
        <input type="submit" name="submit" value="Check">
    </form>

    <?php
    
    function checkIntegerDifference($numbers) {
        $nums = explode(',', $numbers);

        if (count($nums) != 3) {
            return false;
        }

        sort($nums);

        return ($nums[1] - $nums[0] >= 20) || ($nums[2] - $nums[1] >= 20);
    }

    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        if (isset($_POST["numbers"])) {
            $input = $_POST["numbers"];
            $numbers = explode(',', $input);

            
            if (count($numbers) == 3 && is_numeric($numbers[0]) && is_numeric($numbers[1]) && is_numeric($numbers[2])) {
                echo "Numbers: $numbers[0], $numbers[1], $numbers[2] <br>";
                echo "Result: " . (checkIntegerDifference($input) ? "true" : "false");
            } else {
                echo "Please enter three valid integers separated by comma.";
            }
        } else {
            echo "Please enter three integers.";
        }
    }
    ?>
</body>
</html>
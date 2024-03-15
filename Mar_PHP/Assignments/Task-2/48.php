<!DOCTYPE html>
<html>
<head>
</head>
<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter three numbers separated by comma: <input type="text" name="numbers">
        <label for="allowEquality">Allow Equality:</label>
        <input type="checkbox" id="allowEquality" name="allowEquality" value="true">
        <input type="submit" name="submit" value="Check">
    </form>

    <?php
    
    function checkOrder($numbers, $allowEquality = false) {
        $nums = explode(',', $numbers);

        if (count($nums) != 3) {
            return false;
        }

        if ($allowEquality) {
            return ($nums[0] <= $nums[1]) && ($nums[1] <= $nums[2]);
        } else {
            return ($nums[0] < $nums[1]) && ($nums[1] < $nums[2]);
        }
    }

    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        if (isset($_POST["numbers"]) && isset($_POST["allowEquality"])) {
            $input = $_POST["numbers"];
            $allowEquality = ($_POST["allowEquality"] === "true");

            $numbers = explode(',', $input);

            
            if (count($numbers) == 3 && is_numeric($numbers[0]) && is_numeric($numbers[1]) && is_numeric($numbers[2])) {
                echo "Numbers: $numbers[0], $numbers[1], $numbers[2] <br>";
                echo "Allow Equality: " . ($allowEquality ? "Yes" : "No") . "<br>";
                echo "Result: " . (checkOrder($input, $allowEquality) ? "Yes" : "No");
            } else {
                echo "Please enter three valid integers separated by comma.";
            }
        } else {
            echo "Please enter three integers and select whether to allow equality.";
        }
    }
    ?>
</body>
</html>

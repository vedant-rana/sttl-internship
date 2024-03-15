<!DOCTYPE html>
<html>
<head>
</head>
<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter two integers separated by comma: <input type="text" name="numbers">
        <input type="submit" name="submit" value="Calculate">
    </form>

    <?php
    
    function computeSum($num1, $num2) {
        $sum = $num1 + $num2;

        if (($num1 >= 10 && $num1 <= 20) || ($num2 >= 10 && $num2 <= 20)) {
            return 18;
        }

        return $sum;
    }

    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        if (isset($_POST["numbers"])) {
            $input = $_POST["numbers"];
            $numbers = explode(',', $input);

            
            if (count($numbers) == 2 && is_numeric($numbers[0]) && is_numeric($numbers[1])) {
                $num1 = intval($numbers[0]);
                $num2 = intval($numbers[1]);
                echo "Numbers: $num1, $num2 <br>";
                echo "Result: " . computeSum($num1, $num2);
            } else {
                echo "Please enter two valid integers separated by comma.";
            }
        } else {
            echo "Please enter two integers.";
        }
    }
    ?>
</body>
</html>

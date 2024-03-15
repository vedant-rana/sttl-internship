<!DOCTYPE html>
<html>
<head>


<body>
  
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter a non-negative number: <input type="text" name="number">
        <input type="submit" name="submit" value="Check">
    </form>

    <?php
    
    function isMultipleOf3Or7($number) {
        return ($number % 3 == 0) xor ($number % 7 == 0);
    }

    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        if (isset($_POST["number"]) && is_numeric($_POST["number"])) {
            $number = intval($_POST["number"]);

            
            if ($number >= 0) {
                echo "Number: $number <br>";
                echo "Result: " . (isMultipleOf3Or7($number) ? "int(1)" : "int(0)");
            } else {
                echo "Please enter a non-negative number.";
            }
        } else {
            echo "Please enter a valid number.";
        }
    }
    ?>


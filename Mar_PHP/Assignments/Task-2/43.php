<!DOCTYPE html>
<html>
<head>
    
</head>
<body>
   
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        Enter a number: <input type="text" name="number">
        <input type="submit" name="submit" value="Check">
    </form>

    <?php
    
    function isWithinTwoOfMultipleOfTen($number) {
        return ($number % 10 <= 2) || (10 - $number % 10 <= 2);
    }

    
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        
        if (isset($_POST["number"]) && is_numeric($_POST["number"])) {
            $number = intval($_POST["number"]);
            echo "Number: $number <br>";
            echo "Result: " . (isWithinTwoOfMultipleOfTen($number) ? "bool(true)" : "bool(false)");
        } else {
            echo "Please enter a valid number.";
        }
    }
    ?>
</body>
</html>
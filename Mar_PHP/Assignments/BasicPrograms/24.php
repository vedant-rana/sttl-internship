<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>GCD Calculator</title>
</head>
<body>
    <h2>Calculate GCD of Two Numbers</h2>
    <form method="post">
        Enter first number: <input type="number" name="num1" required>
        <br><br>
        Enter second number: <input type="number" name="num2" required>
        <br><br>
        <input type="submit" name="submit" value="Calculate GCD">
    </form>

    <?php
    function findGCD($a, $b) {
        while($b != 0) {
            $temp = $b;
            $b = $a % $b;
            $a = $temp;
        }
        return $a;
    }

    if (isset($_POST['submit'])) {
        $num1 = abs($_POST['num1']); 
        $num2 = abs($_POST['num2']); 
        
        $gcd = findGCD($num1, $num2);

        echo "<p>GCD of $num1 and $num2 is: $gcd</p>";
    }
    ?>
</body>
</html>

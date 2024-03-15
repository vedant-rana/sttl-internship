<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>LCM Calculator</title>
</head>
<body>
    <h2>Calculate LCM of Two Numbers</h2>
    <form method="post">
        Enter first number: <input type="number" name="num1" required>
        <br><br>
        Enter second number: <input type="number" name="num2" required>
        <br><br>
        <input type="submit" name="submit" value="Calculate LCM">
    </form>

    <?php
    function gcd($a, $b) {
        return $b ? gcd($b, $a % $b) : $a;
    }

    function lcm($a, $b) {
        return abs($a * $b) / gcd($a, $b);
    }

    if (isset($_POST['submit'])) {
        $num1 = $_POST['num1'];
        $num2 = $_POST['num2'];
        
        
        $lcm = lcm($num1, $num2);

        echo "<p>LCM of $num1 and $num2 is: $lcm</p>";
    }
    ?>
</body>
</html>

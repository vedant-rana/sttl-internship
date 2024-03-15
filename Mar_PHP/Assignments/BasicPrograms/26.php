<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Prime Factorization Calculator</title>
</head>
<body>
    <h2>Prime Factorization of a Number</h2>
    <form method="post">
        Enter a number: <input type="number" name="number" min="2" required>
        <input type="submit" name="submit" value="Factorize">
    </form>

    <?php
    function primeFactorization($num) {
        $factors = [];
        
        while ($num % 2 == 0) {
            $factors[] = 2;
            $num = $num / 2;
        }

        
        for ($i = 3; $i <= sqrt($num); $i += 2) {
            
            while ($num % $i == 0) {
                $factors[] = $i;
                $num = $num / $i;
            }
        }

        
        
        if ($num > 2) {
            $factors[] = $num;
        }

        return $factors;
    }

    if (isset($_POST['submit'])) {
        $number = $_POST['number'];
        if ($number >= 2) {
            $factors = primeFactorization($number);
            echo "<p>Prime factors of $number: " . implode(', ', $factors) . "</p>";
        } else {
            echo "<p>Please enter a number greater than 1.</p>";
        }
    }
    ?>
</body>
</html>

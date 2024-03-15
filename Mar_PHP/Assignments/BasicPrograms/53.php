<!DOCTYPE html>
<html>
<head>
    <title>Find GCD and LCM</title>
</head>
<body>

<form method="post">
    <label for="numbers">Enter numbers separated by commas:</label>
    <input type="text" id="numbers" name="numbers"><br><br>
    <button type="submit">Calculate</button>
</form>

<?php
function findGcd($arr) {
    $temp = $arr[0];
    $n = count($arr);
    for ($i = 1; $i < $n; $i++) {
        $temp = gcd($temp, $arr[$i]);
    }
    return $temp;
}

function gcd($n1, $n2) {
    if ($n1 == 0) {
        return $n2;
    } elseif ($n2 == 0) {
        return $n1;
    } else {
        for ($i = 1; $i <= $n1 && $i <= $n2; $i++) {
            if ($n1 % $i == 0 && $n2 % $i == 0) {
                $gcd = $i;
            }
        }
    }
    return $gcd;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $numbers = $_POST['numbers'];
    $arr = explode(',', $numbers);

    $gcd = findGcd($arr);
    echo "GCD: $gcd<br>";

    $muli = 1;
    foreach ($arr as $value) {
        $muli *= $value;
    }
    $lcm = $muli / $gcd;
    echo "LCM: $lcm";
}
?>

</body>
</html>

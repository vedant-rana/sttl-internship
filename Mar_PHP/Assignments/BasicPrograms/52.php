<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

</head>
<body>
 
    <form method="post">
        <label for="month">Enter month (1-12):</label><br>
        <input type="number" id="month" name="month" min="1" max="12" required><br><br>
        <label for="year">Enter year:</label><br>
        <input type="number" id="year" name="year" required><br><br>
        <input type="submit" value="Print Calendar">
    </form>

    <?php
    function printCalendar($month, $year) {
        $firstDayOfMonth = date("N", strtotime("$year-$month-01"));
        $daysInMonth = cal_days_in_month(CAL_GREGORIAN, $month, $year);
        $currentDay = 1;

        echo "<h3>Calendar for $month/$year</h3>";
        echo "<table border='1'>";
        echo "<tr><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th><th>Sun</th></tr>";
        
        for ($i = 1; $i <= 6; $i++) {
            echo "<tr>";
            for ($j = 1; $j <= 7; $j++) {
                if (($i == 1 && $j < $firstDayOfMonth) || $currentDay > $daysInMonth) {
                    echo "<td>&nbsp;</td>";
                } else {
                    echo "<td>$currentDay</td>";
                    $currentDay++;
                }
            }
            echo "</tr>";
            if ($currentDay > $daysInMonth) {
                break;
            }
        }
        echo "</table>";
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $month = $_POST["month"];
        $year = $_POST["year"];
        printCalendar($month, $year);
    }
    ?>
</body>
</html>

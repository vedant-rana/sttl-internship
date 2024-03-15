<!DOCTYPE html>
<html>
<head>
    <title>String Values Table</title>
    <style>
        table {
            border-collapse: collapse;
            width: 50%;
        }
        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: left;
        }
    </style>
</head>
<body>

<h2>String Values Table</h2>
<table>
    <tr>
        <th>String</th>
        <th>Value</th>
    </tr>
    <?php
    $string_values = array(
        "Name" => "John",
        "Age" => 25,
        "City" => "New York",
        "Country" => "USA"
    ); foreach ($string_values as $string => $value) {
        echo "<tr>";
        echo "<td>$string</td>";
        echo "<td>$value</td>";
        echo "</tr>";
    }
    ?>
</table>

</body>
</html>

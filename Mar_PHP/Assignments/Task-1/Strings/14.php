<?php
$numeric_string = "1,234,567.89";

$numeric = str_replace(',', '', $numeric_string);

echo "Numeric string without commas: ".$numeric;
?>

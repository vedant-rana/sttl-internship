<?php

$current_month = date('n');
$previous_month = ($current_month - 1) <= 0 ? 12 : ($current_month - 1);

echo "Number of the month before the current month: $previous_month";
?>

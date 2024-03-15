<?php
function secondsToTime($seconds) {
    $days = floor($seconds / (60 * 60 * 24));
    $hours = floor(($seconds % (60 * 60 * 24)) / (60 * 60));
    $minutes = floor(($seconds % (60 * 60)) / 60);
    $seconds = $seconds % 60;
    
    $output = "";
    
    if ($days > 0) {
        $output .= "$days days, ";
    }
    
    if ($hours > 0) {
        $output .= "$hours hours, ";
    }
    
    if ($minutes > 0) {
        $output .= "$minutes minutes, ";
    }
    
    $output .= "$seconds seconds";
    
    return rtrim($output, ', ');
}

$seconds = 200000;
echo "Expected output: " . secondsToTime($seconds);
?>

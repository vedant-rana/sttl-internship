<?php
function calculateAge($dob) {
    $dob = new DateTime($dob);
    $now = new DateTime();
    $interval = $now->diff($dob);
    
    $years = $interval->y;
    $months = $interval->m;
    $days = $interval->d;
    
    return "Your age: $years years, $months months, $days days";
}


$dob = '14-01-2003';


$age = calculateAge($dob);


echo $age;
?>

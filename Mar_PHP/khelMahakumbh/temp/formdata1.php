<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $fname = $_POST['fname'];
    $mname = $_POST['mname'];
    $lname = $_POST['lname'];
    $age = $_POST['age'];
    $gender = $_POST['gender'];
    $mname = $_POST['dob'];
    $mname = $_POST['sport'];
    $mname = $_POST['sub-sport'];
    $mname = $_POST['another-game-check'];
    $mname = $_POST['mobile'];
    $mname = $_POST['email'];
    $mname = $_POST['weight'];
    $mname = $_POST['height'];
    $mname = $_POST['district'];
    $mname = $_POST['taluka'];
    $mname = $_POST['village'];
    $mname = $_POST['caste'];
    $mname = $_POST['parent-fname'];
    $mname = $_POST['parent-lname'];
    $mname = $_POST['parent-mobile'];
    $mname = $_POST['coach-name'];
    $mname = $_POST['coach-mobile'];
    $mname = $_POST['coach-address'];
    $mname = $_POST['captcha'];
    $mname = $_POST['accept-terms'];
    
    echo "Name: $name<br>";
    echo "Email: $email";
} else {
    header("Location: index.html");
    exit;
}
?>

<?php  

require '../models/Users.php';

if($_SERVER["REQUEST_METHOD"] == "POST"){
    $res = User::getUserDataById($_POST);

    if(count($res) == 0){
        echo "<script>window.location.href='login.php'; alert('Login Failed'); </script>";
        exit;
    }
}

?>
<?php
require '../models/Users.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    try {
        $res = User::registerUser($_POST);

        if ($res == true) {
            echo "<script>alert('Registration Successful'); window.location.href='login.php';</script>";
            exit;
        } else {
            echo "<script>alert('Registration Failed')</script>";
        }
    } catch (Exception $e) {
        $message = $e->getMessage();
        echo "<script>alert('Email is already in Used')</script>";
    }
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
    <link rel="stylesheet" href="style.css">

    <link rel="stylesheet" href="login.css">

</head>

<body>

    <div class="container">
        <div class="main-div">
            <div class="left">
                <div class="row">
                    <div class="col-md-12">
                        <form action="register.php" method="post">
                            <div class="row">
                                <div class="form-group col-md-6">
                                    <label for="fname">First Name <span>*</span></label>
                                    <input type="text" class="form-control" id="fname" name="fname">
                                </div>
                                <div class="form-group col-md-6">
                                    <label for="lname">Last Name <span>*</span></label>
                                    <input type="text" class="form-control" id="lname" name="lname">
                                </div>
                            </div>
                            <div class="form-group">
                                <label for="email">Email <span>*</span></label>
                                <input type="email" class="form-control" id="email" name="email">
                            </div>
                            <div class="form-group">
                                <label for="password">Password <span>*</span></label>
                                <input type="text" class="form-control" id="password" name="password">
                            </div>
                            <div class="form-group">
                                <label for="cpassword">confirmPassword <span>*</span></label>
                                <input type="password" class="form-control" id="cpassword" name="cpassword">
                            </div>
                            <div class="form-group">
                                <label for="captcha">Captcha <span>*</span></label>
                                <div class="row align-items-center">
                                    <div class="col-md-6">
                                        <input type="text" class="form-control" id="captcha" name="captcha" required>
                                    </div>
                                    <div class="col-md-4">
                                        <img src="../images/temp_captcha.png" alt="captcha" height="30rem">
                                    </div>
                                    <div class="col-md-1" style="margin-left: 1rem;">
                                        <i class="bi bi-arrow-clockwise"></i>
                                    </div>
                                </div>
                            </div>

                            <div>
                                <button type="submit" class="btn">Register</button>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
            <div class="right">
                <div class="overlay">
                    <div class="overlay-panel">
                        <h2>Register</h2>
                        <p>Enter your personal details and start journey with us</p>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>

</body>

</html>
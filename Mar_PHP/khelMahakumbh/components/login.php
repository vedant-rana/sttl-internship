<?php 

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
    
    <link rel="stylesheet" href="./footer.css">
    <link rel="stylesheet" href="./header.css">

</head>

<body>
<?php include '../components/header.php'; ?>

    <div class="container">
        <div class="main-div">
            <div class="left">
                <div class="row">
                    <div class="col-md-12">
                        <form action="./dashboard.php"  method="post">
                            <div class="form-group">
                                <label for="email">E-mail / KMK Id <span>*</span></label>
                                <input type="text" class="form-control" id="email-id" name="email-id">
                            </div>
                            <div class="form-group">
                                <label for="password">Password <span>*</span></label>
                                <input type="password" class="form-control" id="password" name="password">
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
                                <button type="submit" class="btn">Login</button>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
            <div class="right">
                <div class="overlay">
                    <div class="overlay-panel">
                        <h2>Login</h2>
                        <p>Enter your personal details and start journey with us</p>
                    </div>
                </div>
            </div>
        </div>
    </div>

    <?php include '../components/footer.php'; ?>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>

</body>

</html>
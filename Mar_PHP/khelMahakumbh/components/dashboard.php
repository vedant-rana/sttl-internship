<?php
require '../admin/Player.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $res = Player::loginPlayer($_POST);

    if (count($res) == 0) {
        echo "<script>window.location.href='login.php';  </script>";
        exit;
    }
}


?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <!-- Option 1: Include in HTML -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.3.0/font/bootstrap-icons.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous">
    </script>
    <link rel="stylesheet" href="./dashboard.css">
    <link rel="stylesheet" href="./footer.css">
    <link rel="stylesheet" href="./header.css">
    <title pb-2>Dashboard</title pb-2>
</head>

<body>
    <?php include '../components/header.php'; ?>

    <div class="dashboard py-5">
        <div class="container main m-auto">
            <div class="user-details d-flex justify-content-between p-3 mb-4">
                <div class="" style="width: 35%;">
                    <h2><?php
                        if ($res['fname']  && $res['lname']) {
                            echo $res['fname'] . ' ' . $res['lname'];
                        } else {
                            echo 'Name not set yet';
                        }
                        ?></h2>
                    <p><?php echo $res['sport'] . ' (' . $res['sub_sport'] . ')' ?></p>
                </div>
                <div style="width: 20%;">
                    <div class="details">
                        <h5>KMKID</h5>
                        <p><?php echo ($res['kmk_id'] ? $res['kmk_id'] : '-') ?></p>
                    </div>
                    <div class="details">
                        <h5>Email</h5>
                        <p><?php echo ($res['email'] ? $res['email'] : '-') ?></p>
                    </div>
                    <div class="details">
                        <h5>Player</h5>
                        <p>Individual Player</p>
                    </div>
                </div>
                <div class="" style="width: 20%;">
                    <div class="details">
                        <h5>KhelMahaKumbh ID</h5>
                        <p><?php echo ($res['kmk_id'] ? $res['kmk_id'] : '-') ?></p>
                    </div>
                    <div class="details">
                        <h5>Mobile Number</h5>
                        <p><?php echo ($res['mobile'] ? $res['mobile'] : '-') ?></p>
                    </div>
                    <div class="details">
                        <h5>Registered School Name</h5>
                        <p>-</p>
                    </div>
                </div>
                <div class="" style="width: 20%;">
                    <div class="details">
                        <h5>Team Id</h5>
                        <p>-</p>
                    </div>
                    <div class="details">
                        <h5>Date of Birth</h5>
                        <p><?php

                            $original_date = $res['dob'];

                            $timestamp = strtotime($original_date);

                            $new_date = date("d-m-Y", $timestamp);

                            echo ($new_date ? $new_date : '-')

                            ?></p>
                    </div>
                </div>
            </div>

            <div class="certificates d-flex align-center justify-content-between mb-4">
                <div class="p-2 me-2 bg-white certificates-left rounded border-secondary" style="width: 62%;">
                    <h5 class="title pb-2">Certificates</h5>
                    <div class="rounded download p-2 color-white">
                        <div class="print rounded me-2">
                            <i class="bi bi-printer color-white"></i>
                        </div>
                        <form action="download.php" method="post" class="download-form">
                            <button type="submit" name="download_pdf">Download Form</button>
                        </form>
                        <!-- <span>Download Form</span> -->
                    </div>
                </div>
                <div class="p-2 bg-white certificates-right rounded" style="width: 35%;">
                    <h5 class="title pb-2">Upcoming Events</h5>


                </div>
            </div>

            <div class="kmk-details bg-white rounded p-3">
                <h5 class="title pb-2">11th KhelMahaKumbh Details</h5>
                <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Totam obcaecati velit consequatur sequi
                    voluptas, possimus error impedit vero tenetur explicabo excepturi in sapiente voluptatibus minima,
                    iusto dolor dicta ad perferendis tempora? Totam officia cupiditate ducimus harum sit incidunt velit
                    voluptas ullam suscipit non omnis quibusdam ad repellat nulla eaque debitis, voluptatum amet
                    corporis et voluptatem possimus, autem quod aut. Quasi, facilis rerum officia, vel modi odio
                    laboriosam quam ex soluta tempora ducimus velit quod. Ea enim ipsa vel. Adipisci, dolore, doloribus
                    omnis pariatur debitis consectetur perspiciatis ex reiciendis tempore error voluptates aperiam odio
                    facilis delectus numquam. Tenetur beatae architecto voluptatem!</p>
            </div>
        </div>
    </div>

    <?php include '../components/footer.php'; ?>

</body>

</html>
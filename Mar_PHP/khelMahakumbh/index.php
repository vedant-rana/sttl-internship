<!-- 
<?php  

require 'assets/array_assets.php';

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration - Khel Mahakumbh</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
    <link rel="stylesheet" href="style.css">

</head>

<body>
    <div class="container">
        <div class="instructions">
            <h5>Instructions For Registration</h5>
            <ul>
                <li>
                    For Under-9, Under-11, Under-14, Under-17 competitions, Registration through School is mandatory.
                </li>
                <li>
                    Open Age Group (Born 31/12/2006 And Before)
                </li>
                <li>
                    While registering to participate in the second game, registration must be done with the first registration ID (first game of KMK Id), otherwise the registration of the second game will not be considered valid.
                </li>
            </ul>
        </div>

        <form action="./admin/display_player.php" method="post">
            <h4>Fetch Data From KMK ID</h4>
            <hr />
            <div class="row">
                <div class="form-group col-md-3">
                    <label for="kmkTitle">KhelMahaKumbh</label>
                    <select class="form-select" id="kmkTitle" name="kmkTitle" required>
                        <option>11'th KhelMahaKumbh</option>
                        <option>10'th KhelMahaKumbh</option>
                        <option>9'th KhelMahaKumbh</option>
                        <option>8'th KhelMahaKumbh</option>
                    </select>
                </div>

                <div class="form-group col-md-3">
                    <label for="kmk_id">KMK ID</label>
                    <input type="text" class="form-control" id="kmk_id" name="kmk_id" placeholder="KMK0000000" required>
                </div>
                <div class="form-group col-md-3">
                    <label>&nbsp;</label>
                    <br>
                    <button type="submit" class="btn">Search</button>
                </div>
                <div class="form-group col-md-3">
                    <label>&nbsp;</label>
                    <br>
                    <a href="./admin/displayPlayers.php" class="btn">Gel All Data</a>
                </div>
            </div>
        </form>

        <form action="./admin/submitPlayer.php" method="post">
            <h4>Player Details</h4>
            <hr />
            <div class="row">
                <div class="form-group col-md-3">
                    <label for="fname">First Name <span>*</span></label>
                    <input type="text" class="form-control" id="fname" name="fname" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="mname">Father/Husband Name <span>*</span></label>
                    <input type="text" class="form-control" id="mname" name="mname" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="lname">last Name <span>*</span></label>
                    <input type="text" class="form-control" id="lname" name="lname" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="age">Age Group <span>*</span></label>
                    <select class="form-select" id="age" name="age" required>
                        <?php

                        foreach ($ageArr as $value => $label) {
                            echo "<option value='$value' $selected>$label</option>";
                        }

                        ?>
                    </select>
                </div>
                <div class="form-group col-md-3">
                    <label>Select Gender</label>
                    <div class="d-flex">
                        <div class="form-check" style="padding-right: 1rem;">
                            <label class="form-check-label">
                                <input type="radio" class="form-check-input" name="gender" value="male"> Male
                            </label>
                        </div>
                        <div class="form-check">
                            <label class="form-check-label">
                                <input type="radio" class="form-check-input" name="gender" value="female"> Female
                            </label>
                        </div>
                    </div>

                </div>

                <div class="form-group col-md-3">
                    <label for="dob">Date of Birth (DD-MM-YYYY) <span>*</span></label>
                    <input type="date" class="form-control" id="dob" name="dob" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="sport">Sport Name <span>*</span></label>
                    <select class="form-select" id="sport" name="sport" required>
                        <?php
                       

                        foreach ($sports as $value => $label) {
                            echo "<option value='$value'>$label</option>";
                        }
                        ?>
                    </select>
                </div>
                <div class="form-group col-md-3">
                    <label for="sub_sport">Sub Sport Name <span>*</span></label>
                    <select class="form-select" id="sub_sport" name="sub_sport" required>
                        <?php
                        
                        foreach ($subSports as $value => $label) {
                            echo "<option value='$value'>$label</option>";
                        }
                        ?>
                    </select>
                    </select>
                </div>

                <div class="form-group col-md-3">
                    <label for="another-game-check">Tick the Check box to select another game</label>
                    <div class="form-check">
                        <input class="form-check-input" type="checkbox" value="" id="another-game-check" name="another-game-check">
                    </div>
                </div>

                <div class="form-group col-md-3">
                    <label for="mobile">Mobile Number <span>*</span></label>
                    <input type="number" class="form-control" id="mobile" name="mobile" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="email">Email <span>*</span></label>
                    <input type="email" class="form-control" id="email" name="email" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="weight">Weight (kg)</label>
                    <input type="text" class="form-control" id="weight" name="weight">
                </div>
                <div class="form-group col-md-3">
                    <label for="height">Height (cm)</label>
                    <input type="text" class="form-control" id="height" name="height">
                </div>
                <div class="form-group col-md-3">
                    <label for="district">District</label>
                    <input type="text" class="form-control" id="district" name="district">
                </div>
                <div class="form-group col-md-3">
                    <label for="taluka">Taluka / Zone </label>
                    <input type="text" class="form-control" id="taluka" name="taluka">
                </div>
                <div class="form-group col-md-3">
                    <label for="village">Village / Ward </label>
                    <input type="text" class="form-control" id="village" name="village">
                </div>
                <div class="form-group col-md-3">
                    <label for="caste">Caste <span>*</span></label>
                    <select class="form-select" id="caste" name="caste" required>
                        <?php
                        
                        foreach ($casteArr as $value => $label) {
                            echo "<option value='$value'>$label</option>";
                        }
                        ?>
                    </select>
                </div>
            </div>

            <h4>Guardians Details</h4>
            <hr />
            <div class="row">
                <div class="form-group col-md-3">
                    <label for="parent_fname">First Name </label>
                    <input type="text" class="form-control" id="parent_fname" name="parent_fname">
                </div>
                <div class="form-group col-md-3">
                    <label for="parent_lname">Last Name </label>
                    <input type="text" class="form-control" id="parent_lname" name="parent_lname">
                </div>
                <div class="form-group col-md-3">
                    <label for="parent_mobile">Mobile </label>
                    <input type="number" class="form-control" id="parent_mobile" name="parent_mobile">
                </div>
            </div>

            <h4>Other Details</h4>
            <hr />
            <div class="row">

                <div class="form-group col-md-3">
                    <label for="coach_name">Coach Name </label>
                    <input type="text" class="form-control" id="coach_name" name="coach_name">
                </div>
                <div class="form-group col-md-3">
                    <label for="coach_mobile">Coach Mobile Number </label>
                    <input type="text" class="form-control" id="coach_mobile" name="coach_mobile">
                </div>
                <div class="form-group col-md-3">
                    <label for="coach_address">Coach Home Address </label>
                    <input type="text" class="form-control" id="coach_address" name="coach_address">
                </div>

            </div>
            <div class="form-group">
                <label for="captcha">Captcha</label>
                <div class="row align-items-center">
                    <div class="col-md-2">
                        <input type="text" class="form-control" id="captcha" name="captcha" required>
                    </div>
                    <div class="col-1">
                        <img src="./images/temp_captcha.png" alt="captcha" height="30rem">
                    </div>
                    <div class="col" style="margin-left: 1rem;">
                        <i class="bi bi-arrow-clockwise"></i>
                    </div>
                </div>
            </div>

            <p>Note - You will receive the login ID and password information of the player in the above e-mail.
            </p>

            <ol>
                <li>
                    If any kind of physical injury happens during the competition, it will be the responsibility of me
                    and my guardian. The organizer will have no responsibility
                </li>
                <li>
                    I will register from one place from the entire state, otherwise my registration will be canceled.
                </li>
                <li>
                    Therefore, I guarantee that if I am selected as the winner in Khelmahakumbh, I will be present at
                    the competition venue at my own expense and risk before the time indicated.
                </li>
                <li>
                    Mark the event on the back page for each individual sub-event game.
                </li>
                <li>
                    Form-A for individual sport and Form-A and Form B for joint sport are mandatory to be filled.
                </li>

                <li>
                    Form-B must be filled for Table Tennis, Lawn Tennis, Badminton Doubles and Mixed Doubles.
                </li>
            </ol>

            <div class="form-group col-md-3">
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" value="" id="accept-terms" name="accept-terms" required>
                    <label for="accept-terms">I Accept</label>
                </div>
            </div>

            <hr>
            <div style="text-align: right;">
                <button type="submit" class="btn ">Submit</button>
            </div>

        </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html> -->
<?php require './components/footer.php'; ?>
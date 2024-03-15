<?php
require '../assets/array_assets.php';
require 'Player.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $player = new Player($_POST);
    $result = $player->updatePlayerData($_POST['id']);

    if ($result) {
        header("Location: displayPlayers.php?updation=success");
    } else {
        header("Location: displayPlayers.php?updation=failure");
    }
} else {
    if (isset($_GET['id'])) {

        $playerId = $_GET['id'];

        $result = Player::getPlayerById($playerId);
    }
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration - Khel Mahakumbh</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
    <link rel="stylesheet" href="../style.css">
    <link rel="stylesheet" href="../components/footer.css">
    <link rel="stylesheet" href="../components/header.css">


</head>

<body>
<?php include '../components/header.php'; ?>

    <div class="container register-div">

        <form action="./update_player.php" method="post">
            <h4>Player Details</h4>
            <hr />
            <input type="hidden" name="id" value="<?php echo $result['kmk_id']; ?>">
            <div class="row">
                <div class="form-group col-md-3">
                    <label for="fname">First Name <span>*</span></label>
                    <input type="text" class="form-control" id="fname" name="fname" value="<?php echo $result['fname'] ?>" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="mname">Father/Husband Name <span>*</span></label>
                    <input type="text" class="form-control" id="mname" name="mname" value="<?php echo $result['mname'] ?>" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="lname">last Name <span>*</span></label>
                    <input type="text" class="form-control" id="lname" name="lname" value="<?php echo $result['lname'] ?>" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="age">Age Group <span>*</span></label>
                    <select class="form-select" id="age" name="age" required>
                        <option>Select</option>
                        <?php

                        foreach ($ageArr as $value => $label) {
                            $selected = ($result['age'] == $value) ? 'selected' : '';
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
                                <input type="radio" class="form-check-input" name="gender" value="male" <?php echo ($result['gender'] == 'm') ? 'checked' : ''; ?> />Male
                            </label>
                        </div>
                        <div class="form-check">
                            <label class="form-check-label">
                                <input type="radio" class="form-check-input" name="gender" value="female" <?php echo ($result['gender'] == 'f') ? 'checked' : ''; ?> /> Female
                            </label>
                        </div>
                    </div>

                </div>

                <div class="form-group col-md-3">
                    <label for="dob">Date of Birth (DD-MM-YYYY) <span>*</span></label>
                    <input type="date" class="form-control" id="dob" name="dob" value="<?php echo $result['dob'] ?>" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="sport">Sport Name <span>*</span></label>
                    <select class="form-select" id="sport" name="sport" required>
                        <option>Select</option>
                        <?php

                        foreach ($sports as $value => $label) {
                            $selected = ($result['sport'] == $value) ? 'selected' : '';
                            echo "<option value='$value' $selected>$label</option>";
                        }
                        ?>
                        <option>24-40</option>
                    </select>
                </div>
                <div class="form-group col-md-3">
                    <label for="sub_sport">Sub Sport Name <span>*</span></label>
                    <select class="form-select" id="sub_sport" name="sub_sport" required>
                        <option>Select Sub Events</option>
                        <?php

                        foreach ($subSports as $value => $label) {
                            $selected = ($result['sub_sport'] == $value) ? 'selected' : '';
                            echo "<option value='$value' $selected>$label</option>";
                        }
                        ?>
                    </select>
                </div>

                <div class="form-group col-md-3">
                    <label for="mobile">Mobile Number <span>*</span></label>
                    <input type="number" class="form-control" id="mobile" name="mobile" value="<?php echo $result['mobile'] ?>" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="email">Email <span>*</span></label>
                    <input type="email" class="form-control" id="email" name="email" value="<?php echo $result['email'] ?>" required>
                </div>
                <div class="form-group col-md-3">
                    <label for="weight">Weight (kg)</label>
                    <input type="text" class="form-control" id="weight" name="weight" value="<?php echo $result['weight'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="height">Height (cm)</label>
                    <input type="text" class="form-control" id="height" name="height" value="<?php echo $result['height'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="district">District</label>
                    <input type="text" class="form-control" id="district" name="district" value="<?php echo $result['district'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="taluka">Taluka / Zone </label>
                    <input type="text" class="form-control" id="taluka" name="taluka" value="<?php echo $result['taluka'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="village">Village / Ward </label>
                    <input type="text" class="form-control" id="village" name="village" value="<?php echo $result['village'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="caste">Caste <span>*</span></label>
                    <select class="form-control" id="caste" name="caste" required>
                        <?php

                        foreach ($casteArr as $value => $label) {
                            $selected = ($result['caste'] == $value) ? 'selected' : '';
                            echo "<option value='$value' $selected>$label</option>";
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
                    <input type="text" class="form-control" id="parent_fname" name="parent_fname" value="<?php echo $result['parent_fname'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="parent_lname">Last Name </label>
                    <input type="text" class="form-control" id="parent_lname" name="parent_lname" value="<?php echo $result['parent_lname'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="parent_mobile">Mobile </label>
                    <input type="number" class="form-control" id="parent_mobile" name="parent_mobile" value="<?php echo $result['parent_mobile'] ?>">
                </div>
            </div>

            <h4>Other Details</h4>
            <hr />
            <div class="row">

                <div class="form-group col-md-3">
                    <label for="coach_name">Coach Name </label>
                    <input type="text" class="form-control" id="coach_name" name="coach_name" value="<?php echo $result['coach_name'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="coach_mobile">Coach Mobile Number </label>
                    <input type="text" class="form-control" id="coach_mobile" name="coach_mobile" value="<?php echo $result['coach_mobile'] ?>">
                </div>
                <div class="form-group col-md-3">
                    <label for="coach_address">Coach Home Address </label>
                    <input type="text" class="form-control" id="coach_address" name="coach_address" value="<?php echo $result['coach_address'] ?>">
                </div>

            </div>

            <hr>
            <div style="text-align: right;">
                <button type="submit" class="btn btn-success">Update</button>
                <a href="displayPlayers.php" class="btn btn-secondary">Back</a>
            </div>

        </form>
    </div>
    <?php include '../components/footer.php'; ?>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>
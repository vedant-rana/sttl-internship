<?php

require 'Player.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $playerId = $_POST['kmk_id'];
        $result = Player::getPlayerById($playerId);   
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

        <form>
            <h4>Player Details</h4>
            <hr />
            <input type="hidden" name="id" value="<?php echo $result['kmk_id']; ?>">
            <div class="row">
                <div class="form-group col-md-3">
                    <label for="fname">First Name <span>*</span></label>
                    <input type="text" class="form-control" id="fname" name="fname" value="<?php echo $result['fname'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="mname">Father/Husband Name <span>*</span></label>
                    <input type="text" class="form-control" id="mname" name="mname" value="<?php echo $result['mname'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="lname">last Name <span>*</span></label>
                    <input type="text" class="form-control" id="lname" name="lname" value="<?php echo $result['lname'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="age">Age Group <span>*</span></label>
                    <input type="text" class="form-control" id="age" name="age" value="<?php echo $result['age'] ?>" readonly>

                </div>
                <div class="form-group col-md-3">
                    <label for="gender">Gender<span>*</span></label>
                    <input type="text" class="form-control" id="gender" name="gender" value="<?php echo ($result['gender'] == 'm') ? 'Male' : 'Female' ?>" readonly>
                </div>

                <div class="form-group col-md-3">
                    <label for="dob">Date of Birth (DD-MM-YYYY) <span>*</span></label>
                    <input type="date" class="form-control" id="dob" name="dob" value="<?php echo $result['dob'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="sport">Sport Name <span>*</span></label>
                    <input type="text" class="form-control" id="sport" name="sport" value="<?php echo $result['sport'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="sub_sport">Sub Sport Name <span>*</span></label>
                    <input type="text" class="form-control" id="sub_sport" name="sub_sport" value="<?php echo $result['sub_sport'] ?>" readonly>

                </div>

                <div class="form-group col-md-3">
                    <label for="mobile">Mobile Number <span>*</span></label>
                    <input type="number" class="form-control" id="mobile" name="mobile" value="<?php echo $result['mobile'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="email">Email <span>*</span></label>
                    <input type="email" class="form-control" id="email" name="email" value="<?php echo $result['email'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="weight">Weight (kg)</label>
                    <input type="text" class="form-control" id="weight" name="weight" value="<?php echo $result['weight'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="height">Height (cm)</label>
                    <input type="text" class="form-control" id="height" name="height" value="<?php echo $result['height'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="district">District</label>
                    <input type="text" class="form-control" id="district" name="district" value="<?php echo $result['district'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="taluka">Taluka / Zone </label>
                    <input type="text" class="form-control" id="taluka" name="taluka" value="<?php echo $result['taluka'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="village">Village / Ward </label>
                    <input type="text" class="form-control" id="village" name="village" value="<?php echo $result['village'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="caste">Caste <span>*</span></label>
                    <input type="text" class="form-control" id="caste" name="caste" value="<?php echo $result['caste'] ?>" readonly>

                </div>
            </div>

            <h4>Guardians Details</h4>
            <hr />
            <div class="row">
                <div class="form-group col-md-3">
                    <label for="parent_fname">First Name </label>
                    <input type="text" class="form-control" id="parent_fname" name="parent_fname" value="<?php echo $result['parent_fname'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="parent_lname">Last Name </label>
                    <input type="text" class="form-control" id="parent_lname" name="parent_lname" value="<?php echo $result['parent_lname'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="parent_mobile">Mobile </label>
                    <input type="number" class="form-control" id="parent_mobile" name="parent_mobile" value="<?php echo $result['parent_mobile'] ?>" readonly>
                </div>
            </div>

            <h4>Other Details</h4>
            <hr />
            <div class="row">

                <div class="form-group col-md-3">
                    <label for="coach_name">Coach Name </label>
                    <input type="text" class="form-control" id="coach_name" name="coach_name" value="<?php echo $result['coach_name'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="coach_mobile">Coach Mobile Number </label>
                    <input type="text" class="form-control" id="coach_mobile" name="coach_mobile" value="<?php echo $result['coach_mobile'] ?>" readonly>
                </div>
                <div class="form-group col-md-3">
                    <label for="coach_address">Coach Home Address </label>
                    <input type="text" class="form-control" id="coach_address" name="coach_address" value="<?php echo $result['coach_address'] ?>" readonly>
                </div>

            </div>

            <hr>
            <div style="text-align: right;">
                <a href="update_player.php?id=<?php echo $result['kmk_id'] ?>" class="btn btn-success">Update</a>
                <a href="displayPlayers.php" class="btn btn-secondary">Back</a>

            </div>

        </form>
    </div>
    <?php require '../components/footer.php'; ?>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>
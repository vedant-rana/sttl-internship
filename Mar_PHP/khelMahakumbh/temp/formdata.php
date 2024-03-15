<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form Data</title>
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
    <div class="container p-3">
        <h1>Form Data</h1>
        <hr>
        <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            // Store form data in variables
            $fname = $_POST['fname'];
            $mname = $_POST['mname'];
            $lname = $_POST['lname'];
            $age = $_POST['age'];
            $gender = $_POST['gender'];
            $dob = $_POST['dob'];
            $sport = $_POST['sport'];
            $sub_sport = $_POST['sub-sport'];
            $mobile = $_POST['mobile'];
            $email = $_POST['email'];
            $weight = $_POST['weight'];
            $height = $_POST['height'];
            $district = $_POST['district'];
            $taluka = $_POST['taluka'];
            $village = $_POST['village'];
            $caste = $_POST['caste'];
            $parent_fname = $_POST['parent-fname'];
            $parent_lname = $_POST['parent-lname'];
            $parent_mobile = $_POST['parent-mobile'];
            $coach_name = $_POST['coach-name'];
            $coach_mobile = $_POST['coach-mobile'];
            $coach_address = $_POST['coach-address'];
            
            // Display form data
            echo "<h2>Player Details</h2>";
            echo "<p>First Name: $fname</p>";
            echo "<p>Father/Husband Name: $mname</p>";
            echo "<p>Last Name: $lname</p>";
            echo "<p>Age Group: $age</p>";
            echo "<p>Gender: $gender</p>";
            echo "<p>Date of Birth: $dob</p>";
            echo "<p>Sport Name: $sport</p>";
            echo "<p>Sub Sport Name: $sub_sport</p>";
            echo "<p>Mobile Number: $mobile</p>";
            echo "<p>Email: $email</p>";
            echo "<p>Weight: $weight</p>";
            echo "<p>Height: $height</p>";
            echo "<p>District: $district</p>";
            echo "<p>Taluka / Zone: $taluka</p>";
            echo "<p>Village / Ward: $village</p>";
            echo "<p>Caste: $caste</p>";
            
            echo "<h2>Guardians Details</h2>";
            echo "<p>Guardian First Name: $parent_fname</p>";
            echo "<p>Guardian Last Name: $parent_lname</p>";
            echo "<p>Guardian Mobile: $parent_mobile</p>";
            
            echo "<h2>Other Details</h2>";
            echo "<p>Coach Name: $coach_name</p>";
            echo "<p>Coach Mobile Number: $coach_mobile</p>";
            echo "<p>Coach Home Address: $coach_address</p>";
        } 
        ?>
    </div>

    <!-- Bootstrap JS -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
        crossorigin="anonymous"></script>
</body>
</html>

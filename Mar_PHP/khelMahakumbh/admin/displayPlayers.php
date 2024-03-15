<?php
require 'Player.php';
$players = Player::getAllPlayers();
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Players Data</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">

    <link rel="stylesheet" href="https://cdn.datatables.net/1.13.4/css/dataTables.bootstrap5.min.css" />

    <link rel="stylesheet" href="../components/footer.css">
    <link rel="stylesheet" href="../components/header.css">
    <link rel="stylesheet" href="../style.css">
</head>

<body>
    <?php include '../components/header.php'; ?>


    <div class="container register-div mt-5">
        <h2 style="margin-bottom: 2rem;" class="text-center">Players Data</h2>
        <table id="myTable" class="table table-striped table-bordered text-center">
            <thead class="table-dark">
                <tr>
                    <th scope="col">First Name</th>
                    <th scope="col">Last Name</th>
                    <th scope="col">Age</th>
                    <th scope="col">Gender</th>
                    <th scope="col">Sport</th>
                    <th scope="col">Taluka</th>
                    <th scope="col">Coach Name</th>
                    <th scope="col">Actions</th>
                </tr>
            </thead>
            <tbody class="table-group-divider">
                <?php foreach ($players as $player) {
                    echo '<tr><td>' . $player['fname'] . '</td>';
                    echo '<td>' . $player['lname'] . '</td>';
                    echo '<td>' . $player['age'] . '</td>';
                    echo '<td>' . ($player['gender'] == 'm' ? 'Male' : 'Female') . '</td>';
                    echo '<td>' . $player['sport'] . '</td>';
                    echo '<td>' . $player['taluka'] . '</td>';
                    echo '<td>' . $player['coach_name'] . '</td>';
                    echo '<td>';
                    echo '<a href="display_player.php?id=' . $player['kmk_id'] . '" class="btn btn-success" style="margin-right:0.5rem;"><i class="bi bi-info-circle"></i></a>';
                    echo '<a href="update_player.php?id=' . $player['kmk_id'] . '" class="btn btn-warning" style="margin-right:0.5rem;"><i class="bi bi-pencil-square"></i></a>';
                    echo '<a href="deletePlayer.php?id=' . $player['kmk_id'] . '" class="btn btn-danger" onclick="return confirm(\'Are you sure you want to delete this player?\')"><i class="bi bi-trash3"></i></a>';
                    echo '</td></tr>';
                } ?>
            </tbody>
        </table>
    </div>
    <?php include '../components/footer.php'; ?>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/jquery-3.7.0.js"></script>
    <script src="https://cdn.datatables.net/1.13.4/js/jquery.dataTables.min.js"></script>
    <script src="https://cdn.datatables.net/1.13.4/js/dataTables.bootstrap5.min.js"></script>
    <script>
        $(document).ready(function() {
            $('#myTable').DataTable();
        });
    </script>
</body>

</html>

<?php

if (isset($_GET["deletion"])) {
    if ($_GET['deletion'] == 'success') {
        echo "<script>alert('Player Deleted Successfully!');</script>";
    } else {
        echo "<script>alert('Error in Player Deletion!');</script>";
    }
}

if (isset($_GET["updation"])) {
    if ($_GET['updation'] == 'success') {
        echo "<script>alert('Player Updated Successfully!');</script>";
    } else {
        echo "<script>alert('Error in Player updation!');</script>";
    }
}

?>
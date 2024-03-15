<?php
require 'Player.php';

if(isset($_GET['id'])){
    $playerId = $_GET['id'];

    $result = Player::deletePlayer($playerId);

    if ($result) {
        header("Location: displayPlayers.php?deletion=success");
    } else {
        header("Location: displayPlayers.php?deletion=failure");
    }
    
}
?>
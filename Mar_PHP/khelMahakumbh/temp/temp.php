<?php

require 'db_config.php';

$conn = establishConnection();

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}else{
    echo "conection established";
}

?>

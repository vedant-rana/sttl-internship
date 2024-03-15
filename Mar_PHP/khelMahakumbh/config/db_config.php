<?php

// Database configuration
$servername = "localhost:3500";
$username = "root";
$password = "";
$dbname = "khelmahakumbh";

function establishConnection()
{
    global $servername, $username, $password, $dbname;
    return new mysqli($servername, $username, $password, $dbname);  //
}
?>
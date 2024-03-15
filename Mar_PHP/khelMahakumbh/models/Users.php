<?php
require '../config/db_config.php';


class User
{
    private $fname;
    private $lname;
    private $email;
    private $password;


    public static function registerUser($userData)
    {
        $result=false;
        $conn = establishConnection();

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "INSERT INTO users (fname, lname, email, password)
        VALUES (?,?,?,?)";

        $stmt = $conn->prepare($sql);

        $stmt->bind_param(
            "ssss",
            $userData['fname'],
            $userData['lname'],
            $userData['email'],
            $userData['password'],
        );

        $stmt->execute();

         // Check for errors
         if (!$stmt->error) {
            $result = true;
        } 

        // Close connection
        $stmt->close();
        $conn->close();

        return $result;
    }


    public static function loginUser($loginData) {
        $conn = establishConnection();
        $result=[];
        
        // Prepare the query
        $query = "SELECT * FROM users where email=?";
        $stmt = $conn->prepare($query);
        $stmt->bind_param("s", $loginData['email']);
        $stmt->execute();
        
        $data = $stmt->get_result();

        if($data->num_rows > 0){
            $result = $data->fetch_assoc();
        }
        
        $stmt->close();
        $conn->close();

        if(count($result) > 0 && $loginData['password'] === $result['password']){
            return  $result;
        }else{
            return [];
        }

        return $result;
    }


    public static function getUserDataById($userData){
        $conn = establishConnection();
        $result=[];
        
        // Prepare the query
        $query = "SELECT * FROM users where user_id=?";
        $stmt = $conn->prepare($query);
        $stmt->bind_param("s", $userData['user_id']);
        $stmt->execute();
        
        $data = $stmt->get_result();

        if($data->num_rows > 0){
            $result = $data->fetch_assoc();
        }
        
        $stmt->close();
        $conn->close();

        return $result;
    }
}

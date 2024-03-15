<?php
require '../config/db_config.php';  //database connection details


class Player
{

    public $fname;
    public $mname;
    public $lname;
    public $age;
    public $gender;
    public $dob;
    public $sport;
    public $sub_sport;
    public $mobile;
    public $email;
    public $password;
    public $weight;
    public $height;
    public $district;
    public $taluka;
    public $village;
    public $caste;
    public $parent_fname;
    public $parent_lname;
    public $parent_mobile;
    public $coach_name;
    public $coach_mobile;
    public $coach_address;

  

    public function __construct($formData)
    {
        $this->setPlayer($formData);
    }

    public function insertIntoDatabase()
    {

        $result=false;
        // Create connection
        $conn = establishConnection();

        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        // Prepare SQL statement
        $sql = "INSERT INTO players (fname, mname, lname, age, gender, dob, sport, sub_sport, mobile, email, password, weight, height, district, taluka, village, caste, parent_fname, parent_lname, parent_mobile, coach_name, coach_mobile, coach_address)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

        $stmt = $conn->prepare($sql);

        // Bind parameters
        $stmt->bind_param(
            "sssssssssssssssssssssss",
            $this->fname,
            $this->mname,
            $this->lname,
            $this->age,
            $this->gender,
            $this->dob,
            $this->sport,
            $this->sub_sport,
            $this->mobile,
            $this->email,
            $this->password,
            $this->weight,
            $this->height,
            $this->district,
            $this->taluka,
            $this->village,
            $this->caste,
            $this->parent_fname,
            $this->parent_lname,
            $this->parent_mobile,
            $this->coach_name,
            $this->coach_mobile,
            $this->coach_address
        );

        // Execute the statement
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

    public function setPlayer($formData){
        $this->fname = $formData['fname'];
        $this->mname = $formData['mname'];
        $this->lname = $formData['lname'];
        $this->age = $formData['age'];
        $this->gender = $formData['gender'];
        $this->dob = $formData['dob'];
        $this->sport = $formData['sport'];
        $this->sub_sport = $formData['sub_sport'];
        $this->mobile = $formData['mobile'];
        $this->email = $formData['email'];
        $this->password = $formData['password'];
        $this->weight = $formData['weight'];
        $this->height = $formData['height'];
        $this->district = $formData['district'];
        $this->taluka = $formData['taluka'];
        $this->village = $formData['village'];
        $this->caste = $formData['caste'];
        $this->parent_fname = $formData['parent_fname'];
        $this->parent_lname = $formData['parent_lname'];
        $this->parent_mobile = $formData['parent_mobile'];
        $this->coach_name = $formData['coach_name'];
        $this->coach_mobile = $formData['coach_mobile'];
        $this->coach_address = $formData['coach_address'];
    }

    public static function getAllPlayers()
    {
        $conn = establishConnection();

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $query = "SELECT * FROM `players`;";

        $result = $conn->query($query);
        $players = [];

        if($result->num_rows > 0){
            while($row = $result->fetch_assoc()){
                $players[] = $row;
            }
        }
        $conn->close();
        return $players;
    }

    public static function deletePlayer($playerId){
        $result = false;
        $conn = establishConnection();
        $sql = "DELETE FROM players WHERE kmk_id = ?";

        $stmt = $conn->prepare($sql);
        $stmt->bind_param("i", $playerId);
        $stmt->execute();
    
        if ($stmt->affected_rows > 0) {
            $result = true;
        } 
    
        $stmt->close();
        $conn->close();

        return $result;
    }

    public static function getPlayerById($playerId){
        $result = [];

        $conn = establishConnection();


        $sql = "SELECT * FROM players WHERE kmk_id = ?";

        $stmt = $conn->prepare($sql);
        $stmt->bind_param("i", $playerId);
        $stmt->execute();
        
        $data = $stmt->get_result();

        if($data->num_rows > 0){
            $result = $data->fetch_assoc();
        }

        $stmt->close();
        $conn->close();

        return $result;
    }

    public function updatePlayerData($kmkID){
        $status=false;
        // Create connection
        $conn = establishConnection();

        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        // Prepare SQL statement
        $sql = "UPDATE players SET fname=?, mname=?, lname=?, age=?, gender=?, dob=?, sport=?, sub_sport=?, mobile=?, email=?, password=?, weight=?, height=?, district=?, taluka=?, village=?, caste=?, parent_fname=?, parent_lname=?, parent_mobile=?, coach_name=?, coach_mobile=?, coach_address=? WHERE kmk_id=?";

        $stmt = $conn->prepare($sql);

        // Bind parameters
        $stmt->bind_param(
            "sssssssssssssssssssssssi",
            $this->fname,
            $this->mname,
            $this->lname,
            $this->age,
            $this->gender,
            $this->dob,
            $this->sport,
            $this->sub_sport,
            $this->mobile,
            $this->email,
            $this->password,
            $this->weight,
            $this->height,
            $this->district,
            $this->taluka,
            $this->village,
            $this->caste,
            $this->parent_fname,
            $this->parent_lname,
            $this->parent_mobile,
            $this->coach_name,
            $this->coach_mobile,
            $this->coach_address,
            $kmkID
        );

        // Execute the statement
        $stmt->execute();

        if($stmt->affected_rows > 0){
            $result = true;
        }
        // Close connection
        $stmt->close();
        $conn->close();

        return $result;
    }

    public static function loginPlayer($loginData) {
        $conn = establishConnection();
        $result=[];
        
        // Prepare the query
        $query = "SELECT * FROM players where email=? or kmk_id=?";
        $stmt = $conn->prepare($query);
        $stmt->bind_param("ss", $loginData['email-id'], $loginData['email-id']);
        $stmt->execute();
        
        $data = $stmt->get_result();

        if($data->num_rows > 0){
            $result = $data->fetch_assoc();
        }
        
        $stmt->close();
        $conn->close();

        if($result && $loginData['password'] === $result['password']){
            return  $result;
        }else{
            return [];
        }
    }
}

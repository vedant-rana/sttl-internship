<?php

$json_string = '{"name": "John", "age": 30, "city": "New York"}';


$data = json_decode($json_string);


if ($data !== null) {
    
    print_r($data);
} else {
    echo "Failed to decode JSON.";
}
?>

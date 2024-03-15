<?php

$array = array(
    'name' => 'John Doe',
    'age' => 30,
    'city' => 'New York'
);


$json = json_encode($array);


if ($json !== false) {
    
    echo $json;
} else {
    echo "Failed to encode array to JSON.";
}
?>

<?php

$json_string = '{"number": "123456789012345678901234567890"}';


$data = json_decode($json_string, false, 512, JSON_BIGINT_AS_STRING);


if ($data !== null) {
    
    print_r($data);
} else {
    echo "Failed to decode JSON.";
}
?>

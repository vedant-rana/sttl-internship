<?php

function endsWithOn($input)
{

    return substr($input, -2);
}


$inputs = [
    "Hello",
    "Python",
    "on",
    "o"
];


foreach ($inputs as $input) {
    var_dump(endsWithOn($input));
    echo "<br/>";
}

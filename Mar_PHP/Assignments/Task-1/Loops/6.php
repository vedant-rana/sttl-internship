<?php
echo '<h1>Even numbers between 1 to 10 : </h1>';

for ($i = 1; $i <= 10; $i++) {
    if ($i % 2 == 0) {
        echo $i . " ";
    }
}

?>

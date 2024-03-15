<?php 

function check($num1,$num2){
    if($num1 >= 100 && $num2 <=200 || $num2 >= 100 && $num2 <= 200){
        return "true";
    }
    else{
        return "false";
    }
}

if(isset($_POST['num1']) && isset($_POST['num2'])) {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];
    $result = check($num1, $num2);
    echo $result;
}

?>

<form method="post" action="">
    First Num: <input type="number" name="num1"><br>
    Second Num: <input type="number" name="num2"><br>
    <input type="submit" value="Check">
</form>

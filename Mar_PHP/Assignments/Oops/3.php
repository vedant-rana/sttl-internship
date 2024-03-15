<?php
    class MyClass{
       public function factorial($num){
        if(is_int($num)){
            if($num == 1){
                return $num;
            }
            return $num * $this->factorial($num - 1);
        }else{
            return "Invalid Number";
        }
       }
    }

    $obj = new MyClass();
    echo $obj->factorial(5);
?>
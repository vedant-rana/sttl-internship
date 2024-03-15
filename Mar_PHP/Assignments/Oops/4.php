<?php
    class MyClass{
        public function sortArray($arr){
        if(is_array($arr)){
            sort($arr);
            return $arr;
        }else{
            return "Not an Array";
        }
       }
    }

    $obj = new MyClass();
    $intArr = array(11, -2, 4, 35, 0, 8, -9);
    print_r($obj->sortArray($intArr));
?>
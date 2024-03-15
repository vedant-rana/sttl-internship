<?php
    class MyClass{
        public function getDiff($date1, $date2){
            return $date1->diff($date2);
        }
    }

    $obj = new MyClass();
    $date1 = new DateTime("1981-11-03");
    $date2 = new DateTime("2013-09-04");

    $difference = $obj->getDiff($date1, $date2);
    echo "Difference : " . $difference->y . " Years, " . $difference->m . " Months, " . $difference->d . " Days";
?>
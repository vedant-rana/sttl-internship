<?php
    class MyClass{
        public $name;
        function __construct($name){
            $this->name = $name;
        }
       public function display(){
        echo "Hello All, I am " . $this->name;  
       }
    }

    $order = new MyClass("Scott");
    $order->display();
?>
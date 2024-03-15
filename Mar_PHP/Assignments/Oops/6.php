<?php
    class Calculator{    // Run this program in terminal
        public $num1, $num2;
        public function __construct($num1, $num2){
            $this->num1 = $num1;
            $this->num2 = $num2;
        }
        public function add(){
            return $this->num1 + $this->num2;
        }

        public function subtract(){
            return $this->num1 - $this->num2;
        }

        public function multiply(){
            return $this->num1 * $this->num2;
        }

        public function divide(){
            if($this->num2 == 0){
                return "Can not divide by zero";
            }
            return round($this->num1 / $this->num2, 2);
        }
    }

    function displayFormat(){
        echo "\n\n Enter your choice \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division \n 0. Exit \n\n";
    }

    $num1 = readline(" Enter first number : ");
    $num2 = readline(" Enter second number : ");
    $obj = new Calculator($num1, $num2); 
    do{
        displayFormat();
        $choice = readline(" Enter your choice : ");
        switch($choice){
            case 1:
                echo " Addition = " . $obj->add();
                break;
            case 2:
                echo " Subtraction = " . $obj->subtract();
                break;
            case 3:
                echo " Multiplication = " . $obj->multiply();
                break;
            case 4:
                echo " Division = " . $obj->divide();
                break;
            case 0:
                break;
            default:
                echo "\n\n Invalid Choice, Please enter valid choice!!";
        }
    }while($choice != 0);
?>
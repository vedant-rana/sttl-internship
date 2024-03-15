package P7_Methods;

public class Calculator {

    public int addition(int a, int b){
        int sum = a + b;
        return sum;
    }

    public int addition(int a, int b, int c){
        return a+b+c;
    }


    public static void main(String[] args) {
        Calculator c1= new Calculator();
        System.out.println("Addition of Two Numbers 5+6: "+c1.addition(5,6));
        System.out.println("5+6+7 : "+c1.addition(5,6,7));
    }
}

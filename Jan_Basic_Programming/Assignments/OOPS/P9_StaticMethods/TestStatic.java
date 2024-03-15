package P9_StaticMethods;

public class TestStatic {

    public static float squareRoot(int num){
        return (float)Math.sqrt(num);
    }

    public static void main(String[] args) {
        System.out.println("Square Root of 10 = "+squareRoot(10));
    }
}

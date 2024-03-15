package P20;

class Calculator {
    public static <T extends Number> double add(T num1, T num2) {
        return num1.doubleValue() + num2.doubleValue();
    }
}

public class TestMetaProgram {
    public static void main(String[] args) {
        double resultInt = Calculator.add(5, 10);
        double resultDouble = Calculator.add(3.5, 7.2);

        System.out.println("Sum of integers: " + resultInt);
        System.out.println("Sum of doubles: " + resultDouble);
    }
}

package P55;
// DSL for arithmetic operations
class ArithmeticDSL {
    private int result;

    public ArithmeticDSL() {
        this.result = 0;
    }

    // DSL methods for addition, subtraction, multiplication, and division
    public ArithmeticDSL add(int operand) {
        result += operand;
        return this;
    }

    public ArithmeticDSL subtract(int operand) {
        result -= operand;
        return this;
    }

    public ArithmeticDSL multiply(int operand) {
        result *= operand;
        return this;
    }

    public ArithmeticDSL divide(int operand) {
        if (operand != 0) {
            result /= operand;
        }
        return this;
    }

    // Getter for retrieving the result
    public int getResult() {
        return result;
    }
}


public class TestDSL {
    public static void main(String[] args) {
        // Example usage of the DSL
        int result = new ArithmeticDSL()
                .add(5)
                .multiply(3)
                .subtract(2)
                .divide(4)
                .getResult();

        System.out.println("DSL Result: " + result);
    }
}

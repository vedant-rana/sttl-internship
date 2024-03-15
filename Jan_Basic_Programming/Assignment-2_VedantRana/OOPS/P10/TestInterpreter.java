package P10;

// Abstract Expression
interface Expression {
    int interpret();
}

// Terminal Expression
class Number implements Expression {
    private int value;

    public Number(int value) {
        this.value = value;
    }

    @Override
    public int interpret() {
        return value;
    }
}

// Non-terminal Expression
class Addition implements Expression {
    private Expression left;
    private Expression right;

    public Addition(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public int interpret() {
        return left.interpret() + right.interpret();
    }
}



public class TestInterpreter {
    public static void main(String[] args) {
        // Represent the expression: 2 + 3
        Expression expression = new Addition(new Number(2), new Number(3));

        // Interpret and print the result
        System.out.println("Result: " + expression.interpret());
    }
}

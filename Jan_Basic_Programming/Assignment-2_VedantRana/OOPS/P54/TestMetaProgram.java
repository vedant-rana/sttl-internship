import java.util.function.Predicate;

// GenericConstraint functional interface
interface GenericConstraint<T> {
    boolean test(T value);
}

// ConstraintUtils class for building constraints
class ConstraintUtils {
    // Method to create a constraint from a lambda expression
    static <T> GenericConstraint<T> createConstraint(Predicate<T> predicate) {
        return predicate::test;
    }

    // Method to apply a constraint to a value
    static <T> boolean applyConstraint(T value, GenericConstraint<T> constraint) {
        return constraint.test(value);
    }
}

// Example usage
public class TestMetaProgram {
    public static void main(String[] args) {
        // Define constraints using lambda expressions
        GenericConstraint<Integer> positiveConstraint = ConstraintUtils.createConstraint(x -> x > 0);
        GenericConstraint<String> nonEmptyConstraint = ConstraintUtils.createConstraint(s -> !s.isEmpty());

        // Apply constraints to values
        int number = 42;
        String text = "Hello, World!";

        boolean isPositive = ConstraintUtils.applyConstraint(number, positiveConstraint);
        boolean isNonEmpty = ConstraintUtils.applyConstraint(text, nonEmptyConstraint);

        // Display results
        System.out.println("Is " + number + " positive? " + isPositive);
        System.out.println("Is \"" + text + "\" non-empty? " + isNonEmpty);
    }
}

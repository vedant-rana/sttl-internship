package P42;

public class FibonacciGenerator {

    // Generic class with a static method to compute the nth Fibonacci number
    static class FibonacciCalculator<T extends Number> {
        public T compute(int n) {
            if (n < 0) {
                throw new IllegalArgumentException("Input must be a non-negative integer.");
            }
            if (n == 0) {
                return (T) Integer.valueOf(0);
            }
            if (n == 1) {
                return (T) Integer.valueOf(1);
            }

            T[] fibArray = (T[]) new Number[n + 1];
            fibArray[0] = (T) Integer.valueOf(0);
            fibArray[1] = (T) Integer.valueOf(1);

            for (int i = 2; i <= n; i++) {
                fibArray[i] = add(fibArray[i - 1], fibArray[i - 2]);
            }

            return fibArray[n];
        }

        // Overloaded add method for different numeric types
        private T add(T a, T b) {
            if (a instanceof Integer) {
                return (T) Integer.valueOf(((Integer) a).intValue() + ((Integer) b).intValue());
            } else if (a instanceof Long) {
                return (T) Long.valueOf(((Long) a).longValue() + ((Long) b).longValue());
            } else if (a instanceof Double) {
                return (T) Double.valueOf(((Double) a).doubleValue() + ((Double) b).doubleValue());
            } else {
                throw new UnsupportedOperationException("Unsupported numeric type.");
            }
        }
    }

    public static void main(String[] args) {
        FibonacciCalculator<Integer> intFibonacci = new FibonacciCalculator<>();
        FibonacciCalculator<Long> longFibonacci = new FibonacciCalculator<>();
        FibonacciCalculator<Double> doubleFibonacci = new FibonacciCalculator<>();

        int n = 10;

        System.out.println("Fibonacci(" + n + ") [Integer]: " + intFibonacci.compute(n));
        System.out.println("Fibonacci(" + n + ") [Long]: " + longFibonacci.compute(n));
        System.out.println("Fibonacci(" + n + ") [Double]: " + doubleFibonacci.compute(n));

    }
}
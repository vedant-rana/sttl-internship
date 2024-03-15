package P56;

import java.util.Random;

public class TestQuatumComputing {

    // Classical part of Shor's algorithm
    public static int shorsAlgorithm(int numberToFactorize) {
        Random random = new Random();
        int x = random.nextInt(numberToFactorize - 2) + 2; // Random integer in [2, numberToFactorize - 1]

        int result = gcd(x, numberToFactorize);
        if (result > 1) {
            // Non-trivial factor found
            return result;
        }

        int period = findPeriod(x, numberToFactorize);

        if (period % 2 != 0) {
            // Odd period, retry with a different random x
            return shorsAlgorithm(numberToFactorize);
        }

        int candidate1 = (int) Math.pow(x, period / 2);
        int candidate2 = -candidate1;

        int factor1 = gcd(candidate1 + 1, numberToFactorize);
        int factor2 = gcd(candidate2 + 1, numberToFactorize);

        // Return one of the factors
        return (factor1 > 1) ? factor1 : factor2;
    }

    // Helper method to find the greatest common divisor (Euclidean algorithm)
    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper method to find the period using repeated squaring
    private static int findPeriod(int x, int mod) {
        int period = 1;
        int currentPower = x;

        while (currentPower != 1) {
            currentPower = (currentPower * x) % mod;
            period++;
        }

        return period;
    }

    public static void main(String[] args) {
        int numberToFactorize = 15; // Replace with the number you want to factorize

        System.out.println("Number to factorize: " + numberToFactorize);

        int factor = shorsAlgorithm(numberToFactorize);

        System.out.println("One non-trivial factor: " + factor);
    }
}

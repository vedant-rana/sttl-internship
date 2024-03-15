package P29;

import java.util.Arrays;

// Vector class representing a mathematical vector
class Vector {
    private final double[] elements;

    public Vector(double... elements) {
        this.elements = elements;
    }

    public Vector add(Vector other) {
        double[] result = new double[elements.length];
        for (int i = 0; i < elements.length; i++) {
            result[i] = elements[i] + other.elements[i];
        }
        return new Vector(result);
    }

    public Vector subtract(Vector other) {
        double[] result = new double[elements.length];
        for (int i = 0; i < elements.length; i++) {
            result[i] = elements[i] - other.elements[i];
        }
        return new Vector(result);
    }

    public Vector multiply(double scalar) {
        double[] result = new double[elements.length];
        for (int i = 0; i < elements.length; i++) {
            result[i] = elements[i] * scalar;
        }
        return new Vector(result);
    }

    public double dotProduct(Vector other) {
        double result = 0;
        for (int i = 0; i < elements.length; i++) {
            result += elements[i] * other.elements[i];
        }
        return result;
    }

    public double[] getElements() {
        return elements;
    }

    @Override
    public String toString() {
        return Arrays.toString(elements);
    }
}

// Expression template representing the operation: (v1 + v2) * scalar
class VectorExpression {
    private final Vector v1;
    private final Vector v2;
    private final double scalar;

    public VectorExpression(Vector v1, Vector v2, double scalar) {
        this.v1 = v1;
        this.v2 = v2;
        this.scalar = scalar;
    }

    public Vector evaluate() {
        return v1.add(v2).multiply(scalar);
    }
}

public class TestMathsOperations {
    public static void main(String[] args) {
        Vector v1 = new Vector(1, 2, 3);
        Vector v2 = new Vector(4, 5, 6);
        double scalar = 2.0;

        // Using expression template to represent (v1 + v2) * scalar
        VectorExpression expression = new VectorExpression(v1, v2, scalar);
        Vector result = expression.evaluate();

        System.out.println("v1: " + v1);
        System.out.println("v2: " + v2);
        System.out.println("Scalar: " + scalar);
        System.out.println("(v1 + v2) * scalar: " + result);
    }
}

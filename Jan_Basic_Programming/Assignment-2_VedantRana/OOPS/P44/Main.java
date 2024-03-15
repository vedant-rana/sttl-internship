package P44;

// Define a concept-like interface for printable objects
interface Printable {
    void print();
}

// Define a concept-like interface for comparable objects
interface Comparable<T> {
    int compareTo(T other);
}

// Define a generic class with constraints using the concept-like interfaces
class ConstrainedGenericClass<T extends Printable & Comparable<T>> {
    private T data;

    public ConstrainedGenericClass(T data) {
        this.data = data;
    }

    public void processData() {
        data.print();
        System.out.println("Comparison result: " + data.compareTo(data));
    }
}

// Implement a class that satisfies the constraints
class ExampleClass implements Printable, Comparable<ExampleClass> {
    private String value;

    public ExampleClass(String value) {
        this.value = value;
    }

    @Override
    public void print() {
        System.out.println("Printing: " + value);
    }

    @Override
    public int compareTo(ExampleClass other) {
        return this.value.compareTo(other.value);
    }
}


public class Main {
    public static void main(String[] args) {
        // Create an instance of ConstrainedGenericClass with ExampleClass
        ExampleClass example = new ExampleClass("Hello, Generics!");
        ConstrainedGenericClass<ExampleClass> genericObject = new ConstrainedGenericClass<>(example);

        // Process data using the generic object
        genericObject.processData();
    }
}

package P25;

class MyTemplate<T extends Number> {
    private T value;

    public MyTemplate(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public double square() {
        return value.doubleValue() * value.doubleValue();
    }
}

public class TestTemplate {
    public static void main(String[] args) {
        MyTemplate<Integer> intTemplate = new MyTemplate<>(5);
        System.out.println("Square of integer: " + intTemplate.square());

        // Compilation error since String is not a subclass of Number
        // MyTemplate<String> stringTemplate = new MyTemplate<>("Hello");
    }
}

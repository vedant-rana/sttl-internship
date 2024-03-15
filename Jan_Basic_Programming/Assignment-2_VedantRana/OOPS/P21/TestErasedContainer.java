package P21;

import java.util.ArrayList;
import java.util.List;

class TypeErasedContainer {
    private List<Object> elements = new ArrayList<>();

    public <T> void addElement(T element) {
        elements.add(element);
    }

    public <T> T getElement(int index, Class<T> type) {
        return type.cast(elements.get(index));
    }
}

public class TestErasedContainer {
    public static void main(String[] args) {
        TypeErasedContainer container = new TypeErasedContainer();

        container.addElement("String");
        container.addElement(42);
        container.addElement(3.14);

        String str = container.getElement(0, String.class);
        Integer integer = container.getElement(1, Integer.class);
        Double doub = container.getElement(2, Double.class);

        System.out.println("String: " + str);
        System.out.println("Integer: " + integer);
        System.out.println("Double: " + doub);
    }
}

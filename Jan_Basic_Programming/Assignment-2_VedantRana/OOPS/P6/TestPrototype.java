package P6;

// Prototype interface
interface Prototype {
    Prototype clone();
}

// ConcretePrototype
class ConcretePrototype implements Prototype {
    private String data;

    public ConcretePrototype(String data) {
        this.data = data;
    }

    @Override
    public Prototype clone() {
        return new ConcretePrototype(this.data);
    }

    public String getData() {
        return data;
    }
}


public class TestPrototype {
    public static void main(String[] args) {
        ConcretePrototype originalObject = new ConcretePrototype("Original Data");
        System.out.println("Original Object Data: " + originalObject.getData());

        ConcretePrototype clonedObject = (ConcretePrototype) originalObject.clone();
        System.out.println("Cloned Object Data: " + clonedObject.getData());
    }
}

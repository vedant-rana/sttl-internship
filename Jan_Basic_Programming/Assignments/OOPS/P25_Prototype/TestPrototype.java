package P25_Prototype;


interface Prototype {
    Prototype clone();
    void displayInfo();
}


class ConcretePrototype1 implements Prototype {
    @Override
    public Prototype clone() {
        return new ConcretePrototype1();
    }

    @Override
    public void displayInfo() {
        System.out.println("ConcretePrototype1");
    }
}

class ConcretePrototype2 implements Prototype {
    @Override
    public Prototype clone() {
        return new ConcretePrototype2();
    }

    @Override
    public void displayInfo() {
        System.out.println("ConcretePrototype2");
    }
}


public class TestPrototype {
    public static void main(String[] args) {

        Prototype prototype1 = new ConcretePrototype1();
        Prototype prototype2 = new ConcretePrototype2();


        Prototype clone1 = prototype1.clone();
        Prototype clone2 = prototype2.clone();


        clone1.displayInfo();
        clone2.displayInfo();
    }
}

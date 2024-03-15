package P3;


interface Implementor {
    void implement();
}

class ConcreteImplementorA implements Implementor {
    @Override
    public void implement() {
        System.out.println("Concrete Implementor A");
    }
}

class ConcreteImplementorB implements Implementor {
    @Override
    public void implement() {
        System.out.println("Concrete Implementor B");
    }
}

abstract class Abstraction {
    protected Implementor implementor;

    public Abstraction(Implementor implementor) {
        this.implementor = implementor;
    }

    abstract void operation();
}

class RefinedAbstraction extends Abstraction {
    public RefinedAbstraction(Implementor implementor) {
        super(implementor);
    }

    @Override
    void operation() {
        System.out.print("Refined Abstraction - ");
        implementor.implement();
    }
}


public class TestBridge {
    public static void main(String[] args) {
        Implementor implementorA = new ConcreteImplementorA();
        Implementor implementorB = new ConcreteImplementorB();

        Abstraction abstraction = new RefinedAbstraction(implementorA);
        abstraction.operation();

        abstraction = new RefinedAbstraction(implementorB);
        abstraction.operation();
    }
}

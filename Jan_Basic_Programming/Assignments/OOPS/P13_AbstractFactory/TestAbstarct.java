package P13_AbstractFactory;

interface ProductA{
    void operationA();
}

interface ProductB{
    void operationB();
}

abstract class AbstractFactory{
   abstract ProductA createProductA();
   abstract ProductB createProductB();
}

class Factory1 extends AbstractFactory{
    @Override
    ProductA createProductA() {
        return new ConcreteProductA1();
    }

    @Override
    ProductB createProductB() {
        return new ConcreteProductB1();
    }
}

class Factory2 extends AbstractFactory{
    @Override
    ProductA createProductA() {
        return new ConcreteProductA2();
    }

    @Override
    ProductB createProductB() {
        return new ConcreteProductB2();
    }
}

class ConcreteProductA1 implements ProductA{
    @Override
    public void operationA() {
        System.out.println("Product A made by Factory 1");
    }
}

class ConcreteProductA2 implements ProductA{
    @Override
    public void operationA() {
        System.out.println("Product A made by Factory 2");
    }
}

class ConcreteProductB1 implements ProductB{
    @Override
    public void operationB() {
        System.out.println("Product B made by Factory 1");
    }
}

class ConcreteProductB2 implements ProductB{
    @Override
    public void operationB() {
        System.out.println("Product B made by Factory 2");
    }
}

public class TestAbstarct {
    public static void main(String[] args) {
        AbstractFactory f1 = new Factory1();
        ProductA a1 = new ConcreteProductA1();
        ProductB b1 = new ConcreteProductB1();

        AbstractFactory f2 = new Factory2();
        ProductA a2 = new ConcreteProductA2();
        ProductB b2 = new ConcreteProductB2();

        a1.operationA();
        b1.operationB();
        a2.operationA();
        b2.operationB();
    }
}

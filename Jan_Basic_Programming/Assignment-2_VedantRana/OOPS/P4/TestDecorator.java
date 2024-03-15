package P4;

interface Component {
    void operation();
}

class ConcreteComponent implements Component {
    @Override
    public void operation() {
        System.out.println("Concrete Component operation");
    }
}

class Decorator implements Component {
    private Component component;

    public Decorator(Component component) {
        this.component = component;
    }

    @Override
    public void operation() {
        component.operation();
    }
}

class ConcreteDecoratorA extends Decorator {
    public ConcreteDecoratorA(Component component) {
        super(component);
    }

    @Override
    public void operation() {
        super.operation();
        System.out.println("Decorator A operation");
    }
}

class ConcreteDecoratorB extends Decorator {
    public ConcreteDecoratorB(Component component) {
        super(component);
    }

    @Override
    public void operation() {
        super.operation();
        System.out.println("Decorator B operation");
    }
}

public class TestDecorator {
    public static void main(String[] args) {
        Component component = new ConcreteComponent();
        component.operation();

        Component decoratedA = new ConcreteDecoratorA(component);
        decoratedA.operation();

        Component decoratedB = new ConcreteDecoratorB(component);
        decoratedB.operation();

        Component decoratedAB = new ConcreteDecoratorB(new ConcreteDecoratorA(component));
        decoratedAB.operation();
    }
}

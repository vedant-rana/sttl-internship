package P8;

// Element interface
interface Element {
    void accept(Visitor visitor);
}

// ConcreteElement
class ConcreteElementA implements Element {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    public String operationA() {
        return "ConcreteElementA operation";
    }
}

// ConcreteElement
class ConcreteElementB implements Element {
    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    public String operationB() {
        return "ConcreteElementB operation";
    }
}

// Visitor interface
interface Visitor {
    void visit(ConcreteElementA element);

    void visit(ConcreteElementB element);
}

// ConcreteVisitor
class ConcreteVisitor implements Visitor {
    @Override
    public void visit(ConcreteElementA element) {
        System.out.println("Visitor is performing operations on " + element.operationA());
    }

    @Override
    public void visit(ConcreteElementB element) {
        System.out.println("Visitor is performing operations on " + element.operationB());
    }
}

// ObjectStructure
class ObjectStructure {
    private Element[] elements;

    public ObjectStructure() {
        this.elements = new Element[]{new ConcreteElementA(), new ConcreteElementB()};
    }

    public void accept(Visitor visitor) {
        for (Element element : elements) {
            element.accept(visitor);
        }
    }
}


public class TestVisitor {
    public static void main(String[] args) {
        ObjectStructure objectStructure = new ObjectStructure();
        Visitor visitor = new ConcreteVisitor();

        objectStructure.accept(visitor);
    }
}

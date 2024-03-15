package P30_Visitor;


interface Visitor {
    void visitElementA(ElementA elementA);
    void visitElementB(ElementB elementB);
}


interface Visitable {
    void accept(Visitor visitor);
}

class ElementA implements Visitable {
    @Override
    public void accept(Visitor visitor) {
        visitor.visitElementA(this);
    }

    void operationA() {
        System.out.println("Operation A performed by ElementA");
    }
}

class ElementB implements Visitable {
    @Override
    public void accept(Visitor visitor) {
        visitor.visitElementB(this);
    }

    void operationB() {
        System.out.println("Operation B performed by ElementB");
    }
}


class ConcreteVisitor implements Visitor {
    @Override
    public void visitElementA(ElementA elementA) {
        System.out.println("Visitor is visiting ElementA");
        elementA.operationA();
    }

    @Override
    public void visitElementB(ElementB elementB) {
        System.out.println("Visitor is visiting ElementB");
        elementB.operationB();
    }
}



public class TestVisitor {
    public static void main(String[] args) {

        ElementA elementA = new ElementA();
        ElementB elementB = new ElementB();


        Visitor visitor = new ConcreteVisitor();


        elementA.accept(visitor);
        elementB.accept(visitor);
    }
}

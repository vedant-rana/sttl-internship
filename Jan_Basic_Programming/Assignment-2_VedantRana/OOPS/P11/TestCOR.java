package P11;

// Handler interface
interface Handler {
    void handleRequest(int request);
}

// ConcreteHandler
class ConcreteHandlerA implements Handler {
    private Handler successor;

    @Override
    public void handleRequest(int request) {
        if (request <= 10) {
            System.out.println("ConcreteHandlerA handling request: " + request);
        } else if (successor != null) {
            successor.handleRequest(request);
        }
    }

    public void setSuccessor(Handler successor) {
        this.successor = successor;
    }
}

// ConcreteHandler
class ConcreteHandlerB implements Handler {
    private Handler successor;

    @Override
    public void handleRequest(int request) {
        if (request > 10 && request <= 20) {
            System.out.println("ConcreteHandlerB handling request: " + request);
        } else if (successor != null) {
            successor.handleRequest(request);
        }
    }

    public void setSuccessor(Handler successor) {
        this.successor = successor;
    }
}



public class TestCOR {
    public static void main(String[] args) {
        Handler handlerA = new ConcreteHandlerA();
        Handler handlerB = new ConcreteHandlerB();

        // Set up the chain
        ((ConcreteHandlerA) handlerA).setSuccessor(handlerB);

        // Make requests
        handlerA.handleRequest(5);
        handlerA.handleRequest(15);
        handlerA.handleRequest(25);
    }
}

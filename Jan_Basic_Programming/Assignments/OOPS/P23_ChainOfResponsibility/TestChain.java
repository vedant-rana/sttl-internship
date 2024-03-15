package P23_ChainOfResponsibility;


interface Handler {
    void handleRequest(Request request);
}


class Request {
    private String content;

    public Request(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }
}


class ConcreteHandler1 implements Handler {
    private Handler nextHandler;

    public void setNextHandler(Handler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void handleRequest(Request request) {
        if (request.getContent().contains("keyword1")) {
            System.out.println("Handler 1 processed the request: " + request.getContent());
        } else if (nextHandler != null) {
            nextHandler.handleRequest(request);
        } else {
            System.out.println("No handler can process the request.");
        }
    }
}

class ConcreteHandler2 implements Handler {
    private Handler nextHandler;

    public void setNextHandler(Handler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void handleRequest(Request request) {
        if (request.getContent().contains("keyword2")) {
            System.out.println("Handler 2 processed the request: " + request.getContent());
        } else if (nextHandler != null) {
            nextHandler.handleRequest(request);
        } else {
            System.out.println("No handler can process the request.");
        }
    }
}



public class TestChain {
    public static void main(String[] args) {
        ConcreteHandler1 handler1 = new ConcreteHandler1();
        ConcreteHandler2 handler2 = new ConcreteHandler2();

        
        handler1.setNextHandler(handler2);

        Request request1 = new Request("Request with keyword1");
        Request request2 = new Request("Request with keyword2");
        Request request3 = new Request("Request with keyword3");

        handler1.handleRequest(request1);
        handler1.handleRequest(request2);
        handler1.handleRequest(request3);
    }
}

package P9;

// Subject interface
interface RealSubject {
    void request();
}

// RealSubject
class RealSubjectImpl implements RealSubject {
    @Override
    public void request() {
        System.out.println("RealSubject handling request");
    }
}

// Proxy
class Proxy implements RealSubject {
    private RealSubject realSubject;

    @Override
    public void request() {
        if (realSubject == null) {
            realSubject = new RealSubjectImpl();
        }
        System.out.println("Proxy handling request");
        realSubject.request();
    }
}


public class TestProxy {
    public static void main(String[] args) {
        RealSubject subject = new Proxy();

        // First request - Proxy initializes RealSubject
        subject.request();

        // Subsequent requests - Proxy uses existing RealSubject
        subject.request();
    }
}

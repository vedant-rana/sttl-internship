package P28_Adapter;

interface Target {
    void request();
}


class Adaptee {
    public void specificRequest() {
        System.out.println("Adaptee's specific request");
    }
}

class Adapter implements Target {
    private Adaptee adaptee;

    public Adapter(Adaptee adaptee) {
        this.adaptee = adaptee;
    }

    @Override
    public void request() {
        adaptee.specificRequest();
    }
}



public class TestAdapter {
    public static void main(String[] args) {

        Adaptee adaptee = new Adaptee();

        Target targetAdapter = new Adapter(adaptee);

        targetAdapter.request();
    }
}

package P2;

class Memento {
    private String state;

    public Memento(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }
}

class Originator {
    private String state;

    public void setState(String state) {
        this.state = state;
    }

    public Memento save() {
        return new Memento(state);
    }

    public void restore(Memento memento) {
        state = memento.getState();
    }

    public void printState() {
        System.out.println("Current State: " + state);
    }
}


public class TestMemento {
    public static void main(String[] args) {
        Originator originator = new Originator();
        originator.setState("State1");

        Memento memento = originator.save();

        originator.setState("State2");
        originator.printState();

        originator.restore(memento);
        originator.printState();
    }
}

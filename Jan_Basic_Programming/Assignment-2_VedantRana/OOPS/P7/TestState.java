package P7;
// State interface
interface State {
    void handle();
}

// ConcreteState
class ConcreteStateA implements State {
    @Override
    public void handle() {
        System.out.println("Handling state A");
    }
}

// ConcreteState
class ConcreteStateB implements State {
    @Override
    public void handle() {
        System.out.println("Handling state B");
    }
}

// Context
class Context {
    private State currentState;

    public void setState(State state) {
        this.currentState = state;
    }

    public void request() {
        currentState.handle();
    }
}


public class TestState {
    public static void main(String[] args) {
        Context context = new Context();

        State stateA = new ConcreteStateA();
        context.setState(stateA);
        context.request();

        State stateB = new ConcreteStateB();
        context.setState(stateB);
        context.request();
    }
}

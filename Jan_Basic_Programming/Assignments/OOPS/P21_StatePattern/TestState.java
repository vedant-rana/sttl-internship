package P21_StatePattern;


interface State{
    void displayState();
}

class StateA implements State{
    @Override
    public void displayState() {
        System.out.println("State of class changed to State A.");
    }
}

class StateB implements State{
    @Override
    public void displayState() {
        System.out.println("State of Class changed to State B.");
    }
}

class Context implements State{
    private State state;

    public void setState(State state) {
        this.state = state;
    }

    public State getState() {
        return state;
    }

    @Override
    public void displayState() {
        state.displayState();
    }
}
public class TestState {
    public static void main(String[] args) {
        State s1 = new StateA();
        State s2 = new StateB();
        Context c1 = new Context();

        c1.setState(s1);
        c1.displayState();
        c1.setState(s2);
        c1.displayState();

    }
}

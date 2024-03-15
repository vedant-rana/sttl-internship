package P36_StatePattern;

interface TrafficLightState{
    void handleState(TrafficLight s);
}

class RedLight implements TrafficLightState{
    @Override
    public void handleState(TrafficLight s) {
        System.out.println("Traffic light is red.");
        s.setCurrentState(new YellowLight());
    }
}

class YellowLight implements TrafficLightState{
    @Override
    public void handleState(TrafficLight s) {
        System.out.println("Traffic light is Yellow.");
        s.setCurrentState(new GreenLight());
    }
}

class GreenLight implements TrafficLightState{
    @Override
    public void handleState(TrafficLight s) {
        System.out.println("Traffic light is Green.");
        s.setCurrentState(new RedLight());
    }
}

class TrafficLight{
    private TrafficLightState currentState;

    TrafficLight(){
        this.currentState = new RedLight();
    }

    public void setCurrentState(TrafficLightState s){
        this.currentState = s;
    }

    public void changeState(){
        currentState.handleState(this);
    }
}

public class TestTrafficState {
    public static void main(String[] args) {
        TrafficLight t1 = new TrafficLight();

        t1.changeState();
        t1.changeState();
        t1.changeState();
        t1.changeState();
    }
}

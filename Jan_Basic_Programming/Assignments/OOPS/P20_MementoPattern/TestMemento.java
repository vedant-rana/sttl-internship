package P20_MementoPattern;

import java.util.ArrayList;
import java.util.List;

class Memento{
    private String state;
    public Memento(String state){
        this.state = state;
    }

    public String getState(){
        return state;
    }

}

class CareTaker{
    private List<Memento> mementoList = new ArrayList<>();

    public void add(Memento state){
        mementoList.add(state);
    }

    public Memento get(int index){
        return mementoList.get(index);
    }
}

class Originator{
    private String state;

    public void setState(String state){
        this.state = state;
    }

    public String getState(){
        return state;
    }

    public Memento saveStateToMemento(){
        return new Memento(state);
    }

    public void getStateFromMemento(Memento memento){
        state = memento.getState();
    }
}

public class TestMemento {
    public static void main(String[] args) {
        Originator originator = new Originator();
        CareTaker careTaker = new CareTaker();

        originator.setState("State1");
        originator.setState("State2");
        careTaker.add(originator.saveStateToMemento());

        originator.setState("State3");
        careTaker.add(originator.saveStateToMemento());

        System.out.println("Current State : "+originator.getState());

        originator.getStateFromMemento(careTaker.get(0));
        System.out.println("First saved State : "+ originator.getState());
    }
}

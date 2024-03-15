package P29_Mediator;


interface Mediator {
    void sendMessage(Colleague colleague, String message);
}


class Colleague {
    private Mediator mediator;
    private String name;

    public Colleague(Mediator mediator, String name) {
        this.mediator = mediator;
        this.name = name;
    }

    public void sendMessage(String message) {
        System.out.println(name + " sends message: " + message);
        mediator.sendMessage(this, message);
    }

    public void receiveMessage(String message) {
        System.out.println(name + " receives message: " + message);
    }
}


class ConcreteMediator implements Mediator {
    private Colleague colleague1;
    private Colleague colleague2;

    public void setColleagues(Colleague colleague1, Colleague colleague2) {
        this.colleague1 = colleague1;
        this.colleague2 = colleague2;
    }

    @Override
    public void sendMessage(Colleague colleague, String message) {
        if (colleague == colleague1) {
            colleague2.receiveMessage(message);
        } else if (colleague == colleague2) {
            colleague1.receiveMessage(message);
        }
    }
}



public class TestMediator {
    public static void main(String[] args) {
        ConcreteMediator mediator = new ConcreteMediator();

        Colleague colleague1 = new Colleague(mediator, "Colleague 1");
        Colleague colleague2 = new Colleague(mediator, "Colleague 2");

        mediator.setColleagues(colleague1, colleague2);

        colleague1.sendMessage("Hello from Colleague 1!");
        colleague2.sendMessage("Hi from Colleague 2!");
    }
}

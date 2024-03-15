package P5;
// Command interface
interface Command {
    void execute();
}

// ConcreteCommand
class ConcreteCommandA implements Command {
    private Receiver receiver;

    public ConcreteCommandA(Receiver receiver) {
        this.receiver = receiver;
    }

    @Override
    public void execute() {
        receiver.actionA();
    }
}

// ConcreteCommand
class ConcreteCommandB implements Command {
    private Receiver receiver;

    public ConcreteCommandB(Receiver receiver) {
        this.receiver = receiver;
    }

    @Override
    public void execute() {
        receiver.actionB();
    }
}

// Receiver
class Receiver {
    public void actionA() {
        System.out.println("Receiver performing action A");
    }

    public void actionB() {
        System.out.println("Receiver performing action B");
    }
}

// Invoker
class Invoker {
    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void executeCommand() {
        command.execute();
    }
}


public class TestCommand {
    public static void main(String[] args) {
        Receiver receiver = new Receiver();
        Command commandA = new ConcreteCommandA(receiver);
        Command commandB = new ConcreteCommandB(receiver);

        Invoker invoker = new Invoker();

        invoker.setCommand(commandA);
        invoker.executeCommand();

        invoker.setCommand(commandB);
        invoker.executeCommand();
    }
}

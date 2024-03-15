package P32_Command;


interface Command {
    void execute();
}


class TurnOnCommand implements Command {
    private Device device;

    public TurnOnCommand(Device device) {
        this.device = device;
    }

    @Override
    public void execute() {
        device.turnOn();
    }
}

class TurnOffCommand implements Command {
    private Device device;

    public TurnOffCommand(Device device) {
        this.device = device;
    }

    @Override
    public void execute() {
        device.turnOff();
    }
}


interface Device {
    void turnOn();
    void turnOff();
}


class Television implements Device {
    @Override
    public void turnOn() {
        System.out.println("Turning on the Television");
    }

    @Override
    public void turnOff() {
        System.out.println("Turning off the Television");
    }
}

class RemoteControl {
    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void pressButton() {
        command.execute();
    }
}


public class TestDevices {
    public static void main(String[] args) {

        Device television = new Television();

        Command turnOnCommand = new TurnOnCommand(television);
        Command turnOffCommand = new TurnOffCommand(television);

        RemoteControl remoteControl = new RemoteControl();

        remoteControl.setCommand(turnOnCommand);
        remoteControl.pressButton();

        remoteControl.setCommand(turnOffCommand);
        remoteControl.pressButton();
    }
}

package P47_Command;


interface Command {
    void execute();
}


class TurnOnLightsCommand implements Command {
    private SmartHomeDevice lights;

    public TurnOnLightsCommand(SmartHomeDevice lights) {
        this.lights = lights;
    }

    @Override
    public void execute() {
        lights.turnOn();
    }
}

class TurnOffACCommand implements Command {
    private SmartHomeDevice airConditioner;

    public TurnOffACCommand(SmartHomeDevice airConditioner) {
        this.airConditioner = airConditioner;
    }

    @Override
    public void execute() {
        airConditioner.turnOff();
    }
}


interface SmartHomeDevice {
    void turnOn();
    void turnOff();
}


class Lights implements SmartHomeDevice {
    @Override
    public void turnOn() {
        System.out.println("Lights are ON");
    }

    @Override
    public void turnOff() {
        System.out.println("Lights are OFF");
    }
}

class AirConditioner implements SmartHomeDevice {
    @Override
    public void turnOn() {
        System.out.println("Air Conditioner is ON");
    }

    @Override
    public void turnOff() {
        System.out.println("Air Conditioner is OFF");
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




public class TestRemote {
    public static void main(String[] args) {
         SmartHomeDevice lights = new Lights();
        SmartHomeDevice airConditioner = new AirConditioner();


        Command turnOnLightsCommand = new TurnOnLightsCommand(lights);
        Command turnOffACCommand = new TurnOffACCommand(airConditioner);


        RemoteControl remoteControl = new RemoteControl();


        remoteControl.setCommand(turnOnLightsCommand);
        remoteControl.pressButton();


        remoteControl.setCommand(turnOffACCommand);
        remoteControl.pressButton();
    }
}

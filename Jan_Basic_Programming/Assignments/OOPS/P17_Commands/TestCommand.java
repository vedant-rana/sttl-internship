package P17_Commands;

abstract class Command{
    abstract void execCommand();
}

class TurnOnCommand extends Command{
    Light l;
    TurnOnCommand(Light l){
        this.l=l;
    }

    @Override
    void execCommand() {
        this.l.switchOn();
    }
}

class TurnOffCommand extends Command{
    Light l;
    TurnOffCommand(Light l){
        this.l=l;
    }

    @Override
    void execCommand() {
        this.l.switchOff();
    }
}

class Controller{
    Command cmd;

    Controller(Command cmd){
        this.cmd= cmd;
    }

    void setCommand(Command cmd){
        this.cmd= cmd;
    }

    void pressButton(){
        cmd.execCommand();
    }
}

class Light{
    void switchOn(){
        System.out.println("Light Turned : ON");
    }
    void switchOff(){
        System.out.println("Light Turned : OFF");
    }
}

public class TestCommand {
    public static void main(String[] args) {
        Light l1= new Light();
        Command cm1 = new TurnOnCommand(l1);
        Controller controller1 = new Controller(cm1);
        controller1.pressButton();

        Controller controller2 = new Controller(new TurnOffCommand(l1));
        controller2.pressButton();
    }
}

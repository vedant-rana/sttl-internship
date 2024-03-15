package P11_Composition;

class Engine{
    String name;

    Engine(String name){
        this.name= name;
    }

    public void start(){
        System.out.println(this.name+" Engine started.");
    }
}

class Car{
    String carName;
    Engine e1;

    Car(String name, Engine en1){
        this.carName= name;
        this.e1 = en1;
    }

    public void startCar(){
        System.out.println(this.carName+" is Starting.");
        e1.start();
    }
}

public class TestComposition {
    public static void main(String[] args) {
        Engine e = new Engine("Turbo");
        Car c1 = new Car("Sonet", e);

        c1.startCar();
    }
}

package P35_Factory;



interface Vehicle {
    void start();
    void stop();
}


class Car implements Vehicle {
    @Override
    public void start() {
        System.out.println("Car starting...");
    }

    @Override
    public void stop() {
        System.out.println("Car stopping...");
    }
}

class Motorcycle implements Vehicle {
    @Override
    public void start() {
        System.out.println("Motorcycle starting...");
    }

    @Override
    public void stop() {
        System.out.println("Motorcycle stopping...");
    }
}


interface VehicleFactory {
    Vehicle createVehicle();
}


class CarFactory implements VehicleFactory {
    @Override
    public Vehicle createVehicle() {
        return new Car();
    }
}

class MotorcycleFactory implements VehicleFactory {
    @Override
    public Vehicle createVehicle() {
        return new Motorcycle();
    }
}

public class TestFactory {
    public static void main(String[] args) {
        VehicleFactory carFactory = new CarFactory();
        Vehicle car = carFactory.createVehicle();

        VehicleFactory motorcycleFactory = new MotorcycleFactory();
        Vehicle motorcycle = motorcycleFactory.createVehicle();

        car.start();
        car.stop();

        System.out.println();

        motorcycle.start();
        motorcycle.stop();
    }
}

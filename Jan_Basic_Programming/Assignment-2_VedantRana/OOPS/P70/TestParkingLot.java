package P70;

import java.util.HashMap;
import java.util.Map;

class ParkingLot {
    private Map<Ticket, Vehicle> parkingMap;
    private double hourlyRate;

    public ParkingLot(double hourlyRate) {
        this.parkingMap = new HashMap<>();
        this.hourlyRate = hourlyRate;
    }

    public Ticket parkVehicle(Vehicle vehicle) {
        Ticket ticket = new Ticket();
        parkingMap.put(ticket, vehicle);
        return ticket;
    }

    public Vehicle retrieveVehicle(Ticket ticket) {
        return parkingMap.remove(ticket);
    }

    public double calculateParkingFee(Ticket ticket, int hoursParked) {
        Vehicle vehicle = parkingMap.get(ticket);
        return hourlyRate * hoursParked * vehicle.getRateMultiplier();
    }
}

class Vehicle {
    private String licensePlate;
    private String type;
    private double rateMultiplier;

    public Vehicle(String licensePlate, String type, double rateMultiplier) {
        this.licensePlate = licensePlate;
        this.type = type;
        this.rateMultiplier = rateMultiplier;
    }

    public double getRateMultiplier() {
        return rateMultiplier;
    }

    public String getLicensePlate() {
        return licensePlate;
    }
}

class Ticket {
    // Can include additional ticket information if needed
}

public class TestParkingLot {
    public static void main(String[] args) {
        ParkingLot parkingLot = new ParkingLot(5.0);

        Vehicle car = new Vehicle("ABC123", "Car", 1.0);
        Vehicle motorcycle = new Vehicle("XYZ789", "Motorcycle", 0.7);

        Ticket carTicket = parkingLot.parkVehicle(car);
        Ticket motorcycleTicket = parkingLot.parkVehicle(motorcycle);

        // Simulating time passing (hours parked)
        int carHoursParked = 2;
        int motorcycleHoursParked = 1;

        double carFee = parkingLot.calculateParkingFee(carTicket, carHoursParked);
        double motorcycleFee = parkingLot.calculateParkingFee(motorcycleTicket, motorcycleHoursParked);

        System.out.println("Car Parking Fee: $" + carFee);
        System.out.println("Motorcycle Parking Fee: $" + motorcycleFee);

        // Retrieving vehicles
        Vehicle retrievedCar = parkingLot.retrieveVehicle(carTicket);
        Vehicle retrievedMotorcycle = parkingLot.retrieveVehicle(motorcycleTicket);

        System.out.println("Retrieved Car License Plate: " + retrievedCar.getLicensePlate());
        System.out.println("Retrieved Motorcycle License Plate: " + retrievedMotorcycle.getLicensePlate());
    }
}

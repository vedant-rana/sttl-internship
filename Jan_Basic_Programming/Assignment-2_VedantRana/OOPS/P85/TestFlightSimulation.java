package P85;

import java.util.ArrayList;
import java.util.List;

class Aircraft {
    private String model;
    private int capacity;
    private boolean inFlight;

    public Aircraft(String model, int capacity) {
        this.model = model;
        this.capacity = capacity;
        this.inFlight = false;
    }

    public String getModel() {
        return model;
    }

    public int getCapacity() {
        return capacity;
    }

    public boolean isInFlight() {
        return inFlight;
    }

    public void takeOff() {
        inFlight = true;
    }

    public void land() {
        inFlight = false;
    }
}

class Airport {
    private String name;
    private List<Aircraft> availableAircraft;

    public Airport(String name) {
        this.name = name;
        this.availableAircraft = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void addAircraft(Aircraft aircraft) {
        availableAircraft.add(aircraft);
    }

    public List<Aircraft> getAvailableAircraft() {
        return availableAircraft;
    }
}

class Flight {
    private String flightNumber;
    private Airport departureAirport;
    private Airport destinationAirport;
    private Aircraft aircraft;

    public Flight(String flightNumber, Airport departureAirport, Airport destinationAirport, Aircraft aircraft) {
        this.flightNumber = flightNumber;
        this.departureAirport = departureAirport;
        this.destinationAirport = destinationAirport;
        this.aircraft = aircraft;
    }

    public String getFlightNumber() {
        return flightNumber;
    }

    public Airport getDepartureAirport() {
        return departureAirport;
    }

    public Airport getDestinationAirport() {
        return destinationAirport;
    }

    public Aircraft getAircraft() {
        return aircraft;
    }
}


public class TestFlightSimulation {
    public static void main(String[] args) {
        Airport airport1 = new Airport("Airport A");
        Airport airport2 = new Airport("Airport B");

        Aircraft aircraft1 = new Aircraft("Boeing 737", 150);
        Aircraft aircraft2 = new Aircraft("Airbus A320", 120);

        airport1.addAircraft(aircraft1);
        airport2.addAircraft(aircraft2);

        Flight flight1 = new Flight("FL001", airport1, airport2, aircraft1);
        Flight flight2 = new Flight("FL002", airport2, airport1, aircraft2);

        System.out.println("Flight " + flight1.getFlightNumber() + " from " +
                flight1.getDepartureAirport().getName() + " to " +
                flight1.getDestinationAirport().getName() + " with " +
                flight1.getAircraft().getModel());

        System.out.println("Flight " + flight2.getFlightNumber() + " from " +
                flight2.getDepartureAirport().getName() + " to " +
                flight2.getDestinationAirport().getName() + " with " +
                flight2.getAircraft().getModel());

        aircraft1.takeOff();
        aircraft2.takeOff();

        System.out.println("Aircraft " + aircraft1.getModel() + " is in flight: " + aircraft1.isInFlight());
        System.out.println("Aircraft " + aircraft2.getModel() + " is in flight: " + aircraft2.isInFlight());

        aircraft1.land();
        aircraft2.land();

        System.out.println("Aircraft " + aircraft1.getModel() + " is in flight: " + aircraft1.isInFlight());
        System.out.println("Aircraft " + aircraft2.getModel() + " is in flight: " + aircraft2.isInFlight());
    }
}

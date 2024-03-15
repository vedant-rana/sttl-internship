package P94;

import java.util.ArrayList;
import java.util.List;

class Destination {
    private String destinationName;
    private String description;

    public Destination(String destinationName, String description) {
        this.destinationName = destinationName;
        this.description = description;
    }

    public String getDestinationName() {
        return destinationName;
    }

    public String getDescription() {
        return description;
    }
}

class Itinerary {
    private List<Destination> destinations;

    public Itinerary() {
        this.destinations = new ArrayList<>();
    }

    public void addDestination(Destination destination) {
        destinations.add(destination);
    }

    public void generateItinerary() {
        System.out.println("Travel Itinerary:");
        for (int i = 0; i < destinations.size(); i++) {
            Destination destination = destinations.get(i);
            System.out.println((i + 1) + ". " + destination.getDestinationName());
            System.out.println("   Description: " + destination.getDescription());
            System.out.println("----------------------");
        }
    }
}

class Traveler {
    private String travelerName;
    private Itinerary itinerary;

    public Traveler(String travelerName) {
        this.travelerName = travelerName;
        this.itinerary = new Itinerary();
    }

    public void planTrip(Destination destination) {
        itinerary.addDestination(destination);
    }

    public void viewItinerary() {
        System.out.println("Itinerary for " + travelerName + ":");
        itinerary.generateItinerary();
    }
}


public class TestTravelPlanning {
    public static void main(String[] args) {

        Destination destination1 = new Destination("Paris", "City of Lights");
        Destination destination2 = new Destination("Tokyo", "Metropolitan Bliss");
        Destination destination3 = new Destination("New York", "The Big Apple");


        Traveler traveler1 = new Traveler("Alice");
        Traveler traveler2 = new Traveler("Bob");


        traveler1.planTrip(destination1);
        traveler1.planTrip(destination2);
        traveler2.planTrip(destination2);
        traveler2.planTrip(destination3);


        traveler1.viewItinerary();
        traveler2.viewItinerary();
    }
}

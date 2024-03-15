package P67;

import java.util.ArrayList;
import java.util.List;

class Flight {
    private String flightNumber;
    private int totalSeats;
    private List<Reservation> reservations;

    public Flight(String flightNumber, int totalSeats) {
        this.flightNumber = flightNumber;
        this.totalSeats = totalSeats;
        this.reservations = new ArrayList<>();
    }

    public String getFlightNumber() {
        return flightNumber;
    }

    public int getTotalSeats() {
        return totalSeats;
    }

    public int getAvailableSeats() {
        return totalSeats - reservations.size();
    }

    public boolean bookSeat(Passenger passenger) {
        if (getAvailableSeats() > 0) {
            Reservation reservation = new Reservation(passenger, this);
            reservations.add(reservation);
            return true;
        } else {
            System.out.println("Sorry, the flight is fully booked.");
            return false;
        }
    }

    public boolean cancelReservation(Reservation reservation) {
        if (reservations.contains(reservation)) {
            reservations.remove(reservation);
            return true;
        } else {
            System.out.println("Reservation not found.");
            return false;
        }
    }
}

class Passenger {
    private String passengerName;

    public Passenger(String passengerName) {
        this.passengerName = passengerName;
    }

    public String getPassengerName() {
        return passengerName;
    }
}

class Reservation {
    private Passenger passenger;
    private Flight flight;

    public Reservation(Passenger passenger, Flight flight) {
        this.passenger = passenger;
        this.flight = flight;
    }

    public Passenger getPassenger() {
        return passenger;
    }

    public Flight getFlight() {
        return flight;
    }
}


public class TestFlightReservation {
    public static void main(String[] args) {
        Flight flight = new Flight("ABC123", 50);

        Passenger passenger1 = new Passenger("John Doe");
        Passenger passenger2 = new Passenger("Jane Smith");

        // Booking seats
        flight.bookSeat(passenger1);
        flight.bookSeat(passenger2);

        // Display available seats
        System.out.println("Available seats on Flight " + flight.getFlightNumber() + ": " + flight.getAvailableSeats());

        // Cancel reservation
        Reservation reservation = new Reservation(passenger1, flight);
        flight.cancelReservation(reservation);

        // Display available seats after cancellation
        System.out.println("Available seats on Flight " + flight.getFlightNumber() + " after cancellation: " + flight.getAvailableSeats());
    }
}

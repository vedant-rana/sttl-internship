package P79;

import java.util.ArrayList;
import java.util.List;

class Room {
    private int number;
    private boolean available;

    public Room(int number) {
        this.number = number;
        this.available = true;
    }

    public int getNumber() {
        return number;
    }

    public boolean isAvailable() {
        return available;
    }

    public void book() {
        available = false;
    }

    public void checkOut() {
        available = true;
    }
}

class Guest {
    private String name;
    private String contactNumber;

    public Guest(String name, String contactNumber) {
        this.name = name;
        this.contactNumber = contactNumber;
    }

    public String getName() {
        return name;
    }

    public String getContactNumber() {
        return contactNumber;
    }
}

class Reservation {
    private Room room;
    private Guest guest;
    private String checkInDate;
    private String checkOutDate;

    public Reservation(Room room, Guest guest, String checkInDate, String checkOutDate) {
        this.room = room;
        this.guest = guest;
        this.checkInDate = checkInDate;
        this.checkOutDate = checkOutDate;
    }

    public Room getRoom() {
        return room;
    }

    public Guest getGuest() {
        return guest;
    }

    public String getCheckInDate() {
        return checkInDate;
    }

    public String getCheckOutDate() {
        return checkOutDate;
    }
}

class Hotel {
    private List<Room> rooms;
    private List<Reservation> reservations;

    public Hotel(int numberOfRooms) {
        this.rooms = new ArrayList<>();
        this.reservations = new ArrayList<>();

        for (int i = 1; i <= numberOfRooms; i++) {
            rooms.add(new Room(i));
        }
    }

    public List<Room> getAvailableRooms() {
        List<Room> availableRooms = new ArrayList<>();
        for (Room room : rooms) {
            if (room.isAvailable()) {
                availableRooms.add(room);
            }
        }
        return availableRooms;
    }

    public Reservation bookRoom(Guest guest, String checkInDate, String checkOutDate) {
        List<Room> availableRooms = getAvailableRooms();
        if (!availableRooms.isEmpty()) {
            Room roomToBook = availableRooms.get(0);
            Reservation newReservation = new Reservation(roomToBook, guest, checkInDate, checkOutDate);
            roomToBook.book();
            reservations.add(newReservation);
            System.out.println("Booking successful. Room number: " + roomToBook.getNumber());
            return newReservation;
        } else {
            System.out.println("No available rooms for the specified dates.");
            return null;
        }
    }

    public void checkOutRoom(Reservation reservation) {
        Room room = reservation.getRoom();
        room.checkOut();
        reservations.remove(reservation);
        System.out.println("Check-out successful. Room number: " + room.getNumber());
    }
}


public class TestHotelReservation {
    public static void main(String[] args) {
        Hotel hotel = new Hotel(10);

        Guest guest1 = new Guest("Alice", "1234567890");
        Guest guest2 = new Guest("Bob", "9876543210");

        Reservation reservation1 = hotel.bookRoom(guest1, "2024-02-01", "2024-02-05");
        Reservation reservation2 = hotel.bookRoom(guest2, "2024-02-03", "2024-02-08");

        List<Room> availableRoomsAfterBooking = hotel.getAvailableRooms();
        System.out.println("Available rooms after bookings: " + availableRoomsAfterBooking.size());

        hotel.checkOutRoom(reservation1);

        List<Room> availableRoomsAfterCheckOut = hotel.getAvailableRooms();
        System.out.println("Available rooms after check-out: " + availableRoomsAfterCheckOut.size());
    }
}

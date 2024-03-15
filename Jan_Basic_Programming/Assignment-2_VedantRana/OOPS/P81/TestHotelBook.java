package P81;


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
    private int age;

    public Guest(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}

class Booking {
    private Room room;
    private Guest guest;
    private String checkInDate;
    private String checkOutDate;

    public Booking(Room room, Guest guest, String checkInDate, String checkOutDate) {
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
    private List<Booking> bookings;

    public Hotel(int numberOfRooms) {
        this.rooms = new ArrayList<>();
        this.bookings = new ArrayList<>();

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

    public void bookRoom(Guest guest, String checkInDate, String checkOutDate) {
        List<Room> availableRooms = getAvailableRooms();
        if (!availableRooms.isEmpty()) {
            Room roomToBook = availableRooms.get(0);
            Booking newBooking = new Booking(roomToBook, guest, checkInDate, checkOutDate);
            roomToBook.book();
            bookings.add(newBooking);
            System.out.println("Booking successful. Room number: " + roomToBook.getNumber());
        } else {
            System.out.println("No available rooms for the specified dates.");
        }
    }

    public void checkOutRoom(Room room) {
        for (Booking booking : bookings) {
            if (booking.getRoom() == room) {
                room.checkOut();
                bookings.remove(booking);
                System.out.println("Check-out successful. Room number: " + room.getNumber());
                return;
            }
        }
        System.out.println("Room not found in current bookings.");
    }
}


public class TestHotelBook{
    public static void main(String[] args) {
        Hotel hotel = new Hotel(10);

        Guest guest1 = new Guest("Alice", 28);
        Guest guest2 = new Guest("Bob", 35);

        hotel.bookRoom(guest1, "2024-02-01", "2024-02-05");
        hotel.bookRoom(guest2, "2024-02-03", "2024-02-08");

        List<Room> availableRoomsAfterBooking = hotel.getAvailableRooms();
        System.out.println("Available rooms after bookings: " + availableRoomsAfterBooking.size());

        Room roomToCheckOut = hotel.getAvailableRooms().get(0);
        hotel.checkOutRoom(roomToCheckOut);

        List<Room> availableRoomsAfterCheckOut = hotel.getAvailableRooms();
        System.out.println("Available rooms after check-out: " + availableRoomsAfterCheckOut.size());
    }

}
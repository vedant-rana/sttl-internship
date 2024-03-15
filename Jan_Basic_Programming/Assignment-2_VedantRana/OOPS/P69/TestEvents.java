package P69;

import java.util.ArrayList;
import java.util.List;

class Event {
    private String eventName;
    private String eventDate;
    private Organizer organizer;
    private List<Attendee> attendees;

    public Event(String eventName, String eventDate, Organizer organizer) {
        this.eventName = eventName;
        this.eventDate = eventDate;
        this.organizer = organizer;
        this.attendees = new ArrayList<>();
    }

    public String getEventName() {
        return eventName;
    }

    public String getEventDate() {
        return eventDate;
    }

    public Organizer getOrganizer() {
        return organizer;
    }

    public List<Attendee> getAttendees() {
        return attendees;
    }

    public void registerAttendee(Attendee attendee) {
        attendees.add(attendee);
    }

    public void sendNotification(String message) {
        for (Attendee attendee : attendees) {
            attendee.receiveNotification(message);
        }
    }
}

class Attendee {
    private String attendeeName;
    private String email;

    public Attendee(String attendeeName, String email) {
        this.attendeeName = attendeeName;
        this.email = email;
    }

    public void receiveNotification(String message) {
        System.out.println("Notification sent to " + attendeeName + " at " + email + ": " + message);
    }
}

class Organizer {
    private String organizerName;
    private String organizerEmail;

    public Organizer(String organizerName, String organizerEmail) {
        this.organizerName = organizerName;
        this.organizerEmail = organizerEmail;
    }

    public String getOrganizerName() {
        return organizerName;
    }

    public String getOrganizerEmail() {
        return organizerEmail;
    }
}


public class TestEvents {
    public static void main(String[] args) {
        Organizer organizer = new Organizer("Event Organizer", "organizer@example.com");
        Event event = new Event("Java Meetup", "2024-01-25", organizer);

        Attendee attendee1 = new Attendee("Attendee1", "attendee1@example.com");
        Attendee attendee2 = new Attendee("Attendee2", "attendee2@example.com");

        event.registerAttendee(attendee1);
        event.registerAttendee(attendee2);

        event.sendNotification("Reminder: Java Meetup on 2024-01-25");
    }
}

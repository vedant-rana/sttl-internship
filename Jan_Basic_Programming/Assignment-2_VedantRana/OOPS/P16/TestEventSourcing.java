package P16;

import java.util.ArrayList;
import java.util.List;

// Event
class Event {
    private final String type;
    private final String data;

    public Event(String type, String data) {
        this.type = type;
        this.data = data;
    }

    public String getType() {
        return type;
    }

    public String getData() {
        return data;
    }
}

// Aggregate Root
class AggregateRoot {
    private final List<Event> events = new ArrayList<>();

    public void applyEvent(Event event) {
        // Apply the event to update the state
        // In a real-world scenario, you would have specific logic for each event type
        // For simplicity, let's just print the event details here
        System.out.println("Applying event - Type: " + event.getType() + ", Data: " + event.getData());
        events.add(event);
    }

    public List<Event> getEvents() {
        return new ArrayList<>(events);
    }
}

// Command
class ChangeDataCommand {
    private final String newData;

    public ChangeDataCommand(String newData) {
        this.newData = newData;
    }

    public String getNewData() {
        return newData;
    }
}

// Command Handler
class CommandHandler {
    private final AggregateRoot aggregateRoot;

    public CommandHandler(AggregateRoot aggregateRoot) {
        this.aggregateRoot = aggregateRoot;
    }

    public void handle(ChangeDataCommand command) {
        // Generate an event and apply it to the aggregate root
        Event event = new Event("DataChanged", command.getNewData());
        aggregateRoot.applyEvent(event);
    }
}


public class TestEventSourcing {
    public static void main(String[] args) {
        AggregateRoot aggregateRoot = new AggregateRoot();
        CommandHandler commandHandler = new CommandHandler(aggregateRoot);

        // Command: Change data
        ChangeDataCommand changeDataCommand = new ChangeDataCommand("NewData");
        commandHandler.handle(changeDataCommand);

        // Retrieve events and print them
        List<Event> events = aggregateRoot.getEvents();
        System.out.println("\nEvents captured:");
        for (Event event : events) {
            System.out.println("Type: " + event.getType() + ", Data: " + event.getData());
        }
    }
}

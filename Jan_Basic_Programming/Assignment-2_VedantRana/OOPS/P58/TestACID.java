package P58;

import java.util.ArrayList;
import java.util.List;

// Mock Database class for illustration purposes
class Database {
    private final List<String> data = new ArrayList<>();

    public void insert(String item) {
        data.add(item);
    }

    public List<String> getData() {
        return new ArrayList<>(data);
    }
}

// Transaction class representing a distributed transaction
class DistributedTransaction {
    private final List<Participant> participants;

    public DistributedTransaction(List<Participant> participants) {
        this.participants = participants;
    }

    public boolean commit() {
        // Phase 1: Ask participants if they are ready to commit
        for (Participant participant : participants) {
            if (!participant.prepare()) {
                // Abort if any participant is not ready
                abort();
                return false;
            }
        }

        // Phase 2: If all participants are ready, commit the transaction
        for (Participant participant : participants) {
            participant.commit();
        }

        return true;
    }

    public void abort() {
        for (Participant participant : participants) {
            participant.abort();
        }
    }
}

// Participant interface representing a participant in the distributed transaction
interface Participant {
    boolean prepare();

    void commit();

    void abort();
}

// Concrete Participant implementation
class ConcreteParticipant implements Participant {
    private final Database database;

    public ConcreteParticipant(Database database) {
        this.database = database;
    }

    @Override
    public boolean prepare() {
        // Check if the participant is ready to commit (e.g., validate constraints)
        return true;
    }

    @Override
    public void commit() {
        // Apply changes to the database
        // In a real-world scenario, this would involve more complex logic
        database.insert("Transaction data");
    }

    @Override
    public void abort() {
        // Rollback changes if necessary
    }
}

public class TestACID {
    public static void main(String[] args) {
        // Create participants with their respective databases
        Database database1 = new Database();
        Database database2 = new Database();

        Participant participant1 = new ConcreteParticipant(database1);
        Participant participant2 = new ConcreteParticipant(database2);

        List<Participant> participants = List.of(participant1, participant2);

        // Create a distributed transaction with participants
        DistributedTransaction transaction = new DistributedTransaction(participants);

        // Perform distributed transaction (commit or abort)
        boolean transactionResult = transaction.commit();

        // Print the result
        if (transactionResult) {
            System.out.println("Transaction committed successfully.");
            System.out.println("Database 1 contents: " + database1.getData());
            System.out.println("Database 2 contents: " + database2.getData());
        } else {
            System.out.println("Transaction aborted.");
        }
    }
}

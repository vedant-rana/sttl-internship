package P22;
import java.util.HashMap;
import java.util.Map;

class TransactionalMemorySystem {
    private Map<String, Object> memory = new HashMap<>();

    public void beginTransaction() {
        // Optionally, you might want to start a new transaction context
    }

    public void commitTransaction() {
        // Optionally, you might want to commit changes made during the transaction
    }

    public void rollbackTransaction() {
        // Optionally, you might want to rollback changes made during the transaction
    }

    public void setValue(String key, Object value) {
        memory.put(key, value);
    }

    public Object getValue(String key) {
        return memory.get(key);
    }
}


public class TestSimpleMemory {
    public static void main(String[] args) {
        TransactionalMemorySystem memorySystem = new TransactionalMemorySystem();

        memorySystem.beginTransaction();
        memorySystem.setValue("name", "John");
        memorySystem.setValue("age", 30);
        memorySystem.commitTransaction();

        System.out.println("Name: " + memorySystem.getValue("name"));
        System.out.println("Age: " + memorySystem.getValue("age"));
    }
}

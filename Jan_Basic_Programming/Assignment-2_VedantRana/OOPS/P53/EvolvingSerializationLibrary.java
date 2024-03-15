package P53;

import java.lang.reflect.Field;
import java.util.HashMap;
import java.util.Map;

// Serializable annotation for marking fields that should be serialized
@interface Serializable {
}

// Serialization library with schema evolution support
public class EvolvingSerializationLibrary {

    public static String serialize(Object obj) {
        Class<?> clazz = obj.getClass();
        Map<String, Object> fieldValues = new HashMap<>();

        // Iterate through fields using reflection
        for (Field field : clazz.getDeclaredFields()) {
            if (field.isAnnotationPresent(Serializable.class)) {
                field.setAccessible(true);

                try {
                    Object value = field.get(obj);
                    fieldValues.put(field.getName(), value);
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                }
            }
        }

        // Convert field values to a serialized string (e.g., JSON, XML, etc.)
        // Here, a simple representation is used for demonstration purposes
        StringBuilder serializedData = new StringBuilder("{");
        for (Map.Entry<String, Object> entry : fieldValues.entrySet()) {
            serializedData.append(entry.getKey()).append(":").append(entry.getValue()).append(",");
        }
        serializedData.append("}");

        return serializedData.toString();
    }

    public static <T> T deserialize(String serializedData, Class<T> clazz) {
        // Implementation for deserialization
        // This is a simplified example, and in a real-world scenario,
        // you would use a proper deserialization mechanism (e.g., JSON or XML parsing)
        // and handle schema evolution changes.

        // For demonstration purposes, this example simply returns a new instance of the class.
        try {
            return clazz.newInstance();
        } catch (InstantiationException | IllegalAccessException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        // Example usage with schema evolution
        EvolvingObject oldObject = new EvolvingObject(42, "Hello");
        String serializedData = serialize(oldObject);
        System.out.println("Serialized Data: " + serializedData);

        // Simulate changes in object structure (schema evolution)
        // For example, add a new field 'newField' to the EvolvingObject class
        EvolvingObjectWithNewField newObject = deserialize(serializedData, EvolvingObjectWithNewField.class);

        // Print the result
        System.out.println("Deserialized Data: " + newObject);
    }

    static class EvolvingObject {
        @Serializable
        private int intValue;
        @Serializable
        private String stringValue;

        public EvolvingObject(int intValue, String stringValue) {
            this.intValue = intValue;
            this.stringValue = stringValue;
        }
    }

    static class EvolvingObjectWithNewField {
        @Serializable
        private int intValue;
        @Serializable
        private String stringValue;
        @Serializable
        private String newField;  // New field added for schema evolution

        // Add a constructor for deserialization
        public EvolvingObjectWithNewField() {
        }

        // Getter and setter methods for the new field
        public String getNewField() {
            return newField;
        }

        public void setNewField(String newField) {
            this.newField = newField;
        }

        // Override toString for better print representation
        @Override
        public String toString() {
            return "EvolvingObjectWithNewField{" +
                    "intValue=" + intValue +
                    ", stringValue='" + stringValue + '\'' +
                    ", newField='" + newField + '\'' +
                    '}';
        }
    }
}

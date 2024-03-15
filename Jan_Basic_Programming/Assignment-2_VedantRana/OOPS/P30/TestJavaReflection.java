package P30;

import java.lang.reflect.Field;

class Serializer {

    public static String serialize(Object obj) {
        Class<?> clazz = obj.getClass();
        StringBuilder serializedData = new StringBuilder();

        // Iterate through fields using reflection
        for (Field field : clazz.getDeclaredFields()) {
            field.setAccessible(true); // Allow access to private fields

            try {
                Object value = field.get(obj);
                String fieldName = field.getName();
                String fieldValue = (value != null) ? value.toString() : "null";

                // Append field name and value to the serialized data
                serializedData.append(fieldName).append(":").append(fieldValue).append(",");
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
        }

        return "{" + serializedData.toString() + "}";
    }
}

class ExampleObject {
    private int intValue;
    private String stringValue;
    private double doubleValue;

    public ExampleObject(int intValue, String stringValue, double doubleValue) {
        this.intValue = intValue;
        this.stringValue = stringValue;
        this.doubleValue = doubleValue;
    }
}

public class TestJavaReflection {
    public static void main(String[] args) {
        ExampleObject exampleObj = new ExampleObject(42, "Hello", 3.14);

        // Serialize the object using reflection
        String serializedData = Serializer.serialize(exampleObj);

        // Display the serialized data
        System.out.println("Serialized Data: " + serializedData);
    }
}

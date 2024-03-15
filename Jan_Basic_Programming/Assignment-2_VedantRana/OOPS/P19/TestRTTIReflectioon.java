package P19;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

class MyClass {
    private int privateField;

    public void myMethod() {
        System.out.println("Executing myMethod");
    }
}


public class TestRTTIReflectioon {
    public static void main(String[] args) {
        // Getting Class Information
        Class<?> myClass = MyClass.class;
        System.out.println("Class Name: " + myClass.getName());

        // Getting Fields
        Field[] fields = myClass.getDeclaredFields();
        System.out.println("\nFields:");
        for (Field field : fields) {
            System.out.println(field.getName() + " - " + field.getType());
        }

        // Getting Methods
        Method[] methods = myClass.getDeclaredMethods();
        System.out.println("\nMethods:");
        for (Method method : methods) {
            System.out.println(method.getName());
        }

        // Creating an instance and invoking a method using reflection
        try {
            MyClass instance = (MyClass) myClass.getDeclaredConstructor().newInstance();
            Method method = myClass.getDeclaredMethod("myMethod");
            method.invoke(instance);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

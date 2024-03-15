package P23;

final class ImmutablePerson {
    private final String name;
    private final int age;

    public ImmutablePerson(String name, int age) {
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


public class TestImutableSet {
    public static void main(String[] args) {
        ImmutablePerson person = new ImmutablePerson("Alice", 25);

        // Accessing properties
        System.out.println("Name: " + person.getName());
        System.out.println("Age: " + person.getAge());

        // Attempting to modify will result in a compilation error
        // person.setName("Bob");  // Compilation error: cannot assign a value to a final variable
    }
}

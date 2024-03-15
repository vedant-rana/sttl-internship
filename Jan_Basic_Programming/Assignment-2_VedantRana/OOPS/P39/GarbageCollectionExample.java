public class GarbageCollectionExample {
    public static void main(String[] args) {
        // Create objects
        MyClass obj1 = new MyClass(1);
        MyClass obj2 = new MyClass(2);

        // Assign obj2 to obj1, making obj1 unreferenced
        obj1 = obj2;

        // Explicitly set obj2 to null to make it unreferenced
        obj2 = null;

        // Request garbage collection
        System.gc();

        // Sleep to allow garbage collection to run (for demonstration purposes)
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class MyClass {
    private int data;

    public MyClass(int data) {
        this.data = data;
        System.out.println("Object created with data: " + data);
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println("Object with data " + data + " is being garbage collected.");
    }
}

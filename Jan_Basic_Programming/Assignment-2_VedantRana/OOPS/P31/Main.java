import java.util.ArrayList;
import java.util.List;

// Observable (Subject)
class Subject {
    private List<Observer> observers = new ArrayList<>();

    public synchronized void addObserver(Observer observer) {
        if (!observers.contains(observer)) {
            observers.add(observer);
        }
    }

    public synchronized void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    public synchronized void notifyObservers(String message) {
        for (Observer observer : observers) {
            observer.update(message);
        }
    }
}

// Observer
interface Observer {
    void update(String message);
}

// Concrete Observer
class ConcreteObserver implements Observer {
    private String name;

    public ConcreteObserver(String name) {
        this.name = name;
    }

    @Override
    public void update(String message) {
        System.out.println(name + " received message: " + message);
    }
}

public class Main {
    public static void main(String[] args) {
        Subject subject = new Subject();

        // Create and register observers
        Observer observer1 = new ConcreteObserver("Observer 1");
        Observer observer2 = new ConcreteObserver("Observer 2");
        subject.addObserver(observer1);
        subject.addObserver(observer2);

        // Notify observers concurrently
        Runnable notifyTask = () -> {
            for (int i = 0; i < 5; i++) {
                String message = "Notification " + i;
                subject.notifyObservers(message);
            }
        };

        // Create multiple threads to notify observers concurrently
        Thread thread1 = new Thread(notifyTask);
        Thread thread2 = new Thread(notifyTask);

        thread1.start();
        thread2.start();

        try {
            // Wait for threads to complete
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

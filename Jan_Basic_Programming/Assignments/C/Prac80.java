import java.util.LinkedList;

class P80 {
    private LinkedList<Integer> data;
    private int capacity;

    public P80(int capacity) {
        this.capacity = capacity;
        this.data = new LinkedList<>();
    }

    public synchronized void produce(int item) throws InterruptedException {
        while (data.size() == capacity) {
            
            wait();
        }

        
        data.add(item);
        System.out.println("Produced: " + item);
        
        notify();
    }

    public synchronized void consume() throws InterruptedException {
        while (data.isEmpty()) {
            
            wait();
        }
        
        int item = data.remove();
        System.out.println("Consumed: " + item);
        
        notify();
    }
}

class Producer extends Thread {
    private P80 P80;

    public Producer(P80 P80) {
        this.P80 = P80;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                P80.produce(i);
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer extends Thread {
    private P80 P80;

    public Consumer(P80 P80) {
        this.P80 = P80;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            try {
                P80.consume();
                Thread.sleep(1000); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }




}

public class Prac80{
    public static void main(String[] args) {
        P80 buffer = new P80(3);

        Producer producer = new Producer(buffer);
        Consumer consumer = new Consumer(buffer);

        producer.start();
        consumer.start();
    }
}

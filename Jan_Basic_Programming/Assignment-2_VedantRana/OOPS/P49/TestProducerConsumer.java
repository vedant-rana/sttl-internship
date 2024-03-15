package P49;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

// Producer class
class Producer implements Runnable {
    private final BlockingQueue<Integer> queue;

    public Producer(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= 10; i++) {
                System.out.println("Producing: " + i);
                queue.put(i);
                Thread.sleep(100);  // Simulate some processing time
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

// Consumer class
class Consumer implements Runnable {
    private final BlockingQueue<Integer> queue;

    public Consumer(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            while (true) {
                Integer item = queue.take();
                System.out.println("Consuming: " + item);
                Thread.sleep(200);  // Simulate some processing time
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class TestProducerConsumer {
    public static void main(String[] args) {
        BlockingQueue<Integer> queue = new LinkedBlockingQueue<>();

        // Creating multiple producers and consumers
        Thread producerThread1 = new Thread(new Producer(queue));
        Thread producerThread2 = new Thread(new Producer(queue));
        Thread consumerThread1 = new Thread(new Consumer(queue));
        Thread consumerThread2 = new Thread(new Consumer(queue));

        // Start the threads
        producerThread1.start();
        producerThread2.start();
        consumerThread1.start();
        consumerThread2.start();

        // Allow some time for producers and consumers to work
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Stop the threads
        producerThread1.interrupt();
        producerThread2.interrupt();
        consumerThread1.interrupt();
        consumerThread2.interrupt();
    }
}

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

class Worker implements Runnable {
    private final BlockingQueue<Runnable> taskQueue;

    public Worker(BlockingQueue<Runnable> taskQueue) {
        this.taskQueue = taskQueue;
    }

    @Override
    public void run() {
        while (true) {
            try {
                Runnable task = taskQueue.take(); // Blocking call, waits for a task
                task.run(); // Execute the task
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
    }
}

public class ThreadPool {
    private final BlockingQueue<Runnable> taskQueue;
    private final Thread[] workers;

    public ThreadPool(int poolSize) {
        this.taskQueue = new LinkedBlockingQueue<>();
        this.workers = new Thread[poolSize];

        for (int i = 0; i < poolSize; i++) {
            workers[i] = new Thread(new Worker(taskQueue));
            workers[i].start();
        }
    }

    public void submit(Runnable task) {
        try {
            taskQueue.put(task); // Blocking call, waits for space in the queue
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public void shutdown() {
        for (Thread worker : workers) {
            worker.interrupt();
        }
    }

    public static void main(String[] args) {
        ThreadPool threadPool = new ThreadPool(5);

        // Submit tasks to the thread pool
        for (int i = 0; i < 10; i++) {
            final int taskNumber = i;
            threadPool.submit(() -> {
                System.out.println("Task " + taskNumber + " executed by thread " + Thread.currentThread().getId());
            });
        }

        // Shutdown the thread pool
        threadPool.shutdown();
    }
}

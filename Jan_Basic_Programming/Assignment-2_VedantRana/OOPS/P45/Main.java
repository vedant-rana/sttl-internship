package P45;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// Task to perform computation
class ComputationTask implements Runnable, Serializable {
    private final int start;
    private final int end;
    private final int[] data;
    private final CompletableFuture<Void> completion;

    public ComputationTask(int start, int end, int[] data) {
        this.start = start;
        this.end = end;
        this.data = data;
        this.completion = new CompletableFuture<>();
    }

    @Override
    public void run() {
        for (int i = start; i < end; i++) {
            // Perform computation on data[i]
            data[i] = data[i] * 2;
        }
        completion.complete(null); // Mark the task as completed
    }

    // Check if the task is done
    public boolean isDone() {
        return completion.isDone();
    }
}

// Server to handle incoming connections and distribute tasks
class DistributedServer {
    private final int port;
    private final ExecutorService executorService;

    public DistributedServer(int port, int numThreads) {
        this.port = port;
        this.executorService = Executors.newFixedThreadPool(numThreads);
    }

    public void start() {
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server listening on port " + port);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                handleClient(clientSocket);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void handleClient(Socket clientSocket) {
        executorService.execute(() -> {
            try (ObjectInputStream inputStream = new ObjectInputStream(clientSocket.getInputStream());
                 ObjectOutputStream outputStream = new ObjectOutputStream(clientSocket.getOutputStream())) {

                // Receive computation task from client
                ComputationTask computationTask = (ComputationTask) inputStream.readObject();

                // Perform computation locally
                computationTask.run();

                // Send back the result
                outputStream.writeObject(computationTask);

            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        });
    }
}

// Client to connect to the server and send/receive tasks
class DistributedClient {
    private final String serverAddress;
    private final int serverPort;

    public DistributedClient(String serverAddress, int serverPort) {
        this.serverAddress = serverAddress;
        this.serverPort = serverPort;
    }

    public void performComputation(ComputationTask computationTask) {
        try (Socket socket = new Socket(serverAddress, serverPort);
             ObjectOutputStream outputStream = new ObjectOutputStream(socket.getOutputStream());
             ObjectInputStream inputStream = new ObjectInputStream(socket.getInputStream())) {

            // Send computation task to the server
            outputStream.writeObject(computationTask);

            // Receive the result from the server
            ComputationTask resultTask = (ComputationTask) inputStream.readObject();

            // Further processing with the result if needed
            // ...

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Initialize distributed server
        DistributedServer server = new DistributedServer(9999, 5);
        new Thread(server::start).start();

        // Initialize distributed clients
        DistributedClient client1 = new DistributedClient("localhost", 9999);
        DistributedClient client2 = new DistributedClient("localhost", 9999);

        // Example data for computation
        int[] data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // Divide the computation into tasks
        int dataSize = data.length;
        int partitionSize = dataSize / 2;

        ComputationTask task1 = new ComputationTask(0, partitionSize, data);
        ComputationTask task2 = new ComputationTask(partitionSize, dataSize, data);

        // Perform computation in parallel using distributed clients
        client1.performComputation(task1);
        client2.performComputation(task2);

        // Wait for the tasks to complete
        while (true) {
            if (task1.isDone() && task2.isDone()) {
                break;
            }
        }

        // Print the result
        System.out.println("Result after distributed computation: " + Arrays.toString(data));
    }
}

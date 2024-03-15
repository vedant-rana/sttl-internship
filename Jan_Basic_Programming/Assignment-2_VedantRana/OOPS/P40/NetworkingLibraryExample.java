import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// Message class to represent data that can be sent over the network
class Message implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private String content;

    public Message(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }
}

// Server class that listens for incoming connections
class Server {
    private ServerSocket serverSocket;
    private ExecutorService executorService;

    public Server(int port) {
        try {
            serverSocket = new ServerSocket(port);
            executorService = Executors.newCachedThreadPool();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void start() {
        System.out.println("Server started. Waiting for connections...");

        while (true) {
            try {
                Socket clientSocket = serverSocket.accept();
                handleClient(clientSocket);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void handleClient(Socket clientSocket) {
        executorService.submit(() -> {
            try (
                ObjectOutputStream out = new ObjectOutputStream(clientSocket.getOutputStream());
                ObjectInputStream in = new ObjectInputStream(clientSocket.getInputStream())
            ) {
                // Read and process messages
                while (true) {
                    Message receivedMessage = (Message) in.readObject();
                    System.out.println("Received message: " + receivedMessage.getContent());

                    // Respond to the client
                    Message responseMessage = new Message("Server says: Message received");
                    out.writeObject(responseMessage);
                    out.flush();
                }
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        });
    }
}

// Client class that connects to a server and sends/receives messages
class Client {
    private Socket socket;
    private ObjectOutputStream out;
    private ObjectInputStream in;

    public Client(String host, int port) {
        try {
            socket = new Socket(host, port);
            out = new ObjectOutputStream(socket.getOutputStream());
            in = new ObjectInputStream(socket.getInputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void sendMessage(String content) {
        try {
            // Send a message to the server
            Message message = new Message(content);
            out.writeObject(message);
            out.flush();

            // Receive a response from the server
            Message response = (Message) in.readObject();
            System.out.println("Server response: " + response.getContent());
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

public class NetworkingLibraryExample {
    public static void main(String[] args) {
        // Start the server
        Server server = new Server(8888);
        new Thread(server::start).start();

        // Create a client and send messages
        Client client = new Client("localhost", 8888);
        client.sendMessage("Hello, server!");
        client.sendMessage("How are you?");
    }
}

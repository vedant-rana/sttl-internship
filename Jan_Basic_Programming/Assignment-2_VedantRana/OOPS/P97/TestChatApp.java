package P97;


import java.util.ArrayList;
import java.util.List;

class User {
    private String userId;
    private String username;

    public User(String userId, String username) {
        this.userId = userId;
        this.username = username;
    }

    public String getUserId() {
        return userId;
    }

    public String getUsername() {
        return username;
    }
}

class Message {
    private User sender;
    private String content;

    public Message(User sender, String content) {
        this.sender = sender;
        this.content = content;
    }

    public User getSender() {
        return sender;
    }

    public String getContent() {
        return content;
    }
}

class ChatRoom {
    private List<User> users;
    private List<Message> messageHistory;

    public ChatRoom() {
        this.users = new ArrayList<>();
        this.messageHistory = new ArrayList<>();
    }

    public void addUser(User user) {
        users.add(user);
    }

    public void sendMessage(User sender, String content) {
        Message message = new Message(sender, content);
        messageHistory.add(message);

        System.out.println("[" + sender.getUsername() + "]: " + content);
    }

    public void viewMessageHistory() {
        for (Message message : messageHistory) {
            System.out.println("[" + message.getSender().getUsername() + "]: " + message.getContent());
        }
    }
}


public class TestChatApp {
    public static void main(String[] args) {

        User user1 = new User("1", "Alice");
        User user2 = new User("2", "Bob");

        ChatRoom chatRoom = new ChatRoom();

        chatRoom.addUser(user1);
        chatRoom.addUser(user2);

        chatRoom.sendMessage(user1, "Hello, Bob!");
        chatRoom.sendMessage(user2, "Hi, Alice!");

        chatRoom.viewMessageHistory();
    }
}

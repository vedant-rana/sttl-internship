package P64;

import java.util.ArrayList;
import java.util.List;

class User {
    private String username;
    private List<User> friends;
    private List<Post> posts;

    public User(String username) {
        this.username = username;
        this.friends = new ArrayList<>();
        this.posts = new ArrayList<>();
    }

    public String getUsername() {
        return username;
    }

    public List<User> getFriends() {
        return friends;
    }

    public List<Post> getPosts() {
        return posts;
    }

    public void addFriend(User friend) {
        friends.add(friend);
    }

    public void postMessage(String message) {
        Post post = new Post(this, message);
        posts.add(post);
    }

    public List<Post> getTimeline() {
        List<Post> timeline = new ArrayList<>();
        for (User friend : friends) {
            timeline.addAll(friend.getPosts());
        }
        timeline.addAll(posts);
        return timeline;
    }
}

class Post {
    private User author;
    private String message;

    public Post(User author, String message) {
        this.author = author;
        this.message = message;
    }

    public User getAuthor() {
        return author;
    }

    public String getMessage() {
        return message;
    }
}

public class TestSocialMedia {
    public static void main(String[] args) {
        User user1 = new User("User1");
        User user2 = new User("User2");
        User user3 = new User("User3");

        user1.addFriend(user2);
        user2.addFriend(user1);

        user2.addFriend(user3);
        user3.addFriend(user2);

        user1.postMessage("Hello, everyone!");
        user2.postMessage("Having a great day!");
        user3.postMessage("Enjoying the weekend!");

        // Display user timelines
        displayTimeline(user1);
        displayTimeline(user2);
        displayTimeline(user3);
    }

    private static void displayTimeline(User user) {
        System.out.println("Timeline for " + user.getUsername() + ":");
        List<Post> timeline = user.getTimeline();
        for (Post post : timeline) {
            System.out.println(post.getAuthor().getUsername() + ": " + post.getMessage());
        }
        System.out.println();
    }
}

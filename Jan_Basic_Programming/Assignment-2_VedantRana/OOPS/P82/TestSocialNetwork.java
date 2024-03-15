package P82;

import java.util.ArrayList;
import java.util.List;

class Post {
    private String content;
    private int likes;
    private int comments;

    public Post(String content) {
        this.content = content;
        this.likes = 0;
        this.comments = 0;
    }

    public String getContent() {
        return content;
    }

    public int getLikes() {
        return likes;
    }

    public int getComments() {
        return comments;
    }

    public void like() {
        likes++;
    }

    public void comment() {
        comments++;
    }
}

class User {
    private String username;
    private List<Post> posts;
    private List<User> friends;

    public User(String username) {
        this.username = username;
        this.posts = new ArrayList<>();
        this.friends = new ArrayList<>();
    }

    public String getUsername() {
        return username;
    }

    public void addPost(Post post) {
        posts.add(post);
    }

    public List<Post> getPosts() {
        return posts;
    }

    public void addFriend(User friend) {
        friends.add(friend);
    }

    public List<User> getFriends() {
        return friends;
    }
}

class Network {
    private List<User> users;

    public Network() {
        this.users = new ArrayList<>();
    }

    public void addUser(User user) {
        users.add(user);
    }

    public List<User> getUsers() {
        return users;
    }

    public List<User> findInfluentialUsers() {
        List<User> influentialUsers = new ArrayList<>();

        for (User user : users) {
            int totalLikes = user.getPosts().stream().mapToInt(Post::getLikes).sum();
            int totalFriendsLikes = user.getFriends().stream()
                    .mapToInt(friend -> friend.getPosts().stream().mapToInt(Post::getLikes).sum())
                    .sum();

            if (totalLikes + totalFriendsLikes > 100) {
                influentialUsers.add(user);
            }
        }

        return influentialUsers;
    }

    public List<Post> findPopularPosts() {
        List<Post> popularPosts = new ArrayList<>();

        for (User user : users) {
            popularPosts.addAll(user.getPosts());
        }

        popularPosts.sort((p1, p2) -> Integer.compare(p2.getLikes(), p1.getLikes()));

        return popularPosts.subList(0, Math.min(popularPosts.size(), 5));
    }
}



public class TestSocialNetwork {
    public static void main(String[] args) {
        Network socialNetwork = new Network();

        User user1 = new User("Alice");
        User user2 = new User("Bob");
        User user3 = new User("Charlie");

        Post post1 = new Post("Enjoying a sunny day!");
        Post post2 = new Post("New recipe experiment: delicious!");
        Post post3 = new Post("Exciting weekend adventures!");

        user1.addPost(post1);
        user2.addPost(post2);
        user3.addPost(post3);

        user1.addFriend(user2);
        user1.addFriend(user3);

        socialNetwork.addUser(user1);
        socialNetwork.addUser(user2);
        socialNetwork.addUser(user3);

        post1.like();
        post1.like();
        post1.comment();

        post2.like();
        post2.like();

        post3.like();
        post3.like();
        post3.like();
        post3.comment();

        List<User> influentialUsers = socialNetwork.findInfluentialUsers();
        System.out.println("Influential Users:");
        for (User influentialUser : influentialUsers) {
            System.out.println("- " + influentialUser.getUsername());
        }

        List<Post> popularPosts = socialNetwork.findPopularPosts();
        System.out.println("Popular Posts:");
        for (Post popularPost : popularPosts) {
            System.out.println("- " + popularPost.getContent() +
                    " (Likes: " + popularPost.getLikes() + ", Comments: " + popularPost.getComments() + ")");
        }
    }
}

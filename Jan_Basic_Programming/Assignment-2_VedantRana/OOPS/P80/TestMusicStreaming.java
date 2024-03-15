package P80;

import java.util.ArrayList;
import java.util.List;

class Song {
    private String title;
    private String artist;
    private int duration; // in seconds

    public Song(String title, String artist, int duration) {
        this.title = title;
        this.artist = artist;
        this.duration = duration;
    }

    public String getTitle() {
        return title;
    }

    public String getArtist() {
        return artist;
    }

    public int getDuration() {
        return duration;
    }
}

class Playlist {
    private String name;
    private List<Song> songs;

    public Playlist(String name) {
        this.name = name;
        this.songs = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void addSong(Song song) {
        songs.add(song);
    }

    public List<Song> getSongs() {
        return songs;
    }
}

class User {
    private String username;
    private List<Playlist> playlists;
    private List<Song> likedSongs;

    public User(String username) {
        this.username = username;
        this.playlists = new ArrayList<>();
        this.likedSongs = new ArrayList<>();
    }

    public String getUsername() {
        return username;
    }

    public void createPlaylist(String playlistName) {
        playlists.add(new Playlist(playlistName));
    }

    public void addSongToPlaylist(Song song, Playlist playlist) {
        playlist.addSong(song);
    }

    public void likeSong(Song song) {
        likedSongs.add(song);
    }

    public List<Playlist> getPlaylists() {
        return playlists;
    }

    public List<Song> getLikedSongs() {
        return likedSongs;
    }
}

class MusicStreamingService {
    private List<User> users;
    private List<Song> allSongs;

    public MusicStreamingService() {
        this.users = new ArrayList<>();
        this.allSongs = new ArrayList<>();
    }

    public void addUser(User user) {
        users.add(user);
    }

    public List<User> getUsers() {
        return users;
    }

    public void addSong(Song song) {
        allSongs.add(song);
    }

    public List<Song> getAllSongs() {
        return allSongs;
    }

    public List<Song> recommendSongs(User user) {
        List<Song> recommendedSongs = new ArrayList<>();

        // Dummy recommendation logic - recommend songs not in the user's liked songs
        for (Song song : allSongs) {
            if (!user.getLikedSongs().contains(song)) {
                recommendedSongs.add(song);
            }
        }

        return recommendedSongs;
    }
}


public class TestMusicStreaming {
    public static void main(String[] args) {
        MusicStreamingService streamingService = new MusicStreamingService();

        Song song1 = new Song("Shape of You", "Ed Sheeran", 240);
        Song song2 = new Song("Blinding Lights", "The Weeknd", 210);
        Song song3 = new Song("Dance Monkey", "Tones and I", 180);

        streamingService.addSong(song1);
        streamingService.addSong(song2);
        streamingService.addSong(song3);

        User user1 = new User("Alice");
        User user2 = new User("Bob");

        streamingService.addUser(user1);
        streamingService.addUser(user2);

        user1.createPlaylist("Favorites");
        user1.addSongToPlaylist(song1, user1.getPlaylists().get(0));
        user1.likeSong(song2);

        List<Song> recommendedSongs = streamingService.recommendSongs(user1);

        System.out.println("Recommended songs for " + user1.getUsername() + ":");
        for (Song recommendedSong : recommendedSongs) {
            System.out.println("- " + recommendedSong.getTitle() + " by " + recommendedSong.getArtist());
        }
    }
}

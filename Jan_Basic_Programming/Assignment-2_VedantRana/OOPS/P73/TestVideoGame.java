package P73;

import java.util.ArrayList;
import java.util.List;

class Game {
    private String title;
    private String genre;

    public Game(String title, String genre) {
        this.title = title;
        this.genre = genre;
    }
}

class Player {
    public String playerName;
    public int playerLevel;

    public Player(String playerName) {
        this.playerName = playerName;
        this.playerLevel = 1;
    }
}

class Inventory {
    private List<Game> games;
    private Player player;

    public Inventory(Player player) {
        this.player = player;
        this.games = new ArrayList<>();
    }

    public void addGame(Game game) {
        games.add(game);
    }

    public void removeGame(Game game) {
        games.remove(game);
    }

    public void trackPlayerProgress() {
        System.out.println(player.playerName + "'s current level: " + player.playerLevel);
    }
}


public class TestVideoGame {
    public static void main(String[] args) {
        Player player = new Player("Player1");
        Inventory inventory = new Inventory(player);

        Game game1 = new Game("Assassin's Creed Valhalla", "Action RPG");
        Game game2 = new Game("The Legend of Zelda: Breath of the Wild", "Adventure");

        inventory.addGame(game1);
        inventory.addGame(game2);

        inventory.trackPlayerProgress();

        inventory.removeGame(game1);

        inventory.trackPlayerProgress();
    }
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player
{
public:
    Player(const string &name) : name(name) {}

    string getName() const
    {
        return name;
    }

    int makeGuess() const
    {
        int guess;
        cout << name << ", enter your guess: ";
        cin >> guess;
        return guess;
    }

private:
    string name;
};

class NumberGame
{
public:
    NumberGame()
    {

        srand(static_cast<unsigned>(time(nullptr)));

        targetNumber = rand() % 100 + 1;
    }

    void play()
    {
        cout << "Welcome to the Number Guessing Game!" << endl;

        while (true)
        {
            for (const auto &player : players)
            {
                int guess = player.makeGuess();
                if (guess == targetNumber)
                {
                    cout << player.getName() << " guessed the correct number! Game over." << endl;
                    return;
                }
                else
                {
                    cout << player.getName() << "'s guess is incorrect." << endl;
                }
            }
        }
    }

    void addPlayer(const string &playerName)
    {
        players.emplace_back(playerName);
    }

private:
    int targetNumber;
    vector<Player> players;
};

int main()
{
    int numPlayers;
    cout << "Enter the number of players: ";
    cin >> numPlayers;

    NumberGame game;

    for (int i = 1; i <= numPlayers; ++i)
    {
        string playerName = "Player " + to_string(i);
        game.addPlayer(playerName);
    }

    game.play();

    return 0;
}

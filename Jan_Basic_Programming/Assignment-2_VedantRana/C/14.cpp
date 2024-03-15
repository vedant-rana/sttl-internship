#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
private:
    string username;
    vector<string> friendsList;

public:
    User(const string& username) : username(username) {}

    const string& getUsername() const {
        return username;
    }

    const vector<string>& getFriendsList() const {
        return friendsList;
    }

    void addFriend(const string& friendUsername) {
        friendsList.push_back(friendUsername);
    }
};

class SocialNetwork {
private:
    vector<User*> users;

public:
    void addUser(const string& username) {
        users.push_back(new User(username));
    }

    User* findUser(const string& username) const {
        for (const auto& user : users) {
            if (user->getUsername() == username) {
                return user;
            }
        }
        return nullptr;
    }

    void addFriendship(const string& username1, const string& username2) {
        User* user1 = findUser(username1);
        User* user2 = findUser(username2);

        if (user1 && user2) {
            user1->addFriend(username2);
            user2->addFriend(username1);
        }
    }

    void displayUsers() const {
        cout << "Users in the Social Network:\n";
        for (const auto& user : users) {
            cout << user->getUsername() << "\n";
        }
    }

    void displayFriends(const string& username) const {
        User* user = findUser(username);
        if (user) {
            cout << "Friends of " << username << ":\n";
            const vector<string>& friendsList = user->getFriendsList();
            for (const auto& friendUsername : friendsList) {
                cout << friendUsername << "\n";
            }
        } else {
            cout << "User not found.\n";
        }
    }

    ~SocialNetwork() {
        for (auto& user : users) {
            delete user;
        }
    }
};

int main() {
    SocialNetwork socialNetwork;

    socialNetwork.addUser("Alice");
    socialNetwork.addUser("Bob");
    socialNetwork.addUser("Charlie");

    socialNetwork.addFriendship("Alice", "Bob");
    socialNetwork.addFriendship("Alice", "Charlie");

    socialNetwork.displayUsers();

    cout << "\n";

    socialNetwork.displayFriends("Alice");
    socialNetwork.displayFriends("Bob");
    socialNetwork.displayFriends("Charlie");

    return 0;
}

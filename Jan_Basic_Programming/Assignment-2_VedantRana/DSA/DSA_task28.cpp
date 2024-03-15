#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class Node {
public:
    int key;
    Node** forward;

    Node(int k, int level) {
        key = k;
        forward = new Node*[level + 1];
        fill(forward, forward + level + 1, nullptr);
    }
};

class SkipList {
    int MAXLVL;
    float P;
    int level;
    Node* header;

public:
    SkipList(int max_level, float probability) {
        MAXLVL = max_level;
        P = probability;
        level = 0;
        header = new Node(INT_MIN, MAXLVL);
    }

    int randomLevel() {
        int lvl = 0;
        while (((float)rand() / RAND_MAX) < P && lvl < MAXLVL)
            lvl++;
        return lvl;
    }

    Node* createNode(int key, int level) {
        Node* n = new Node(key, level);
        return n;
    }

    void insert(int key) {
        Node* update[MAXLVL + 1];
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
                current = current->forward[i];
            update[i] = current;
        }

        int newLevel = randomLevel();

        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++)
                update[i] = header;
            level = newLevel;
        }

        Node* newNode = createNode(key, newLevel);

        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        cout << "Successfully Inserted key " << key << "\n";
    }

    void display() {
        cout << "Skip List:\n";
        for (int i = 0; i <= level; i++) {
            Node* node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << node->key << " ";
                node = node->forward[i];
            }
            cout << "\n";
        }
    }

    bool search(int key) {
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
                current = current->forward[i];
        }

        current = current->forward[0];

        return (current != nullptr && current->key == key);
    }

    void remove(int key) {
        Node* update[MAXLVL + 1];
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && current->key == key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current)
                    break;
                update[i]->forward[i] = current->forward[i];
            }

            while (level > 0 && header->forward[level] == nullptr)
                level--;

            delete current;

            cout << "Successfully Deleted key " << key << "\n";
        }
    }
};

int main() {
    srand((unsigned)time(0));

    SkipList skipList(3, 0.5);

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(7);
    skipList.insert(9);
    skipList.insert(12);
    skipList.insert(19);
    skipList.insert(17);
    skipList.insert(26);
    skipList.insert(21);
    skipList.insert(25);

    skipList.display();

    if (skipList.search(19))
        cout << "Key 19 found in Skip List\n";
    else
        cout << "Key 19 not found in Skip List\n";

    skipList.remove(19);

    skipList.display();

    return 0;
}

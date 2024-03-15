#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>
#include <map>

const int MAX_LEVEL = 16;  

class Node {
public:
    int value;
    std::vector<Node*> forward;  

    Node(int level, int value) : value(value), forward(level + 1, nullptr) {}
};

class SkipList {
private:
    Node* header;  
    int level;     

public:
    SkipList() : level(0) {
        header = new Node(MAX_LEVEL, INT_MAX);
    }

    
    int randomLevel() {
        int lvl = 0;
        while (rand() % 2 == 0 && lvl < MAX_LEVEL) {
            lvl++;
        }
        return lvl;
    }

    
    void insert(int value) {
        std::vector<Node*> update(MAX_LEVEL + 1, nullptr);
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();
        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++) {
                update[i] = header;
            }
            level = newLevel;
        }

        Node* newNode = new Node(newLevel, value);

        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    
    void display() {
        for (int i = 0; i <= level; i++) {
            Node* node = header->forward[i];
            std::cout << "Level " << i << ": ";
            while (node != nullptr) {
                std::cout << node->value << " ";
                node = node->forward[i];
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    SkipList skipList;
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

    std::cout << "Skip List after insertion:" << std::endl;
    skipList.display();

    return 0;
}

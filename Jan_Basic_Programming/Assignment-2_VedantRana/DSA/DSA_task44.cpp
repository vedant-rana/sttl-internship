#include <iostream>
#include <vector>
#include <limits>

class SkipGraphNode {
public:
    int key;
    std::vector<SkipGraphNode*> forward;

    SkipGraphNode(int k, int level) : key(k), forward(level + 1, nullptr) {}
};

class SkipList {
private:
    int maxLevel;
    int currentLevel;
    SkipGraphNode* header;

public:
    SkipList(int maxLvl) : maxLevel(maxLvl), currentLevel(0) {
        header = new SkipGraphNode(std::numeric_limits<int>::min(), maxLevel);
    }

    int randomLevel() const {
        int lvl = 0;
        while (lvl < maxLevel && rand() % 2 == 0) {
            lvl++;
        }
        return lvl;
    }

    SkipGraphNode* createNode(int key, int level) {
        return new SkipGraphNode(key, level);
    }

    void insert(int key) {
        std::vector<SkipGraphNode*> update(maxLevel + 1, nullptr);
        SkipGraphNode* current = header;

        for (int i = currentLevel; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();
        if (newLevel > currentLevel) {
            for (int i = currentLevel + 1; i <= newLevel; i++) {
                update[i] = header;
            }
            currentLevel = newLevel;
        }

        SkipGraphNode* newNode = createNode(key, newLevel);

        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    void print() const {
        for (int i = currentLevel; i >= 0; i--) {
            SkipGraphNode* node = header->forward[i];
            std::cout << "Level " << i << ": ";
            while (node != nullptr) {
                std::cout << node->key << " ";
                node = node->forward[i];
            }
            std::cout << "\n";
        }
        std::cout << "--------------------------\n";
    }
};

int main() {
    SkipList skipList(4);

    
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

    
    skipList.print();

    return 0;
}

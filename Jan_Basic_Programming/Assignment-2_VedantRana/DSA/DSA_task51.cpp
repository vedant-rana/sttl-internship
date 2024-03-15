#include<bits/stdc++.h>

using namespace std;
class SkipNode {
public:
    int data;
   vector<SkipNode*> forward;

    SkipNode(int value, int level) : data(value), forward(level, nullptr) {}
};

class SkipList {
private:
    int maxLevels;
    SkipNode* header;

public:
    SkipList(int maxLevels) : maxLevels(maxLevels) {
        header = new SkipNode(0, maxLevels);
    }

    int randomLevel() {
        int level = 1;
        while ((rand() % 2 == 0) && (level < maxLevels)) {
            level++;
        }
        return level;
    }

    void insert(int value) {
        int updateLevel = randomLevel();
        SkipNode* update[maxLevels];
        SkipNode* current = header;

        for (int i = maxLevels - 1; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->data < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();

        if (newLevel > updateLevel) {
            for (int i = updateLevel; i < newLevel; i++) {
                update[i] = header;
            }
            updateLevel = newLevel;
        }

        SkipNode* newNode = new SkipNode(value, newLevel);

        for (int i = 0; i < updateLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    SkipNode* search(int value) {
        SkipNode* current = header;

        for (int i = maxLevels - 1; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->data < value) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        if (current != nullptr && current->data == value) {
            return current;
        }

        return nullptr;
    }

    void display() {
        for (int i = maxLevels - 1; i >= 0; i--) {
            SkipNode* current = header->forward[i];
           cout << "Level " << i << ": ";
            while (current != nullptr) {
               cout << current->data << " ";
                current = current->forward[i];
            }
           cout <<endl;
        }
    }
};

int main() {
    srand(time(nullptr));

    int maxLevels;
   cout << "Enter the maximum number of levels in the Skip List: ";
   cin >> maxLevels;

    SkipList skipList(maxLevels);

    int choice, value;
    while (true) {
       cout << "\n1. Insert Element\n2. Search Element\n3. Display Skip List\n4. Exit\n";
       cout << "Enter your choice: ";
       cin >> choice;

        switch (choice) {
            case 1:
               cout << "Enter the element to insert: ";
               cin >> value;
                skipList.insert(value);
                break;
            case 2:
               cout << "Enter the element to search: ";
               cin >> value;
                if (skipList.search(value) != nullptr) {
                   cout << "Element found in Skip List.\n";
                } else {
                   cout << "Element not found in Skip List.\n";
                }
                break;
            case 3:
                skipList.display();
                break;
            case 4:
                return 0;
            default:
               cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

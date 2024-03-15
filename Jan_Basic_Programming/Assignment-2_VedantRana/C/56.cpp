#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class SkipNode
{
public:
    int key;
    vector<SkipNode *> forward;

    SkipNode(int k, int level) : key(k), forward(level + 1, nullptr) {}
};

class SkipList
{
public:
    SkipList(int maxLevel) : maxLevel(maxLevel), currentLevel(0)
    {

        head = new SkipNode(-2147483648, maxLevel);
    }

    int randomLevel()
    {
        int level = 0;
        while (rand() % 2 == 0 && level < maxLevel)
        {
            level++;
        }
        return level;
    }

    void insert(int key)
    {
        vector<SkipNode *> update(maxLevel + 1, nullptr);
        SkipNode *current = head;

        for (int i = currentLevel; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();

        if (newLevel > currentLevel)
        {
            for (int i = currentLevel + 1; i <= newLevel; i++)
            {
                update[i] = head;
            }
            currentLevel = newLevel;
        }

        SkipNode *newNode = new SkipNode(key, newLevel);

        for (int i = 0; i <= newLevel; i++)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        cout << "Inserted key " << key << " at level " << newLevel << endl;
    }

    bool search(int key)
    {
        SkipNode *current = head;

        for (int i = currentLevel; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        return (current != nullptr && current->key == key);
    }

    void print()
    {
        for (int i = 0; i <= currentLevel; i++)
        {
            SkipNode *current = head->forward[i];
            cout << "Level " << i << ": ";
            while (current != nullptr)
            {
                cout << current->key << " ";
                current = current->forward[i];
            }
            cout << endl;
        }
    }

private:
    SkipNode *head;
    int maxLevel;
    int currentLevel;
};

int main()
{

    srand(time(0));

    SkipList skipList(4);

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(7);
    skipList.insert(9);
    skipList.insert(12);

    skipList.print();

    cout << "Search result for key 7: " << (skipList.search(7) ? "Found" : "Not found") << endl;
    cout << "Search result for key 8: " << (skipList.search(8) ? "Found" : "Not found") << endl;

    return 0;
}

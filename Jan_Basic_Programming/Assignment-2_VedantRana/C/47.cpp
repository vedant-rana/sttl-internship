

#include <bits/stdc++.h>

using namespace std;

struct SkipNode
{
    int key;
    int value;
    SkipNode **forward;

    SkipNode(int k, int v, int level) : key(k), value(v)
    {
        forward = new SkipNode *[level + 1];
        fill(forward, forward + level + 1, nullptr);
    }

    ~SkipNode()
    {
        delete[] forward;
    }
};

class SkipList
{
private:
    int maxLevel;
    float p;
    int level;
    SkipNode *header;

public:
    SkipList(int maxLvl, float prob) : maxLevel(maxLvl), p(prob), level(0)
    {
        header = new SkipNode(INT_MIN, 0, maxLevel);
    }

    ~SkipList()
    {
        delete header;
    }

    int randomLevel()
    {
        int lvl = 0;
        float r = static_cast<float>(rand()) / RAND_MAX;
        while (r < p && lvl < maxLevel)
        {
            lvl++;
            r = static_cast<float>(rand()) / RAND_MAX;
        }
        return lvl;
    }

    void insert(int key, int value)
    {
        SkipNode *update[maxLevel + 1];
        SkipNode *current = header;

        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }

        int newLevel = randomLevel();

        if (newLevel > level)
        {
            for (int i = level + 1; i <= newLevel; i++)
            {
                update[i] = header;
            }
            level = newLevel;
        }

        SkipNode *newNode = new SkipNode(key, value, newLevel);

        for (int i = 0; i <= newLevel; i++)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        cout << "Inserted key: " << key << ", value: " << value << " at level: " << newLevel << endl;
    }

    int search(int key)
    {
        SkipNode *current = header;
        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->key < key)
            {
                current = current->forward[i];
            }
        }

        current = current->forward[0];
        if (current != nullptr && current->key == key)
        {
            return current->value;
        }
        else
        {
            return INT_MIN;
        }
    }

    void display()
    {
        cout << "Skip List:" << endl;
        for (int i = 0; i <= level; i++)
        {
            SkipNode *node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr)
            {
                cout << "(" << node->key << "," << node->value << ") ";
                node = node->forward[i];
            }
            cout << endl;
        }
    }
};

int main()
{

    srand(static_cast<unsigned>(time(0)));

    SkipList skipList(4, 0.5);

    skipList.insert(3, 10);
    skipList.insert(6, 20);
    skipList.insert(7, 30);
    skipList.insert(9, 40);
    skipList.insert(12, 50);

    skipList.display();

    int keyToSearch = 7;
    int result = skipList.search(keyToSearch);
    if (result != INT_MIN)
    {
        cout << "Found key: " << keyToSearch << ", value: " << result << endl;
    }
    else
    {
        cout << "Key " << keyToSearch << " not found." << endl;
    }

    return 0;
}

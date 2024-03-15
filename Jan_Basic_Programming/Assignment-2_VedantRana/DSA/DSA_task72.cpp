#include <iostream>
#include <atomic>
#include <cstdlib>
#include <ctime>
#include <climits>

class Node {
public:
    int key;
    std::atomic<Node*> next[1];

    Node(int k, int level) : key(k) {
        for (int i = 0; i <= level; ++i) {
            next[i].store(nullptr, std::memory_order_relaxed);
        }
    }
};

class SkipList {
private:
    static const int MAX_LEVEL = 16; 

    std::atomic<Node*> head;
    std::atomic<int> maxLevel;

public:
    SkipList() {
        head.store(new Node(INT_MIN, MAX_LEVEL), std::memory_order_relaxed);
        maxLevel.store(1, std::memory_order_relaxed);
    }

    int randomLevel() {
        int level = 1;
        while ((rand() & 1) && (level < MAX_LEVEL)) {
            level++;
        }
        return level;
    }

    Node* createNode(int key, int level) {
        return new Node(key, level);
    }

    bool insert(int key) {
        int topLevel = randomLevel();
        Node* newNode = createNode(key, topLevel);

        Node* preds[MAX_LEVEL + 1];
        Node* succs[MAX_LEVEL + 1];

        for (int i = 0; i <= MAX_LEVEL; ++i) {
            preds[i] = nullptr;
            succs[i] = nullptr;
        }

        while (true) {
            int foundLevel = find(key, preds, succs);

            if (foundLevel != -1) {
                
                delete newNode;
                return false;
            }

            if (topLevel > maxLevel.load(std::memory_order_relaxed)) {
                maxLevel.store(topLevel, std::memory_order_relaxed);
            }

            
            for (int i = 0; i <= topLevel; ++i) {
                newNode->next[i].store(succs[i], std::memory_order_relaxed);
            }

            Node* pred = preds[0];
            Node* succ = succs[0];

            if (!pred->next[0].compare_exchange_strong(succ, newNode, std::memory_order_release, std::memory_order_relaxed)) {
                
                continue;
            }

            for (int i = 1; i <= topLevel; ++i) {
                while (true) {
                    pred = preds[i];
                    succ = succs[i];

                    if (pred->next[i].compare_exchange_strong(succ, newNode, std::memory_order_release, std::memory_order_relaxed)) {
                        
                        break;
                    }

                    
                    find(key, preds, succs);
                }
            }

            
            return true;
        }
    }

    bool remove(int key) {
        Node* preds[MAX_LEVEL + 1];
        Node* succs[MAX_LEVEL + 1];

        while (true) {
            int foundLevel = find(key, preds, succs);

            if (foundLevel == -1) {
                
                return false;
            }

            Node* pred = preds[0];
            Node* succ = succs[0];

            for (int i = foundLevel; i >= 0; --i) {
                if (!preds[i]->next[i].compare_exchange_strong(succ, succ->next[i], std::memory_order_release, std::memory_order_relaxed)) {
                    
                    find(key, preds, succs);
                    continue;
                }
            }

            
            delete succ;
            return true;
        }
    }

    bool search(int key) {
        Node* preds[MAX_LEVEL + 1];
        Node* succs[MAX_LEVEL + 1];
        int foundLevel = find(key, preds, succs);
        return (foundLevel != -1);
    }

    void printList() {
        Node* current = head.load(std::memory_order_relaxed)->next[0].load(std::memory_order_relaxed);

        while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->next[0].load(std::memory_order_relaxed);
        }

        std::cout << std::endl;
    }

private:
    int find(int key, Node* preds[], Node* succs[]) {
        int foundLevel = -1;
        Node* pred = head.load(std::memory_order_relaxed);
        
        for (int i = MAX_LEVEL; i >= 0; --i) {
            Node* curr = pred->next[i].load(std::memory_order_relaxed);

            while (curr != nullptr && curr->key < key) {
                pred = curr;
                curr = pred->next[i].load(std::memory_order_relaxed);
            }

            if (foundLevel == -1 && curr != nullptr && curr->key == key) {
                foundLevel = i;
            }

            preds[i] = pred;
            succs[i] = curr;
        }

        return foundLevel;
    }
};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    SkipList skipList;

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(1);
    skipList.insert(9);
    skipList.insert(2);
    skipList.insert(7);

    std::cout << "Skip List after insertions: ";
    skipList.printList();

    skipList.remove(1);
    skipList.remove(6);

    std::cout << "Skip List after removals: ";
    skipList.printList();

    std::cout << "Search for key 2: " << (skipList.search(2) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for key 6: " << (skipList.search(6) ? "Found" : "Not Found") << std::endl;

    return 0;
}

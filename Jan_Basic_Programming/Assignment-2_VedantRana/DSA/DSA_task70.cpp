#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

class YFastTrie {
public:
    YFastTrie(int universeSize) : u(universeSize), logU(ceil(log2(u))) {
        maxLevel = logU;
        for (int i = 0; i <= maxLevel; ++i) {
            level[i].clear();
        }
        root = nullptr;
    }

    void insert(int key) {
        Node* node = new Node(key);
        level[0].insert(node);

        for (int i = 1; i <= maxLevel; ++i) {
            if (key & (1 << (maxLevel - i))) {
                if (level[i].empty()) {
                    level[i].insert(node);
                } else {
                    auto successor = level[i].lower_bound(node);
                    if (successor != level[i].end()) {
                        node->next[i] = *successor;
                        level[i].erase(successor);
                    }
                }
            }
        }

        if (!root || node->key < root->key) {
            root = node;
        }
    }

    void erase(int key) {
        auto it = level[0].lower_bound(new Node(key));
        if (it == level[0].end() || (*it)->key != key) {
            return; 
        }

        Node* node = *it;
        level[0].erase(it);

        for (int i = 1; i <= maxLevel; ++i) {
            if (key & (1 << (maxLevel - i))) {
                if (node->next[i]) {
                    level[i].insert(node->next[i]);
                }
            }
        }

        if (node == root) {
            if (!level[0].empty()) {
                root = *level[0].begin();
            } else {
                root = nullptr;
            }
        }

        delete node;
    }

    int successor(int key) {
        Node* current = root;
        for (int i = maxLevel; i >= 0; --i) {
            if (!current) break;
            if (key < current->key && current->next[i]) {
                current = current->next[i];
            }
        }
        return current ? current->key : -1;
    }

private:
    struct Node {
        int key;
        vector<Node*> next;

        Node(int k) : key(k) {
            next.resize(logU + 1, nullptr);
        }

        bool operator<(const Node* other) const {
            return key < other->key;
        }
    };

    int u; 
    int logU; 
    int maxLevel; 
    set<Node*> level[32]; 
    Node* root;
};

int main() {
    YFastTrie yFastTrie(32); 

    
    yFastTrie.insert(5);
    yFastTrie.insert(3);
    yFastTrie.insert(8);
    yFastTrie.insert(7);
    yFastTrie.insert(12);

    
    cout << "Successor of 6: " << yFastTrie.successor(6) << endl; 
    cout << "Successor of 10: " << yFastTrie.successor(10) << endl; 

    
    yFastTrie.erase(7);

    
    cout << "Successor of 6 after erasing 7: " << yFastTrie.successor(6) << endl; 

    return 0;
}

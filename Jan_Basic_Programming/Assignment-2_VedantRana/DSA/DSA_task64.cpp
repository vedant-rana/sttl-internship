#include <iostream>
#include <string>

using namespace std;

struct TSTNode {
    char data;
    bool isEnd;
    TSTNode* left;
    TSTNode* middle;
    TSTNode* right;

    TSTNode(char ch) : data(ch), isEnd(false), left(nullptr), middle(nullptr), right(nullptr) {}
};

class TernarySearchTree {
public:
    TernarySearchTree() : root(nullptr) {}

    void insert(const string& key) {
        root = insertHelper(root, key, 0);
    }

    bool search(const string& key) {
        return searchHelper(root, key, 0);
    }

    void traverse() {
        traverseHelper(root, "");
    }

private:
    TSTNode* root;

    TSTNode* insertHelper(TSTNode* node, const string& key, int index) {
        char ch = key[index];

        if (!node) {
            node = new TSTNode(ch);
        }

        if (ch < node->data) {
            node->left = insertHelper(node->left, key, index);
        } else if (ch == node->data) {
            if (index < key.length() - 1) {
                node->middle = insertHelper(node->middle, key, index + 1);
            } else {
                node->isEnd = true;
            }
        } else {
            node->right = insertHelper(node->right, key, index);
        }

        return node;
    }

    bool searchHelper(TSTNode* node, const string& key, int index) {
        if (!node) {
            return false;
        }

        char ch = key[index];

        if (ch < node->data) {
            return searchHelper(node->left, key, index);
        } else if (ch == node->data) {
            if (index == key.length() - 1) {
                return node->isEnd;
            } else {
                return searchHelper(node->middle, key, index + 1);
            }
        } else {
            return searchHelper(node->right, key, index);
        }
    }

    void traverseHelper(TSTNode* node, string currentKey) {
        if (!node) {
            return;
        }

        traverseHelper(node->left, currentKey);

        currentKey += node->data;
        if (node->isEnd) {
            cout << currentKey << endl;
        }

        traverseHelper(node->middle, currentKey.erase(currentKey.length() - 1));

        traverseHelper(node->right, currentKey.erase(currentKey.length() - 1));
    }
};

int main() {
    TernarySearchTree tst;

    
    tst.insert("cat");
    tst.insert("dog");
    tst.insert("cot");
    tst.insert("cater");
    tst.insert("bat");

    
    cout << "Search 'cat': " << (tst.search("cat") ? "Found" : "Not Found") << endl;
    cout << "Search 'dog': " << (tst.search("dog") ? "Found" : "Not Found") << endl;
    cout << "Search 'cater': " << (tst.search("cater") ? "Found" : "Not Found") << endl;
    cout << "Search 'cot': " << (tst.search("cot") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (tst.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'bats': " << (tst.search("bats") ? "Found" : "Not Found") << endl;

    
    cout << "All keys in the Ternary Search Tree:" << endl;
    tst.traverse();

    return 0;
}

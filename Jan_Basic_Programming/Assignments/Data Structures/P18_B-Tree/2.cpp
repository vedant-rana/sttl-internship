#include <iostream>
#include <vector>
using namespace std;
const int ORDER = 3;

class BPlusTreeNode {
public:
    bool isLeaf;
    int keys[ORDER - 1];
    BPlusTreeNode* children[ORDER];
    BPlusTreeNode* next;

    BPlusTreeNode(bool leafNode) : isLeaf(leafNode), next(nullptr) {
        for (int i = 0; i < ORDER - 1; ++i) {
            keys[i] = 0;
            children[i] = nullptr;
        }
        children[ORDER - 1] = nullptr;
    }
};

class BPlusTree {
private:
    BPlusTreeNode* root;

public:
    BPlusTree() : root(nullptr) {}

    void insert(int key) {
        if (root == nullptr) {
            root = new BPlusTreeNode(true);
            root->keys[0] = key;
            root->children[ORDER - 1] = nullptr;
            return;
        }

        if (root->isLeaf) {
            insertIntoLeaf(root, key);
        } else {
            if (root->children[0]->isLeaf && root->children[0]->keys[0] > key) {
                insertIntoNonLeaf(root, key);
            } else {
                insertInternal(root, key);
            }
        }
    }

    bool search(int key) {
        return searchKey(root, key);
    }

    void printTree() {
        printTree(root, 0);
    }

private:
    void insertIntoLeaf(BPlusTreeNode* node, int key) {
        int i = 0;
        while (i < ORDER - 1 && node->keys[i] < key)
            ++i;

        for (int j = ORDER - 2; j > i; --j) {
            node->keys[j] = node->keys[j - 1];
        }

        node->keys[i] = key;
    }

    void insertIntoNonLeaf(BPlusTreeNode* node, int key) {
        int i = 0;
        while (i < ORDER - 1 && node->keys[i] < key)
            ++i;

        if (node->children[i]->isLeaf) {
            insertIntoLeaf(node->children[i], key);
        } else {
            insertInternal(node->children[i], key);
        }
    }

    void insertInternal(BPlusTreeNode* node, int key) {
        int i = 0;
        while (i < ORDER - 1 && node->keys[i] < key)
            ++i;

        if (node->children[i]->isLeaf) {
            insertIntoLeaf(node->children[i], key);
        } else {
            insertInternal(node->children[i], key);
        }
    }

    bool searchKey(BPlusTreeNode* node, int key) {
        int i = 0;
        while (i < ORDER - 1 && key > node->keys[i])
            ++i;

        if (i < ORDER - 1 && key == node->keys[i])
            return true;

        if (node->isLeaf)
            return false;

        return searchKey(node->children[i], key);
    }

    void printTree(BPlusTreeNode* node, int level) {
        if (node != nullptr) {
            cout << "Level " << level << ": ";
            for (int i = 0; i < ORDER - 1; ++i) {
                if (node->keys[i] != 0)
                    cout << node->keys[i] << " ";
            }
            cout << endl;

            if (!node->isLeaf) {
                for (int i = 0; i < ORDER; ++i) {
                    if (node->children[i] != nullptr)
                        printTree(node->children[i], level + 1);
                }
            }
        }
    }
};

int main() {
    BPlusTree bPlusTree;

    bPlusTree.insert(3);
    bPlusTree.insert(7);
    bPlusTree.insert(1);
    bPlusTree.insert(5);
    bPlusTree.insert(10);
    bPlusTree.insert(2);
    bPlusTree.insert(6);
    bPlusTree.insert(9);
    bPlusTree.insert(11);
    bPlusTree.insert(4);
    bPlusTree.insert(8);

    cout << "B+ Tree:\n";
    bPlusTree.printTree();

    cout << "\nSearch for key 6: " << (bPlusTree.search(6) ? "Found" : "Not Found") << endl;
    cout << "Search for key 12: " << (bPlusTree.search(12) ? "Found" : "Not Found") << endl;

    return 0;
}

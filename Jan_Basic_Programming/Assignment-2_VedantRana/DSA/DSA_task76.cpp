#include <iostream>
#include <vector>
#include <algorithm>

const int BLOCK_SIZE = 4; 

class BTreeNode {
public:
    std::vector<int> keys;
    std::vector<BTreeNode*> children;

    bool isLeaf;

    BTreeNode(bool leaf = true) : isLeaf(leaf) {}

    ~BTreeNode() {
        for (BTreeNode* child : children) {
            delete child;
        }
    }
};

class BTree {
private:
    BTreeNode* root;

public:
    BTree() : root(nullptr) {}

    ~BTree() {
        if (root != nullptr) {
            delete root;
        }
    }

    void insert(int key) {
        if (root == nullptr) {
            root = new BTreeNode();
            root->keys.push_back(key);
        } else {
            insertRecursive(root, key);
        }
    }

    void print() const {
        if (root != nullptr) {
            printRecursive(root, 0);
        }
    }

private:
    void insertRecursive(BTreeNode* node, int key) {
        auto it = std::lower_bound(node->keys.begin(), node->keys.end(), key);

        if (node->isLeaf) {
            node->keys.insert(it, key);

            if (node->keys.size() > BLOCK_SIZE - 1) {
                splitNode(node);
            }
        } else {
            int index = std::distance(node->keys.begin(), it);

            if (index < node->children.size()) {
                insertRecursive(node->children[index], key);
            } else {
                insertRecursive(node->children.back(), key);
            }
        }
    }

    void splitNode(BTreeNode* node) {
        int middleIndex = node->keys.size() / 2;
        int middleKey = node->keys[middleIndex];

        BTreeNode* newNode = new BTreeNode(node->isLeaf);
        newNode->keys.assign(node->keys.begin() + middleIndex + 1, node->keys.end());
        node->keys.resize(middleIndex);

        if (!node->isLeaf) {
            newNode->children.assign(node->children.begin() + middleIndex + 1, node->children.end());
            node->children.resize(middleIndex + 1);
        }

        if (node == root) {
            BTreeNode* newRoot = new BTreeNode(false);
            newRoot->keys.push_back(middleKey);
            newRoot->children.push_back(node);
            newRoot->children.push_back(newNode);
            root = newRoot;
        } else {
            BTreeNode* parent = findParent(root, node);
            auto it = std::lower_bound(parent->keys.begin(), parent->keys.end(), middleKey);
            int index = std::distance(parent->keys.begin(), it);
            parent->keys.insert(it, middleKey);
            parent->children.insert(parent->children.begin() + index + 1, newNode);

            if (parent->keys.size() > BLOCK_SIZE - 1) {
                splitNode(parent);
            }
        }
    }

    BTreeNode* findParent(BTreeNode* current, BTreeNode* child) {
        for (BTreeNode* next : current->children) {
            if (next == child) {
                return current;
            }
            BTreeNode* result = findParent(next, child);
            if (result != nullptr) {
                return result;
            }
        }
        return nullptr;
    }

    void printRecursive(BTreeNode* node, int level) const {
        std::cout << "Level " << level << ": ";
        for (int key : node->keys) {
            std::cout << key << " ";
        }
        std::cout << "\n";

        for (BTreeNode* child : node->children) {
            printRecursive(child, level + 1);
        }
    }
};

int main() {
    BTree btree;
    for (int i = 1; i <= 10; ++i) {
        btree.insert(i);
    }

    btree.print();

    return 0;
}

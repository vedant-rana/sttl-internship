#include <iostream>

class CacheObliviousNode {
public:
    int key;
    CacheObliviousNode* left;
    CacheObliviousNode* right;

    CacheObliviousNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class CacheObliviousTree {
private:
    CacheObliviousNode* root;

public:
    CacheObliviousTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

private:
    CacheObliviousNode* insertRecursive(CacheObliviousNode* node, int key) {
        if (node == nullptr) {
            return new CacheObliviousNode(key);
        }

        if (key < node->key) {
            node->left = insertRecursive(node->left, key);
        } else if (key > node->key) {
            node->right = insertRecursive(node->right, key);
        }

        return node;
    }

    void inorderTraversalRecursive(CacheObliviousNode* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            std::cout << node->key << " ";
            inorderTraversalRecursive(node->right);
        }
    }
};

int main() {
    CacheObliviousTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    tree.inorderTraversal();

    return 0;
}

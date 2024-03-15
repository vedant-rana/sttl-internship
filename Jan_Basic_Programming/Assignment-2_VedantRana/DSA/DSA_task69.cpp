#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class ScapegoatTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;
    int rebuildThreshold;

public:
    ScapegoatTree(double alpha) : root(nullptr), size(0) {
        // alpha is the threshold for rebuilding the tree
        rebuildThreshold = static_cast<int>(alpha * pow(2.0, 64));
    }

    // Helper function to insert a key into the tree
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            size++;
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        // Check if the current subtree becomes unbalanced
        if (size > rebuildThreshold) {
            rebuild(node);
        }

        return node;
    }

    // Helper function to rebuild a subtree
    Node* rebuild(Node* node) {
        std::vector<int> values;
        collectValues(node, values);

        int n = values.size();
        Node* parent = findParent(root, node->key);
        Node* newSubtree = buildTreeFromSortedArray(values, 0, n - 1);

        if (parent == nullptr) {
            root = newSubtree;
        } else if (parent->left == node) {
            parent->left = newSubtree;
        } else {
            parent->right = newSubtree;
        }

        size = n;
        return newSubtree;
    }

    // Helper function to collect values of a subtree in sorted order
    void collectValues(Node* node, std::vector<int>& values) {
        if (node == nullptr) {
            return;
        }

        collectValues(node->left, values);
        values.push_back(node->key);
        collectValues(node->right, values);
    }

    // Helper function to build a balanced tree from a sorted array
    Node* buildTreeFromSortedArray(const std::vector<int>& values, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        Node* node = new Node(values[mid]);
        node->left = buildTreeFromSortedArray(values, start, mid - 1);
        node->right = buildTreeFromSortedArray(values, mid + 1, end);

        return node;
    }

    // Helper function to find the parent of a node in the tree
    Node* findParent(Node* current, int key) {
        if (current == nullptr || (current->left != nullptr && current->left->key == key) ||
            (current->right != nullptr && current->right->key == key)) {
            return current;
        }

        if (key < current->key) {
            return findParent(current->left, key);
        } else {
            return findParent(current->right, key);
        }
    }

    // Public function to insert a key into the tree
    void insert(int key) {
        root = insert(root, key);
    }

    // Public function to check if the tree contains a key
    bool contains(int key) const {
        return contains(root, key);
    }

    // Helper function to check if the tree contains a key
    bool contains(Node* node, int key) const {
        if (node == nullptr) {
            return false;
        }

        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            return contains(node->left, key);
        } else {
            return contains(node->right, key);
        }
    }
};

int main() {
    ScapegoatTree tree(0.7);

    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);

    std::cout << "Tree contains 6: " << (tree.contains(6) ? "true" : "false") << std::endl;
    std::cout << "Tree contains 4: " << (tree.contains(4) ? "true" : "false") << std::endl;

    return 0;
}

#include <iostream>
#include <climits>
#include <algorithm>

class OrderStatisticTree {
private:
    struct Node {
        int key;
        int size;
        Node* left;
        Node* right;

        Node(int k) : key(k), size(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    int getSize(Node* node) const {
        return (node != nullptr) ? node->size : 0;
    }

    void updateSize(Node* node) {
        if (node != nullptr) {
            node->size = getSize(node->left) + getSize(node->right) + 1;
        }
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }

        updateSize(node);

        return node;
    }

    int kthSmallest(Node* node, int k) const {
        if (node == nullptr || k <= 0 || k > node->size) {
            return INT_MIN; 
        }

        int leftSize = getSize(node->left);

        if (k == leftSize + 1) {
            return node->key;
        } else if (k <= leftSize) {
            return kthSmallest(node->left, k);
        } else {
            return kthSmallest(node->right, k - leftSize - 1);
        }
    }

public:
    OrderStatisticTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    int kthSmallest(int k) const {
        return kthSmallest(root, k);
    }
};

int main() {
    OrderStatisticTree ost;

    ost.insert(3);
    ost.insert(1);
    ost.insert(4);
    ost.insert(2);

    std::cout << "1st smallest element: " << ost.kthSmallest(1) << std::endl;
    std::cout << "3rd smallest element: " << ost.kthSmallest(3) << std::endl;

    return 0;
}

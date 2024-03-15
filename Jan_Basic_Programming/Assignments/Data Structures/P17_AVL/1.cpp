#include <iostream>
#include <algorithm>

using namespace std;

struct AVLNode {
    int key;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int val) : key(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    void updateHeight(AVLNode* node) {
        if (node != nullptr)
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    int getBalanceFactor(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* balanceNode(AVLNode* node) {
        updateHeight(node);

        int balance = getBalanceFactor(node);

        if (balance > 1) {
            if (getBalanceFactor(node->left) < 0)
                node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1) {
            if (getBalanceFactor(node->right) > 0)
                node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* insertKey(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->key)
            node->left = insertKey(node->left, key);
        else if (key > node->key)
            node->right = insertKey(node->right, key);
        else
            return node;

        return balanceNode(node);
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteKey(AVLNode* node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = deleteKey(node->left, key);
        else if (key > node->key)
            node->right = deleteKey(node->right, key);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = (node->left != nullptr) ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                delete temp;
            } else {
                AVLNode* temp = minValueNode(node->right);
                node->key = temp->key;
                node->right = deleteKey(node->right, temp->key);
            }
        }

        if (node == nullptr)
            return node;

        return balanceNode(node);
    }

    bool searchKey(AVLNode* node, int key) {
        if (node == nullptr)
            return false;

        if (key < node->key)
            return searchKey(node->left, key);
        else if (key > node->key)
            return searchKey(node->right, key);
        else
            return true;
    }

    void inOrderTraversal(AVLNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->key << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertKey(root, key);
    }

    void remove(int key) {
        root = deleteKey(root, key);
    }

    bool search(int key) {
        return searchKey(root, key);
    }

    void printInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(15);
    avl.insert(5);

    avl.printInOrder();

    avl.remove(20);

    avl.printInOrder();

    int searchKey = 30;
    if (avl.search(searchKey))
        cout << searchKey << " is present in the AVL tree.\n";
    else
        cout << searchKey << " is not present in the AVL tree.\n";

    return 0;
}

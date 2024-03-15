#include <iostream>
#include <algorithm>

using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        
        x->right = y;
        y->left = T2;

        
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        
        y->left = x;
        x->right = T2;

        
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, int data) {
        if (node == nullptr) {
            return new AVLNode(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            
            return node;
        }

        
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        
        int balance = getBalanceFactor(node);

        
        if (balance > 1 && data < node->left->data) {
            return rotateRight(node);
        }

        
        if (balance < -1 && data > node->right->data) {
            return rotateLeft(node);
        }

        
        if (balance > 1 && data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        
        if (balance < -1 && data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* findMinValueNode(AVLNode* node) {
        AVLNode* current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    AVLNode* deleteNode(AVLNode* root, int data) {
        if (root == nullptr) {
            return root;
        }

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                AVLNode* temp = (root->left != nullptr) ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                AVLNode* temp = findMinValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr) {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);

        
        if (balance > 1 && getBalanceFactor(root->left) >= 0) {
            return rotateRight(root);
        }

        
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        
        if (balance < -1 && getBalanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        }

        
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void remove(int data) {
        root = deleteNode(root, data);
    }

    void inOrderTraversal(AVLNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void printTree() {
        cout << "Inorder Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    
    AVLTree avlTree;

    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);

    cout << "Initial AVL Tree:" << endl;
    avlTree.printTree();

    avlTree.remove(30);

    cout << "AVL Tree after deleting 30:" << endl;
    avlTree.printTree();

    return 0;
}

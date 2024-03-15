#include <iostream>
#include <vector>

using namespace std;

enum Color { RED, BLACK };


struct PersistentRBNode {
    int data;
    Color color;
    PersistentRBNode* left, *right;

    PersistentRBNode(int data, Color color) : data(data), color(color), left(nullptr), right(nullptr) {}
};

class PersistentRBTree {
private:
    vector<PersistentRBNode*> versions;

    PersistentRBNode* rotateLeft(PersistentRBNode* root) {
        PersistentRBNode* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }

    PersistentRBNode* rotateRight(PersistentRBNode* root) {
        PersistentRBNode* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }

    PersistentRBNode* insert(PersistentRBNode* root, int data) {
        if (root == nullptr) {
            return new PersistentRBNode(data, RED);
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        } else {
            
            return root;
        }

        
        if (root->right != nullptr && root->left != nullptr &&
            root->left->color == RED && root->right->color == RED) {
            root->color = RED;
            root->left->color = BLACK;
            root->right->color = BLACK;
        }

        
        if (root->right != nullptr && root->right->color == RED) {
            root = rotateLeft(root);
        }

        
        if (root->left != nullptr && root->left->left != nullptr && root->left->color == RED &&
            root->left->left->color == RED) {
            root = rotateRight(root);
        }

        return root;
    }

public:
    PersistentRBTree() {
        versions.push_back(nullptr);
    }

    void insert(int data, int version) {
        versions.push_back(insert(versions[version], data));
    }

    void printTree(int version) {
        cout << "Version " << version << " - Inorder Traversal: ";
        printInOrder(versions[version]);
        cout << endl;
    }

    void printInOrder(PersistentRBNode* root) {
        if (root != nullptr) {
            printInOrder(root->left);
            cout << root->data << " ";
            printInOrder(root->right);
        }
    }
};

int main() {
    PersistentRBTree persistentRBTree;

    
    persistentRBTree.insert(10, 0);
    persistentRBTree.printTree(0);

    
    persistentRBTree.insert(20, 1);
    persistentRBTree.printTree(1);

    
    persistentRBTree.insert(5, 2);
    persistentRBTree.printTree(2);

    return 0;
}

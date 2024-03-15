#include <iostream>
#include <algorithm>

using namespace std;


struct WAVLNode {
    int key, value;
    int rank;  
    WAVLNode* left, *right;

    WAVLNode(int key, int value) : key(key), value(value), rank(0), left(nullptr), right(nullptr) {}
};

class WAVLTree {
private:
    WAVLNode* root;

    
    WAVLNode* rotateRight(WAVLNode* node) {
        WAVLNode* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateRank(node);
        updateRank(newRoot);
        return newRoot;
    }

    
    WAVLNode* rotateLeft(WAVLNode* node) {
        WAVLNode* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateRank(node);
        updateRank(newRoot);
        return newRoot;
    }

    
    void updateRank(WAVLNode* node) {
        int leftRank = (node->left == nullptr) ? -1 : node->left->rank;
        int rightRank = (node->right == nullptr) ? -1 : node->right->rank;
        node->rank = 1 + max(leftRank, rightRank);
    }

    
    WAVLNode* balanceInsert(WAVLNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        updateRank(node);

        int leftRank = (node->left == nullptr) ? -1 : node->left->rank;
        int rightRank = (node->right == nullptr) ? -1 : node->right->rank;

        
        if (leftRank > rightRank + 1) {
            int leftChildLeftRank = (node->left->left == nullptr) ? -1 : node->left->left->rank;
            int leftChildRightRank = (node->left->right == nullptr) ? -1 : node->left->right->rank;

            
            if (leftChildLeftRank >= leftChildRightRank) {
                
                return rotateRight(node);
            } else {
                
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        
        if (rightRank > leftRank + 1) {
            int rightChildLeftRank = (node->right->left == nullptr) ? -1 : node->right->left->rank;
            int rightChildRightRank = (node->right->right == nullptr) ? -1 : node->right->right->rank;

            
            if (rightChildRightRank >= rightChildLeftRank) {
                
                return rotateLeft(node);
            } else {
                
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    
    WAVLNode* insert(WAVLNode* node, int key, int value) {
        if (node == nullptr) {
            return new WAVLNode(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            
            node->value = value;
            return node;
        }

        return balanceInsert(node);
    }

    
    void inOrderTraversal(WAVLNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << "(" << node->key << ", " << node->value << ", " << node->rank << ") ";
            inOrderTraversal(node->right);
        }
    }

public:
    WAVLTree() : root(nullptr) {}

    
    void insert(int key, int value) {
        root = insert(root, key, value);
    }

    
    void printTree() {
        cout << "WAVL Tree (In-order Traversal): ";
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    WAVLTree wavlTree;

    
    wavlTree.insert(5, 50);
    wavlTree.insert(3, 30);
    wavlTree.insert(7, 70);
    wavlTree.insert(2, 20);
    wavlTree.insert(4, 40);
    wavlTree.insert(6, 60);
    wavlTree.insert(8, 80);

    
    wavlTree.printTree();

    return 0;
}

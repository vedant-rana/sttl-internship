#include <iostream>

using namespace std;

template <typename T>
class SplayTree {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;

        Node(const T& val) : key(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    
    void leftRotate(Node*& x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        x = y;
    }

    void rightRotate(Node*& x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        x = y;
    }

    
    void splay(Node*& root, const T& key) {
        if (!root || root->key == key) {
            return;
        }

        if (key < root->key) {
            if (!root->left) {
                return;  
            }

            if (key < root->left->key) {
                splay(root->left->left, key);
                rightRotate(root);
            } else if (key > root->left->key) {
                splay(root->left->right, key);
                if (root->left->right) leftRotate(root->left);
            }

            if (root->left) rightRotate(root);
        } else if (key > root->key) {
            if (!root->right) {
                return;  
            }

            if (key < root->right->key) {
                splay(root->right->left, key);
                if (root->right->left) rightRotate(root->right);
            } else if (key > root->right->key) {
                splay(root->right->right, key);
                leftRotate(root);
            }

            if (root->right) leftRotate(root);
        }
    }

    
    void insert(Node*& root, const T& key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        splay(root, key);

        if (key < root->key) {
            Node* newNode = new Node(key);
            newNode->left = root->left;
            newNode->right = root;
            root->left = nullptr;
            root = newNode;
        } else if (key > root->key) {
            Node* newNode = new Node(key);
            newNode->right = root->right;
            newNode->left = root;
            root->right = nullptr;
            root = newNode;
        }
    }

    
    void remove(Node*& root, const T& key) {
        if (!root) {
            return; 
        }

        splay(root, key);

        if (key == root->key) {
            Node* temp = root;
            if (!root->left) {
                root = root->right;
            } else {
                Node* newRoot = root->left;
                splay(newRoot, key);
                newRoot->right = root->right;
                root = newRoot;
            }
            delete temp;
        }
    }

    
    bool search(Node* root, const T& key) const {
        if (!root) {
            return false;
        }

        splay(root, key);
        return root->key == key;
    }

public:
    SplayTree() : root(nullptr) {}

    
    void insert(const T& key) {
        insert(root, key);
    }

    
    void remove(const T& key) {
        remove(root, key);
    }

    
    bool search(const T& key) const {
        return search(root, key);
    }
};

int main() {
    SplayTree<int> splayTree;

    splayTree.insert(5);
    splayTree.insert(3);
    splayTree.insert(7);
    splayTree.insert(2);
    splayTree.insert(4);

    cout << "Is 3 in the tree? " << (splayTree.search(3) ? "Yes" : "No") << endl;
    cout << "Is 6 in the tree? " << (splayTree.search(6) ? "Yes" : "No") << endl;

    splayTree.remove(3);

    cout << "Is 3 in the tree after removal? " << (splayTree.search(3) ? "Yes" : "No") << endl;

    return 0;
}

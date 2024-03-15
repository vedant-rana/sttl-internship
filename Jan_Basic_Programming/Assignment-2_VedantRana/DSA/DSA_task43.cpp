#include <iostream>

using namespace std;


struct SplayNode {
    int key;
    SplayNode* left, *right, *parent;

    SplayNode(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {}
};

class SplayTree {
private:
    SplayNode* root;

    void leftRotate(SplayNode* x) {
        SplayNode* y = x->right;
        x->right = y->left;

        if (y->left != nullptr) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(SplayNode* y) {
        SplayNode* x = y->left;
        y->left = x->right;

        if (x->right != nullptr) {
            x->right->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

    void splay(SplayNode* x) {
        while (x->parent != nullptr) {
            if (x->parent->parent == nullptr) {
                if (x == x->parent->left) {
                    rightRotate(x->parent);
                } else {
                    leftRotate(x->parent);
                }
            } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
                rightRotate(x->parent->parent);
                rightRotate(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
                leftRotate(x->parent->parent);
                leftRotate(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
                leftRotate(x->parent);
                rightRotate(x->parent);
            } else {
                rightRotate(x->parent);
                leftRotate(x->parent);
            }
        }
    }

    SplayNode* findNode(int key) {
        SplayNode* current = root;
        while (current != nullptr) {
            if (key < current->key) {
                if (current->left == nullptr) {
                    break;
                }
                current = current->left;
            } else if (key > current->key) {
                if (current->right == nullptr) {
                    break;
                }
                current = current->right;
            } else {
                break;
            }
        }
        splay(current);
        return current;
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(int key) {
        if (root == nullptr) {
            root = new SplayNode(key);
            return;
        }

        SplayNode* current = root;
        SplayNode* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                
                splay(current);
                return;
            }
        }

        SplayNode* newNode = new SplayNode(key);
        newNode->parent = parent;

        if (key < parent->key) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        splay(newNode);
    }

    void remove(int key) {
        SplayNode* node = findNode(key);
        if (node == nullptr || node->key != key) {
            cout << "Key not found." << endl;
            return;
        }

        SplayNode* leftSubtree = node->left;
        SplayNode* rightSubtree = node->right;

        if (leftSubtree != nullptr) {
            leftSubtree->parent = nullptr;
        }

        if (rightSubtree != nullptr) {
            rightSubtree->parent = nullptr;
        }

        delete node;

        if (leftSubtree != nullptr && rightSubtree != nullptr) {
            root = rightSubtree;
            SplayNode* maxNode = findNode(INT_MAX); 
            maxNode->left = leftSubtree;
            leftSubtree->parent = maxNode;
        } else if (leftSubtree != nullptr) {
            root = leftSubtree;
        } else if (rightSubtree != nullptr) {
            root = rightSubtree;
        } else {
            root = nullptr;
        }
    }

    void search(int key) {
        SplayNode* result = findNode(key);
        if (result == nullptr || result->key != key) {
            cout << "Key not found." << endl;
            return;
        }

        cout << "Key " << key << " found." << endl;
    }

    void inOrderTraversal(SplayNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->key << " ";
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
    SplayTree splayTree;

    
    splayTree.insert(50);
    splayTree.insert(30);
    splayTree.insert(70);
    splayTree.insert(20);
    splayTree.insert(40);
    splayTree.insert(60);
    splayTree.insert(80);

    cout << "Initial Splay Tree:" << endl;
    splayTree.printTree();

    splayTree.remove(40);

    cout << "Splay Tree after removing 40:" << endl;
    splayTree.printTree();

    splayTree.search(30);

    return 0;
}

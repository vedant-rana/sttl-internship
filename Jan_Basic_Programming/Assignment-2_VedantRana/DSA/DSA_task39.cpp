#include <iostream>
#include <cstdlib>
#include <ctime>

class TreapNode {
public:
    int key, priority;
    TreapNode* left, *right;

    TreapNode(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

class Treap {
private:
    TreapNode* root;

    
    TreapNode* rightRotate(TreapNode* y) {
        TreapNode* x = y->left;
        y->left = x->right;
        x->right = y;
        return x;
    }

    
    TreapNode* leftRotate(TreapNode* x) {
        TreapNode* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    
    TreapNode* insertUtil(TreapNode* root, int key) {
        if (!root)
            return new TreapNode(key);

        
        if (key <= root->key) {
            root->left = insertUtil(root->left, key);

            
            if (root->left->priority > root->priority)
                root = rightRotate(root);
        } else {
            root->right = insertUtil(root->right, key);

            
            if (root->right->priority > root->priority)
                root = leftRotate(root);
        }

        return root;
    }

    
    bool searchUtil(TreapNode* root, int key) const {
        if (!root)
            return false;

        if (key == root->key)
            return true;

        if (key < root->key)
            return searchUtil(root->left, key);
        else
            return searchUtil(root->right, key);
    }

    
    void printUtil(TreapNode* root, int level) const {
        if (root) {
            printUtil(root->right, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "   ";
            std::cout << root->key << "(" << root->priority << ")\n";
            printUtil(root->left, level + 1);
        }
    }

public:
    Treap() : root(nullptr) {
        srand(time(0));
    }

    
    void insert(int key) {
        root = insertUtil(root, key);
    }

    
    bool search(int key) const {
        return searchUtil(root, key);
    }

    
    void print() const {
        printUtil(root, 0);
        std::cout << "-------------------------------\n";
    }
};

int main() {
    Treap treap;

    
    treap.insert(4);
    treap.insert(2);
    treap.insert(6);
    treap.insert(1);
    treap.insert(3);
    treap.insert(5);
    treap.insert(7);

    
    treap.print();

    
    std::cout << "Search for 5: " << (treap.search(5) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 8: " << (treap.search(8) ? "Found" : "Not found") << std::endl;

    return 0;
}

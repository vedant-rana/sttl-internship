#include<bits/stdc++.h>

using namespace std;

const int t = 2;

struct Node {
    vector<int> keys;
    vector<Node*> children;
    bool isLeaf;

    Node(bool leaf = true) : isLeaf(leaf) {}
};

class BTree {
    Node* root;

public:
    BTree() : root(nullptr) {}

    void rangeQuery(Node* x, int low, int high) {
        int i = 0;
        while (i < x->keys.size() && low > x->keys[i]) {
            i++;
        }

        if (i < x->keys.size()) {
            while (i < x->keys.size() && x->keys[i] <= high) {
                cout << x->keys[i] << " ";
                i++;
            }
        }

        if (!x->isLeaf) {
            for (int j = 0; j < x->children.size(); j++) {
                rangeQuery(x->children[j], low, high);
            }
        }
    }

    void rangeQuery(int low, int high) {
        rangeQuery(root, low, high);
    }

    void insert(int key) {
        if (root == nullptr) {
            root = new Node();
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == (2 * t - 1)) {
                Node* newRoot = new Node(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0);
                root = newRoot;
            }
            insertNonFull(root, key);
        }
    }

private:
    void splitChild(Node* x, int i) {
        Node* y = x->children[i];
        Node* z = new Node(y->isLeaf);
        x->children.insert(x->children.begin() + i + 1, z);

        x->keys.insert(x->keys.begin() + i, y->keys[t - 1]);

        z->keys.assign(y->keys.begin() + t, y->keys.end());
        y->keys.erase(y->keys.begin() + t - 1, y->keys.end());

        if (!y->isLeaf) {
            z->children.assign(y->children.begin() + t, y->children.end());
            y->children.erase(y->children.begin() + t, y->children.end());
        }
    }

    void insertNonFull(Node* x, int key) {
        int i = x->keys.size() - 1;

        if (x->isLeaf) {
            while (i >= 0 && key < x->keys[i]) {
                i--;
            }
            x->keys.insert(x->keys.begin() + i + 1, key);
        } else {
            while (i >= 0 && key < x->keys[i]) {
                i--;
            }
            i++;
            if (x->children[i]->keys.size() == (2 * t - 1)) {
                splitChild(x, i);
                if (key > x->keys[i]) {
                    i++;
                }
            }
            insertNonFull(x->children[i], key);
        }
    }
};

int main() {
    BTree bTree;

    bTree.insert(3);
    bTree.insert(8);
    bTree.insert(12);
    bTree.insert(16);
    bTree.insert(20);
    bTree.insert(25);
    bTree.insert(10);
    bTree.insert(2);
    bTree.insert(14);

    cout << "Range Query (10, 20): ";
    bTree.rangeQuery(10, 20);
    cout << endl;

    return 0;
}

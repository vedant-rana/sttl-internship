#include <iostream>
#include <vector>

using namespace std;

struct EulerTourTreeNode {
    int key;
    EulerTourTreeNode* left, *right, *parent;

    EulerTourTreeNode(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {}
};

class EulerTourTree {
private:
    vector<EulerTourTreeNode*> nodes;

    
    void makeRoot(EulerTourTreeNode* node) {
        access(node);
        splay(node);
    }

    
    void access(EulerTourTreeNode* node) {
        EulerTourTreeNode* v = node;
        EulerTourTreeNode* last = nullptr;

        while (v != nullptr) {
            splay(v);
            v->right = last;
            last = v;
            v = v->parent;
        }

        splay(node);
    }

    
    void splay(EulerTourTreeNode* node) {
        while (node->parent != nullptr) {
            EulerTourTreeNode* parent = node->parent;
            EulerTourTreeNode* grandparent = parent->parent;

            if (grandparent == nullptr) {
                
                if (parent->left == node) {
                    rotateRight(node);
                } else {
                    rotateLeft(node);
                }
            } else {
                if ((grandparent->left == parent && parent->left == node) ||
                    (grandparent->right == parent && parent->right == node)) {
                    
                    if (parent->left == node) {
                        rotateRight(parent);
                        rotateRight(node);
                    } else {
                        rotateLeft(parent);
                        rotateLeft(node);
                    }
                } else {
                    
                    if (parent->left == node) {
                        rotateRight(node);
                        rotateLeft(node);
                    } else {
                        rotateLeft(node);
                        rotateRight(node);
                    }
                }
            }
        }
    }

    
    void rotateLeft(EulerTourTreeNode* node) {
        EulerTourTreeNode* parent = node->parent;
        EulerTourTreeNode* grandparent = parent->parent;

        parent->right = node->left;
        if (node->left != nullptr) {
            node->left->parent = parent;
        }

        node->left = parent;
        parent->parent = node;

        if (grandparent != nullptr) {
            if (grandparent->left == parent) {
                grandparent->left = node;
            } else {
                grandparent->right = node;
            }
        }

        node->parent = grandparent;
    }

    
    void rotateRight(EulerTourTreeNode* node) {
        EulerTourTreeNode* parent = node->parent;
        EulerTourTreeNode* grandparent = parent->parent;

        parent->left = node->right;
        if (node->right != nullptr) {
            node->right->parent = parent;
        }

        node->right = parent;
        parent->parent = node;

        if (grandparent != nullptr) {
            if (grandparent->left == parent) {
                grandparent->left = node;
            } else {
                grandparent->right = node;
            }
        }

        node->parent = grandparent;
    }

public:
    EulerTourTree(int n) {
        nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = new EulerTourTreeNode(i);
        }
    }

    
    void link(int u, int v) {
        makeRoot(nodes[u]);
        nodes[u]->parent = nodes[v];
    }

    
    void cut(int u, int v) {
        makeRoot(nodes[u]);
        access(nodes[v]);
        splay(nodes[v]);
        nodes[v]->left->parent = nullptr;
        nodes[v]->left = nullptr;
    }

    
    bool isConnected(int u, int v) {
        makeRoot(nodes[u]);
        access(nodes[v]);
        splay(nodes[v]);
        return nodes[v]->left != nullptr;
    }
};

int main() {
    EulerTourTree eulerTourTree(6);

    
    eulerTourTree.link(0, 1);
    eulerTourTree.link(1, 2);
    eulerTourTree.link(2, 3);
    eulerTourTree.link(3, 4);
    eulerTourTree.link(4, 5);

    
    cout << "Is 0 connected to 5? " << (eulerTourTree.isConnected(0, 5) ? "Yes" : "No") << endl;
    cout << "Is 2 connected to 4? " << (eulerTourTree.isConnected(2, 4) ? "Yes" : "No") << endl;

    
    eulerTourTree.cut(1, 2);
    eulerTourTree.cut(3, 4);

    
    cout << "Is 0 connected to 5 now? " << (eulerTourTree.isConnected(0, 5) ? "Yes" : "No") << endl;
    cout << "Is 2 connected to 4 now? " << (eulerTourTree.isConnected(2, 4) ? "Yes" : "No") << endl;

    return 0;
}

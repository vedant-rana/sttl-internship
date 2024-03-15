#include <iostream>
#include <algorithm>

using namespace std;

enum Color { RED, BLACK };

struct RBNode {
    int data;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    RBNode* root;

    void leftRotate(RBNode* x) {
        RBNode* y = x->right;
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

    void rightRotate(RBNode* y) {
        RBNode* x = y->left;
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

    void fixInsert(RBNode* z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                RBNode* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                RBNode* y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(RBNode* u, RBNode* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

    RBNode* minimum(RBNode* x) {
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

    void fixDelete(RBNode* x) {
        while (x != root && (x == nullptr || x->color == BLACK)) {
            if (x == x->parent->left) {
                RBNode* w = x->parent->right;
                if (w != nullptr && w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if ((w->left == nullptr || w->left->color == BLACK) &&
                    (w->right == nullptr || w->right->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right == nullptr || w->right->color == BLACK) {
                        if (w->left != nullptr) {
                            w->left->color = BLACK;
                        }
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->right != nullptr) {
                        w->right->color = BLACK;
                    }
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                RBNode* w = x->parent->left;
                if (w != nullptr && w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if ((w->right == nullptr || w->right->color == BLACK) &&
                    (w->left == nullptr || w->left->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left == nullptr || w->left->color == BLACK) {
                        if (w->right != nullptr) {
                            w->right->color = BLACK;
                        }
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->left != nullptr) {
                        w->left->color = BLACK;
                    }
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        if (x != nullptr) {
            x->color = BLACK;
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int data) {
        RBNode* z = new RBNode(data);
        RBNode* y = nullptr;
        RBNode* x = root;

        while (x != nullptr) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z;
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }

        fixInsert(z);
    }

    void remove(int data) {
        RBNode* z = root;
        while (z != nullptr) {
            if (data < z->data) {
                z = z->left;
            } else if (data > z->data) {
                z = z->right;
            } else {
                break;
            }
        }

        if (z == nullptr) {
            cout << "Node with value " << data << " not found." << endl;
            return;
        }

        RBNode* y = z;
        Color yOriginalColor = y->color;
        RBNode* x;

        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;

        if (yOriginalColor == BLACK) {
            fixDelete(x);
        }
    }

    void inOrderTraversal(RBNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << "(" << node->data << ", " << (node->color == RED ? "RED" : "BLACK") << ") ";
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
    
    RedBlackTree redBlackTree;

    redBlackTree.insert(10);
    redBlackTree.insert(20);
    redBlackTree.insert(30);
    redBlackTree.insert(40);
    redBlackTree.insert(50);

    cout << "Initial Red-Black Tree:" << endl;
    redBlackTree.printTree();

    redBlackTree.remove(30);

    cout << "Red-Black Tree after deleting 30:" << endl;
    redBlackTree.printTree();

    return 0;
}

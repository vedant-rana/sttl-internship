#include<bits/stdc++.h>

using namespace std;

struct Node {
    int key, value;
    Node *left, *right, *parent;
    bool isRoot;
    Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr), parent(nullptr), isRoot(true) {}
};

class LinkCutTree {
public:
    LinkCutTree(int n) : nodes(n, nullptr) {}

    void link(int u, int v) {
        makeRoot(u);
        nodes[u]->parent = nodes[v];
    }

    void cut(int u) {
        access(u);
        nodes[u]->left->parent = nullptr;
        nodes[u]->left = nullptr;
    }

    int query(int u) {
        access(u);
        return nodes[u]->value;
    }

    void update(int u, int newValue) {
        access(u);
        nodes[u]->value = newValue;
    }

private:
    vector<Node*> nodes;

    void makeRoot(int u) {
        access(u);
        splay(u);
        nodes[u]->left = nullptr;
        nodes[u]->isRoot = true;
    }

    void access(int u) {
        splay(u);
        if (nodes[u]->right) {
            nodes[u]->right->isRoot = true;
            nodes[u]->right->parent = nullptr;
            nodes[u]->right = nullptr;
        }
        while (nodes[u]->parent) {
            int w = nodes[u]->parent->key;
            splay(w);
            nodes[w]->right = nodes[u];
            nodes[w]->isRoot = false;
            nodes[u]->parent = nullptr;
            u = w;
        }
    }

    void splay(int u) {
        while (!nodes[u]->isRoot) {
            int p = nodes[u]->parent->key;
            int g = nodes[p]->parent ? nodes[p]->parent->key : 0;
            if (!nodes[p]->isRoot) {
                if ((nodes[p]->left && u == nodes[p]->left->key) ^ (nodes[g]->left && p == nodes[g]->left->key))
                    rotate(u);
                else
                    rotate(p);
            }
            rotate(u);
        }
    }

    void rotate(int u) {
        Node *p = nodes[u]->parent;
        Node *g = p->parent;
        if (p->left && u == p->left->key) {
            p->left = nodes[u]->right;
            if (nodes[u]->right) nodes[u]->right->parent = p;
            nodes[u]->right = p;
        } else {
            p->right = nodes[u]->left;
            if (nodes[u]->left) nodes[u]->left->parent = p;
            nodes[u]->left = p;
        }
        p->parent = nodes[u];
        nodes[u]->parent = g;
        if (!g) nodes[u]->isRoot = true;
        else if (g->left && p == g->left) g->left = nodes[u];
        else g->right = nodes[u];
    }
};

int main() {
    int n = 6; // Number of nodes
    LinkCutTree lct(n);

    // Sample operations
    lct.link(1, 2);
    lct.link(3, 4);
    lct.link(2, 5);
    lct.link(4, 6);

    lct.update(5, 10);

    cout << "Query result for node 6: " << lct.query(6) << endl;

    lct.cut(5);

    cout << "Query result for node 6 after cut operation: " << lct.query(6) << endl;

    return 0;
}

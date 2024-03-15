#include <iostream>
#include <vector>

class LinkCutTreeNode {
public:
    int value;
    int subtreeSum;
    LinkCutTreeNode* parent;
    LinkCutTreeNode* left;
    LinkCutTreeNode* right;

    LinkCutTreeNode(int val) : value(val), subtreeSum(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

class LinkCutTree {
private:
    std::vector<LinkCutTreeNode*> nodes;

    void updateSubtreeSum(LinkCutTreeNode* node) {
        node->subtreeSum = node->value +
            (node->left ? node->left->subtreeSum : 0) +
            (node->right ? node->right->subtreeSum : 0);
    }

    void rotateRight(LinkCutTreeNode* node) {
        LinkCutTreeNode* parent = node->parent;
        LinkCutTreeNode* grandparent = parent->parent;

        if (grandparent) {
            if (grandparent->left == parent) {
                grandparent->left = node;
            } else {
                grandparent->right = node;
            }
        }

        parent->left = node->right;
        if (node->right) {
            node->right->parent = parent;
        }

        node->right = parent;
        parent->parent = node;

        updateSubtreeSum(parent);
        updateSubtreeSum(node);
    }

    void rotateLeft(LinkCutTreeNode* node) {
        LinkCutTreeNode* parent = node->parent;
        LinkCutTreeNode* grandparent = parent->parent;

        if (grandparent) {
            if (grandparent->left == parent) {
                grandparent->left = node;
            } else {
                grandparent->right = node;
            }
        }

        parent->right = node->left;
        if (node->left) {
            node->left->parent = parent;
        }

        node->left = parent;
        parent->parent = node;

        updateSubtreeSum(parent);
        updateSubtreeSum(node);
    }

    void splay(LinkCutTreeNode* node) {
        while (node->parent) {
            LinkCutTreeNode* parent = node->parent;
            LinkCutTreeNode* grandparent = parent->parent;

            if (!grandparent) {
                if (parent->left == node) {
                    rotateRight(node);
                } else {
                    rotateLeft(node);
                }
            } else {
                if (grandparent->left == parent) {
                    if (parent->left == node) {
                        rotateRight(parent);
                        rotateRight(node);
                    } else {
                        rotateLeft(node);
                        rotateRight(node);
                    }
                } else {
                    if (parent->right == node) {
                        rotateLeft(parent);
                        rotateLeft(node);
                    } else {
                        rotateRight(node);
                        rotateLeft(node);
                    }
                }
            }
        }
    }

public:
    LinkCutTree(int size) : nodes(size, nullptr) {
        for (int i = 0; i < size; ++i) {
            nodes[i] = new LinkCutTreeNode(i + 1);
        }
    }

    void link(int u, int v) {
        access(nodes[u]);
        access(nodes[v]);
        nodes[u]->parent = nodes[v];
    }

    void cut(int u) {
        access(nodes[u]);
        nodes[u]->left->parent = nullptr;
        nodes[u]->left = nullptr;
    }

    int pathSum(int u, int v) {
        access(nodes[u]);
        access(nodes[v]);
        return nodes[u]->subtreeSum;
    }

    void access(LinkCutTreeNode* node) {
        splay(node);
        if (node->right) {
            node->right->parent = nullptr;
            node->right = nullptr;
            updateSubtreeSum(node);
        }
        while (node->parent) {
            LinkCutTreeNode* parent = node->parent;
            splay(parent);
            parent->right = node;
            updateSubtreeSum(parent);
            node->parent = nullptr;
            node = parent;
        }
    }
};

int main() {
    LinkCutTree linkCutTree(6);

    linkCutTree.link(1, 2);
    linkCutTree.link(2, 3);
    linkCutTree.link(4, 5);
    linkCutTree.link(5, 6);

    std::cout << "Path sum from 3 to 5: " << linkCutTree.pathSum(3, 5) << std::endl;

    linkCutTree.cut(4);

    std::cout << "Path sum from 3 to 5 after cutting 4: " << linkCutTree.pathSum(3, 5) << std::endl;

    return 0;
}

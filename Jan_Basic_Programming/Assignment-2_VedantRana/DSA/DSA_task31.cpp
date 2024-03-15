#include <iostream>
#include <vector>

class PersistentSegmentTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    std::vector<Node*> versions;

public:
    PersistentSegmentTree() {
        versions.push_back(new Node(0));
    }

    int query(Node* node, int start, int end, int left, int right) {
        if (!node || left > end || right < start)
            return 0;

        if (left <= start && right >= end)
            return node->value;

        int mid = (start + end) / 2;
        int leftSum = query(node->left, start, mid, left, right);
        int rightSum = query(node->right, mid + 1, end, left, right);

        return leftSum + rightSum;
    }

    Node* update(Node* node, int start, int end, int index, int val) {
        if (!node)
            node = new Node(0);

        if (start == end) {
            Node* newNode = new Node(node->value + val);
            return newNode;
        }

        int mid = (start + end) / 2;
        if (index <= mid)
            node->left = update(node->left, start, mid, index, val);
        else
            node->right = update(node->right, mid + 1, end, index, val);

        Node* newNode = new Node(node->left->value + node->right->value);
        newNode->left = node->left;
        newNode->right = node->right;

        return newNode;
    }

    void update(int version, int index, int val) {
        versions.push_back(update(versions[version], 0, versions[0]->value - 1, index, val));
    }

    int query(int version, int left, int right) {
        return query(versions[version], 0, versions[0]->value - 1, left, right);
    }
};

int main() {
    PersistentSegmentTree pst;

    pst.update(0, 0, 5);
    pst.update(1, 2, 3);
    pst.update(2, 4, 2);

    std::cout << "Version 0: " << pst.query(0, 0, 4) << std::endl;
    std::cout << "Version 1: " << pst.query(1, 0, 4) << std::endl;
    std::cout << "Version 2: " << pst.query(2, 0, 4) << std::endl;

    return 0;
}

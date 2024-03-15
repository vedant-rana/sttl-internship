#include <iostream>
#include <vector>

class CartesianTree {
private:
    struct Node {
        int key;
        int priority;
        Node* left;
        Node* right;

        Node(int k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* build(int start, int end, const std::vector<int>& keys, const std::vector<int>& priorities) {
        if (start > end) {
            return nullptr;
        }

        int maxIndex = start;
        for (int i = start + 1; i <= end; ++i) {
            if (priorities[i] > priorities[maxIndex]) {
                maxIndex = i;
            }
        }

        Node* node = new Node(keys[maxIndex], priorities[maxIndex]);
        node->left = build(start, maxIndex - 1, keys, priorities);
        node->right = build(maxIndex + 1, end, keys, priorities);

        return node;
    }

    int query(Node* node, int key) const {
        if (node == nullptr) {
            return 0;
        }

        if (key < node->key) {
            return query(node->left, key);
        } else {
            return 1 + query(node->right, key);
        }
    }

public:
    CartesianTree() : root(nullptr) {}

    void buildTree(const std::vector<int>& keys, const std::vector<int>& priorities) {
        root = build(0, keys.size() - 1, keys, priorities);
    }

    int countSmaller(int key) const {
        return query(root, key);
    }
};

int main() {
    std::vector<int> keys = {3, 1, 4, 2};
    std::vector<int> priorities = {10, 5, 8, 15};

    CartesianTree ct;
    ct.buildTree(keys, priorities);

    std::cout << "Count of elements smaller than 3: " << ct.countSmaller(3) << std::endl;
    std::cout << "Count of elements smaller than 2: " << ct.countSmaller(2) << std::endl;

    return 0;
}

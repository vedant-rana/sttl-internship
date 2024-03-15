#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct CartesianTreeNode {
    int value;
    int index;
    CartesianTreeNode* left;
    CartesianTreeNode* right;

    CartesianTreeNode(int val, int idx) : value(val), index(idx), left(nullptr), right(nullptr) {}
};

class RMQCartesianTree {
public:
    RMQCartesianTree(const vector<int>& arr) : array(arr), root(nullptr) {
        buildCartesianTree();
    }

    int rangeMinimumQuery(int left, int right) {
        CartesianTreeNode* lca = findLCA(root, left, right);
        return min(findMinIndex(lca->left, left), findMinIndex(lca->right, right));
    }

private:
    vector<int> array;
    CartesianTreeNode* root;

    CartesianTreeNode* buildCartesianTree() {
        stack<CartesianTreeNode*> st;

        for (int i = 0; i < array.size(); ++i) {
            CartesianTreeNode* current = new CartesianTreeNode(array[i], i);

            while (!st.empty() && st.top()->value > current->value) {
                st.pop();
            }

            if (!st.empty()) {
                current->left = st.top()->right;
                st.top()->right = current;
            } else {
                current->left = root;
                root = current;
            }

            st.push(current);
        }

        return root;
    }

    CartesianTreeNode* findLCA(CartesianTreeNode* root, int left, int right) {
        if (!root || (root->index >= left && root->index <= right)) {
            return root;
        }

        if (root->index > right) {
            return findLCA(root->left, left, right);
        }

        return findLCA(root->right, left, right);
    }

    int findMinIndex(CartesianTreeNode* root, int index) {
        int minIndex = INT_MAX;

        while (root) {
            if (root->index >= index) {
                minIndex = min(minIndex, root->index);
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return minIndex;
    }
};

int main() {
    // Example usage:
    vector<int> arr = {5, 2, 3, 7, 1, 8, 6};
    RMQCartesianTree rmqTree(arr);

    cout << "Minimum in range [2, 5]: " << arr[rmqTree.rangeMinimumQuery(2, 5)] << endl;
    cout << "Minimum in range [1, 6]: " << arr[rmqTree.rangeMinimumQuery(1, 6)] << endl;

    return 0;
}

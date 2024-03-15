#include <iostream>
#include <stack>
#include <vector>

using namespace std;


struct CartesianNode {
    int key;
    CartesianNode* left, *right;

    CartesianNode(int key) : key(key), left(nullptr), right(nullptr) {}
};

class CartesianTree {
private:
    CartesianNode* root;

public:
    CartesianTree() : root(nullptr) {}

    CartesianNode* constructTree(const vector<int>& arr) {
        stack<CartesianNode*> st;

        for (int i = 0; i < arr.size(); ++i) {
            CartesianNode* node = new CartesianNode(arr[i]);

            while (!st.empty() && st.top()->key > arr[i]) {
                node->left = st.top();
                st.pop();
            }

            if (!st.empty()) {
                st.top()->right = node;
            } else {
                root = node;
            }

            st.push(node);
        }

        return root;
    }

    void inOrderTraversal(CartesianNode* node) {
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
    CartesianTree cartesianTree;

    
    vector<int> arr = {3, 5, 10, 7, 15};
    CartesianNode* root = cartesianTree.constructTree(arr);

    cout << "Cartesian Tree:" << endl;
    cartesianTree.printTree();

    return 0;
}

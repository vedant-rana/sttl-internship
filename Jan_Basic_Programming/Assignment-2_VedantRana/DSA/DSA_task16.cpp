#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    vector<int> point;
    Node* left;
    Node* right;
};

Node* newNode(vector<int> point) {
    Node* temp = new Node;
    temp->point = point;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insertRec(Node* root, vector<int> point, size_t depth) {
    if (root == nullptr) {
        return newNode(point);
    }

    size_t cd = depth % point.size();

    if (point[cd] < (root->point[cd])) {
        root->left = insertRec(root->left, point, depth + 1);
    } else {
        root->right = insertRec(root->right, point, depth + 1);
    }

    return root;
}

Node* insert(Node* root, vector<int> point) {
    return insertRec(root, point, 0);
}

int findMinRec(Node* root, size_t d, size_t depth) {
    if (root == nullptr) {
        return INT_MAX;
    }

    size_t cd = depth % d;

    if (cd == d - 1) {
        return min(root->point[cd], min(findMinRec(root->left, d, depth + 1), findMinRec(root->right, d, depth + 1)));
    }

    return min(findMinRec(root->left, d, depth + 1), findMinRec(root->right, d, depth + 1));
}

int findMin(Node* root, size_t d) {
    return findMinRec(root, d, 0);
}

int main() {
    Node* root = nullptr;
    vector<vector<int>> points = {{2, 3}, {5, 4}, {9, 6}, {4, 7}, {8, 1}};

    for (const auto& point : points) {
        root = insert(root, point);
    }

    size_t dimensions = points[0].size();
    int minVal = findMin(root, dimensions);

    cout << "Minimum value in the K Dimensional Tree: " << minVal << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    vector<int> coordinates;

    Point(const vector<int>& coords) : coordinates(coords) {}
};

struct Node {
    Point point;
    Node* left;
    Node* right;

    Node(const Point& p) : point(p), left(nullptr), right(nullptr) {}
};

class KDTree {
public:
    KDTree() : root(nullptr) {}

    void insert(const Point& point) {
        root = insertRecursive(root, point, 0);
    }

    bool search(const Point& target) {
        return searchRecursive(root, target, 0);
    }

private:
    Node* root;

    Node* insertRecursive(Node* node, const Point& point, int depth) {
        if (node == nullptr) {
            return new Node(point);
        }

        int currentDimension = depth % point.coordinates.size();

        if (point.coordinates[currentDimension] < node->point.coordinates[currentDimension]) {
            node->left = insertRecursive(node->left, point, depth + 1);
        } else {
            node->right = insertRecursive(node->right, point, depth + 1);
        }

        return node;
    }

    bool searchRecursive(Node* node, const Point& target, int depth) {
        if (node == nullptr) {
            return false;
        }

        if (node->point.coordinates == target.coordinates) {
            return true;
        }

        int currentDimension = depth % target.coordinates.size();

        if (target.coordinates[currentDimension] < node->point.coordinates[currentDimension]) {
            return searchRecursive(node->left, target, depth + 1);
        } else {
            return searchRecursive(node->right, target, depth + 1);
        }
    }
};

int main() {
    KDTree kdTree;

    
    kdTree.insert(Point({3, 6}));
    kdTree.insert(Point({1, 2}));
    kdTree.insert(Point({4, 7}));
    kdTree.insert(Point({5, 9}));

    
    Point searchPoint({4, 7});
    cout << "Is point " << searchPoint.coordinates[0] << ", " << searchPoint.coordinates[1]
         << " in the KD-Tree? " << (kdTree.search(searchPoint) ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct KDNode {
    vector<int> point;
    KDNode* left, *right;

    KDNode(const vector<int>& point) : point(point), left(nullptr), right(nullptr) {}
};

class KDTree {
private:
    KDNode* root;

    KDNode* buildTree(vector<vector<int>>& points, int depth) {
        if (points.empty()) {
            return nullptr;
        }

        int k = points[0].size();
        int axis = depth % k;

        sort(points.begin(), points.end(), [axis](const vector<int>& a, const vector<int>& b) {
            return a[axis] < b[axis];
        });

        int medianIndex = points.size() / 2;
        KDNode* node = new KDNode(points[medianIndex]);

        vector<vector<int>> leftPoints(points.begin(), points.begin() + medianIndex);
        vector<vector<int>> rightPoints(points.begin() + medianIndex + 1, points.end());

        node->left = buildTree(leftPoints, depth + 1);
        node->right = buildTree(rightPoints, depth + 1);

        return node;
    }

    bool searchNode(KDNode* node, const vector<int>& target, int depth) {
        if (node == nullptr) {
            return false;
        }

        int k = target.size();
        int axis = depth % k;

        if (node->point == target) {
            return true;
        }

        if (target[axis] < node->point[axis]) {
            return searchNode(node->left, target, depth + 1);
        } else {
            return searchNode(node->right, target, depth + 1);
        }
    }

public:
    KDTree(vector<vector<int>>& points) : root(nullptr) {
        root = buildTree(points, 0);
    }

    bool search(const vector<int>& target) {
        return searchNode(root, target, 0);
    }
};

int main() {
    
    vector<vector<int>> points = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19}};
    KDTree kdTree(points);

    
    vector<int> target = {6, 12};
    bool found = kdTree.search(target);

    if (found) {
        cout << "Point " << "(" << target[0] << ", " << target[1] << ") found in the K-D tree." << endl;
    } else {
        cout << "Point " << "(" << target[0] << ", " << target[1] << ") not found in the K-D tree." << endl;
    }

    return 0;
}

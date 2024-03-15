#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int low, high;

    Interval(int l, int h) : low(l), high(h) {}
};

struct IntervalNode {
    Interval interval;
    int maxEndpoint;
    IntervalNode* left;
    IntervalNode* right;

    IntervalNode(const Interval& i) : interval(i), maxEndpoint(i.high), left(nullptr), right(nullptr) {}
};

class IntervalTree {
private:
    IntervalNode* root;

    void updateMaxEndpoint(IntervalNode* node) {
        node->maxEndpoint = max(node->interval.high, max(getMaxEndpoint(node->left), getMaxEndpoint(node->right)));
    }

    int getMaxEndpoint(IntervalNode* node) const {
        return (node == nullptr) ? -1 : node->maxEndpoint;
    }

    IntervalNode* leftRotate(IntervalNode* y) {
        IntervalNode* x = y->right;
        y->right = x->left;
        x->left = y;

        updateMaxEndpoint(y);
        updateMaxEndpoint(x);

        return x;
    }

    IntervalNode* rightRotate(IntervalNode* x) {
        IntervalNode* y = x->left;
        x->left = y->right;
        y->right = x;

        updateMaxEndpoint(x);
        updateMaxEndpoint(y);

        return y;
    }

    IntervalNode* balance(IntervalNode* node) {
        updateMaxEndpoint(node);

        if (getHeight(node->left) > getHeight(node->right) + 1) {
            if (getHeight(node->left->right) > getHeight(node->left->left)) {
                node->left = leftRotate(node->left);
            }
            node = rightRotate(node);
        } else if (getHeight(node->right) > getHeight(node->left) + 1) {
            if (getHeight(node->right->left) > getHeight(node->right->right)) {
                node->right = rightRotate(node->right);
            }
            node = leftRotate(node);
        }

        return node;
    }

    IntervalNode* insert(IntervalNode* node, const Interval& interval) {
        if (node == nullptr) {
            return new IntervalNode(interval);
        }

        if (interval.low < node->interval.low) {
            node->left = insert(node->left, interval);
        } else {
            node->right = insert(node->right, interval);
        }

        return balance(node);
    }

    IntervalNode* remove(IntervalNode* node, const Interval& interval) {
        if (node == nullptr) {
            return nullptr;
        }

        if (interval.low < node->interval.low) {
            node->left = remove(node->left, interval);
        } else if (interval.low > node->interval.low || interval.high > node->interval.high) {
            node->right = remove(node->right, interval);
        } else {
            if (node->left == nullptr) {
                IntervalNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                IntervalNode* temp = node->left;
                delete node;
                return temp;
            }

            IntervalNode* successor = findMin(node->right);
            node->interval = successor->interval;
            node->right = remove(node->right, successor->interval);
        }

        return balance(node);
    }

    IntervalNode* findMin(IntervalNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void search(IntervalNode* node, const Interval& interval, vector<Interval>& result) const {
        if (node == nullptr) {
            return;
        }

        if (doIntervalsOverlap(node->interval, interval)) {
            result.push_back(node->interval);
        }

        if (node->left != nullptr && interval.low <= getMaxEndpoint(node->left)) {
            search(node->left, interval, result);
        }

        if (node->right != nullptr && interval.low <= getMaxEndpoint(node->right)) {
            search(node->right, interval, result);
        }
    }

    bool doIntervalsOverlap(const Interval& a, const Interval& b) const {
        return !(a.high < b.low || b.high < a.low);
    }

    int getHeight(IntervalNode* node) const {
        return (node == nullptr) ? 0 : 1 + max(getHeight(node->left), getHeight(node->right));
    }

public:
    IntervalTree() : root(nullptr) {}

    void insert(const Interval& interval) {
        root = insert(root, interval);
    }

    void remove(const Interval& interval) {
        root = remove(root, interval);
    }

    vector<Interval> search(const Interval& interval) const {
        vector<Interval> result;
        search(root, interval, result);
        return result;
    }
};

int main() {
    IntervalTree intervalTree;

    intervalTree.insert({15, 20});
    intervalTree.insert({10, 30});
    intervalTree.insert({5, 12});
    intervalTree.insert({25, 30});
    intervalTree.insert({17, 19});
    intervalTree.insert({8, 11});

    Interval searchInterval = {14, 16};
    vector<Interval> overlappingIntervals = intervalTree.search(searchInterval);

    cout << "Intervals overlapping with [" << searchInterval.low << ", " << searchInterval.high << "]:\n";
    for (const Interval& interval : overlappingIntervals) {
        cout << "[" << interval.low << ", " << interval.high << "]\n";
    }

    Interval removeInterval = {10, 30};
    intervalTree.remove(removeInterval);

    return 0;
}

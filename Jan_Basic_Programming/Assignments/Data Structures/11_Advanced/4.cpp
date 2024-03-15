#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& arr) : arrSize(arr.size()), tree(4 * arr.size(), 0) {
        buildTree(arr, 0, 0, arrSize - 1);
    }

    int query(int queryStart, int queryEnd) {
        return queryHelper(0, 0, arrSize - 1, queryStart, queryEnd);
    }

    void update(int index, int newValue) {
        updateHelper(0, 0, arrSize - 1, index, newValue);
    }

private:
    int arrSize;
    vector<int> tree;

    void buildTree(const vector<int>& arr, int treeIndex, int start, int end) {
        if (start == end) {
            tree[treeIndex] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        buildTree(arr, leftChild, start, mid);
        buildTree(arr, rightChild, mid + 1, end);

        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }

    int queryHelper(int treeIndex, int start, int end, int queryStart, int queryEnd) {
        if (queryStart > end || queryEnd < start) {
            return 0; 
        }

        if (queryStart <= start && queryEnd >= end) {
            return tree[treeIndex]; 
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        int leftSum = queryHelper(leftChild, start, mid, queryStart, queryEnd);
        int rightSum = queryHelper(rightChild, mid + 1, end, queryStart, queryEnd);

        return leftSum + rightSum;
    }

    void updateHelper(int treeIndex, int start, int end, int index, int newValue) {
        if (start == end) {
            tree[treeIndex] = newValue;
            return;
        }

        int mid = start + (end - start) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        if (index <= mid) {
            updateHelper(leftChild, start, mid, index, newValue);
        } else {
            updateHelper(rightChild, mid + 1, end, index, newValue);
        }

        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segmentTree(arr);

    cout << "Sum in range [1, 4]: " << segmentTree.query(1, 4) << "\n";

    segmentTree.update(2, 6);

    cout << "Sum in updated range [1, 4]: " << segmentTree.query(1, 4) << "\n";

    return 0;
}

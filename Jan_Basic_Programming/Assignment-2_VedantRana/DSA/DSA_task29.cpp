#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(arr, 0, n - 1, 1);
    }

    void build(const vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(arr, start, mid, 2 * node);
        build(arr, mid + 1, end, 2 * node + 1);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int index, int val) {
        update(0, n - 1, 1, index, val);
    }

    void update(int start, int end, int node, int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid)
            update(start, mid, 2 * node, index, val);
        else
            update(mid + 1, end, 2 * node + 1, index, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void rangeUpdate(int left, int right, int val) {
        rangeUpdate(0, n - 1, 1, left, right, val);
    }

    void rangeUpdate(int start, int end, int node, int left, int right, int val) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > end || start > right || end < left)
            return;

        if (start >= left && end <= right) {
            tree[node] += (end - start + 1) * val;

            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }

            return;
        }

        int mid = (start + end) / 2;
        rangeUpdate(start, mid, 2 * node, left, right, val);
        rangeUpdate(mid + 1, end, 2 * node + 1, left, right, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }

    int query(int start, int end, int node, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > end || start > right || end < left)
            return 0;

        if (start >= left && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        int leftSum = query(start, mid, 2 * node, left, right);
        int rightSum = query(mid + 1, end, 2 * node + 1, left, right);

        return leftSum + rightSum;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    SegmentTree st(arr);

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    cout << "Sum in range [1, 4]: " << st.query(1, 4) << endl;

    st.update(2, 8);
    cout << "Array after updating index 2 to 8: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << st.query(i, i) << " ";
    cout << endl;

    st.rangeUpdate(1, 4, 2);
    cout << "Array after adding 2 to elements in range [1, 4]: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << st.query(i, i) << " ";
    cout << endl;

    return 0;
}

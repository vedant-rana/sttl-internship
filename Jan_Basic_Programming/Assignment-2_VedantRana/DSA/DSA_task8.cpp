#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> lazy;
    string input;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = input[start] - 'A' + 1;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > right || end < left) {
            return;
        }

        if (start >= left && end <= right) {
            tree[node] += (end - start + 1);

            if (start != end) {
                lazy[2 * node]++;
                lazy[2 * node + 1]++;
            }

            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, left, right);
        update(2 * node + 1, mid + 1, end, left, right);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > right || end < left) {
            return 0;
        }

        if (start >= left && end <= right) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftSum = query(2 * node, start, mid, left, right);
        int rightSum = query(2 * node + 1, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

public:
    SegmentTree(const string& s) : input(s) {
        int n = s.length();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(1, 0, n - 1);
    }

    void modify(int left, int right) {
        update(1, 0, input.length() - 1, left, right);
    }

    int query(int left, int right) {
        return query(1, 0, input.length() - 1, left, right);
    }
};

int main() {
    
    string s1 = "AABBBCCCC";
    vector<vector<int>> queries1 = {{1, 0}, {2, 1}, {1, 0}, {2, 2}, {1, 3}};
    SegmentTree st1(s1);

    for (const auto& query : queries1) {
        int type = query[0];
        int param = query[1];

        if (type == 1) {
            st1.modify(param, param);
        } else if (type == 2) {
            int result = st1.query(param, s1.length() - 1);
            cout << "Result: " << result << endl;
        }
    }

    string s2 = "XXYYY";
    vector<vector<int>> queries2 = {{1, 3}, {2, 3}, {1, 2}};
    SegmentTree st2(s2);

    for (const auto& query : queries2) {
        int type = query[0];
        int param = query[1];

        if (type == 1) {
            st2.modify(param, param);
        } else if (type == 2) {
            int result = st2.query(param, s2.length() - 1);
            cout << "Result: " << result << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree, lazy;
    int n;

    void propagate(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node] * (end - start + 1);

            if (start != end)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

public:
    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void updateRange(int startIndex, int endIndex, int value)
    {
        updateRange(0, 0, n - 1, startIndex, endIndex, value);
    }

    void updateRange(int node, int start, int end, int startIndex, int endIndex, int value)
    {
        propagate(node, start, end);

        if (start > endIndex || end < startIndex)
        {
            return;
        }

        if (startIndex <= start && endIndex >= end)
        {
            tree[node] += value * (end - start + 1);

            if (start != end)
            {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }

            return;
        }


        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, startIndex, endIndex, value);
        updateRange(2 * node + 2, mid + 1, end, startIndex, endIndex, value);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    int query(int queryStart, int queryEnd)
    {
        return query(0, 0, n - 1, queryStart, queryEnd);
    }

    int query(int node, int start, int end, int queryStart, int queryEnd)
    {
        propagate(node, start, end);


        if (start > queryEnd || end < queryStart)
        {
            return 0;
        }


        if (queryStart <= start && queryEnd >= end)
        {
            return tree[node];
        }

        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, queryStart, queryEnd) +
               query(2 * node + 2, mid + 1, end, queryStart, queryEnd);
    }
};

int main()
{
    int n = 5;
    SegmentTree segmentTree(n);

    segmentTree.updateRange(1, 3, 2); 
    segmentTree.updateRange(2, 4, 1); 

    cout << "Query in range [1, 3]: " << segmentTree.query(1, 3) << endl; 

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree
{
public:
    SegmentTree(const std::vector<int> &arr) : n(arr.size())
    {
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int query(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }

private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = std::min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int left, int right)
    {
        if (start > right || end < left)
        {
            return INT_MAX;
        }
        if (start >= left && end <= right)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = query(2 * node, start, mid, left, right);
        int rightMin = query(2 * node + 1, mid + 1, end, left, right);
        return std::min(leftMin, rightMin);
    }
};

int main()
{

    std::vector<int> arr = {1, 3, 2, 7, 9, 11};

    SegmentTree rmq(arr);

    int result = rmq.query(1, 4);

    std::cout << "Minimum element in the range [1, 4]: " << result << std::endl;

    return 0;
}

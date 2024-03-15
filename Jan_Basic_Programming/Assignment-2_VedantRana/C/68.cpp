#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 1)
    {

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {

            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {

            if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool areConnected(int x, int y)
    {
        return find(x) == find(y);
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main()
{

    int n = 6;

    UnionFind uf(n);

    uf.unionSets(0, 1);
    uf.unionSets(1, 2);
    uf.unionSets(3, 4);
    uf.unionSets(4, 5);

    cout << "Are 0 and 2 connected? " << (uf.areConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 1 and 3 connected? " << (uf.areConnected(1, 3) ? "Yes" : "No") << endl;

    return 0;
}

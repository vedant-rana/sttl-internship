#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class UnionFind {
public:
    vector<int> parent, size;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) {
                swap(rootA, rootB);
            }

            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};


pair<int, int> findComponentDifference(const vector<pair<int, int>>& queries, int numNodes) {
    UnionFind uf(numNodes);
    int smallestComponentSize = numNodes;
    int largestComponentSize = 1;

    pair<int, int> result;

    for (const auto& query : queries) {
        int u = query.first;
        int v = query.second;

        uf.unionSets(u, v);

        int componentSize = uf.getSize(u);

        smallestComponentSize = min(smallestComponentSize, componentSize);
        largestComponentSize = max(largestComponentSize, componentSize);

        result = make_pair(smallestComponentSize, largestComponentSize);
    }

    return result;
}

int main() {
    int numNodes = 6;
    vector<pair<int, int>> queries = {{0, 1}, {1, 2}, {3, 4}, {4, 5}};

    pair<int, int> result = findComponentDifference(queries, numNodes);

    cout << "Smallest Component Size: " << result.first << endl;
    cout << "Largest Component Size: " << result.second << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    DSU(int n, const vector<int>& weights) : parent(n + 1), rank(n + 1), weight(weights) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            int originalParent = parent[x];
            parent[x] = find(parent[x]); 
            weight[x] += weight[originalParent]; 
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return; 
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            weight[rootX] = weight[y] - weight[x];
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            weight[rootY] = weight[x] - weight[y];
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
            weight[rootX] = weight[y] - weight[x];
        }
    }

    int getWeightDifference(int x, int y) {
        return weight[y] - weight[x];
    }

private:
    vector<int> parent;
    vector<int> rank;
    vector<int> weight;
};

int main() {
    int n1 = 7;
    vector<int> weights1 = {1, 2, 6, 4, 2, 0, 3};
    vector<pair<int, int>> edges1 = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {4, 6}, {6, 7}};

    int n2 = 6;
    vector<int> weights2 = {2, 4, 0, 2, 2, 6};
    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 6}};

    DSU dsu1(n1, weights1);
    DSU dsu2(n2, weights2);

    
    for (const auto& edge : edges1) {
        dsu1.unionSets(edge.first, edge.second);
    }

    for (const auto& edge : edges2) {
        dsu2.unionSets(edge.first, edge.second);
    }

    
    int query1 = 4;
    int query2 = 5;

    int root1 = dsu1.find(query1);
    int root2 = dsu1.find(query2);

    cout << "Weight difference between nodes " << query1 << " and " << query2 << " in tree 1: "
         << dsu1.getWeightDifference(root1, root2) << endl;

    int root3 = dsu2.find(query1);
    int root4 = dsu2.find(query2);

    cout << "Weight difference between nodes " << query1 << " and " << query2 << " in tree 2: "
         << dsu2.getWeightDifference(root3, root4) << endl;

    return 0;
}

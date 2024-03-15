#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 1) {
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

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<int> minDifferenceAfterQuery(int N, int Q, const vector<vector<int>>& queries) {
    vector<int> result;
    UnionFind uf(N);

    for (const auto& query : queries) {
        int type = query[0];
        int u = query[1];

        if (type == 1) {
            int v = query[2];
            uf.unionSets(u - 1, v - 1);
        } else if (type == 2) {
            int component1 = uf.find(u - 1);
            int component2 = uf.find(u);
            result.push_back(abs(component1 - component2));
        }
    }

    return result;
}

int main() {
    
    int N1 = 2, Q1 = 1;
    vector<vector<int>> queries1 = {{1, 1, 2}};
    vector<int> result1 = minDifferenceAfterQuery(N1, Q1, queries1);

    cout << "Minimum difference after each query for N = 2, Q = 1: ";
    for (int diff : result1) {
        cout << diff << " ";
    }
    cout << endl;

    int N2 = 4, Q2 = 2;
    vector<vector<int>> queries2 = {{1, 1, 2}, {2, 4}};
    vector<int> result2 = minDifferenceAfterQuery(N2, Q2, queries2);

    cout << "Minimum difference after each query for N = 4, Q = 2: ";
    for (int diff : result2) {
        cout << diff << " ";
    }
    cout << endl;

    return 0;
}

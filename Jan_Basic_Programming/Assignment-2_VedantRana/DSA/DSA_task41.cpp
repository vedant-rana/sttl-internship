#include <iostream>
#include <vector>

using namespace std;

class WeightedUnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    WeightedUnionFind(int n) : parent(n), rank(n, 0) {
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
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }

            parent[rootY] = rootX;

            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

int main() {
    
    WeightedUnionFind uf(5);

    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(0, 4);

    cout << "Are 1 and 4 connected? " << (uf.find(1) == uf.find(4) ? "Yes" : "No") << endl;

    return 0;
}

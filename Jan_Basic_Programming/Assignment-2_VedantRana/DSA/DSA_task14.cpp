#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int n = 5; 
    UnionFind uf(n);

    
    uf.unionSets(0, 1);
    uf.unionSets(2, 3);
    uf.unionSets(0, 4);

    
    cout << "Are 1 and 4 in the same set? " << (uf.find(1) == uf.find(4) ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        
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

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            
            return false;
        }

        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }

        return true;
    }
};

int main() {
    
    int n = 10; 

    UnionFind uf(n);

    
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(5, 6);

    
    cout << "Are 1 and 2 connected? " << (uf.find(1) == uf.find(2) ? "Yes" : "No") << endl;
    cout << "Are 1 and 5 connected? " << (uf.find(1) == uf.find(5) ? "Yes" : "No") << endl;

    

    return 0;
}
